### KMP算法详解

---

#### next数组
> next数组是一种求真前缀长度的方法， \
> 其核心是通过使用 `next[index]` 表示当前元素的前面所有元素组成的集合 \
> 的最大公共前缀的长度n，而这个最大公共前缀正好是 `array[0 ~ n-1]` \
> 以及紧挨着当前元素的`array[ index - n  ~ index - 1]`, \
> 这两个部分是完全相等的。为了判断`next[index+1]` \
> 可以直接判断array[next[index]] 是否等于 array[index], 如果相等 \
> 那么`next[index + 1] = next[index] + 1` \
> 如果不相等的话，由于继续判断 array[index] 是否等于 array[next[next[index]]] \
> 这是由于next数组表示的是相同的最大公共前缀，后缀。所以在前缀后缀里面的前缀后缀也是一样的 \
> 那么就只需要如果上述相等， 那么 `next[index + 1] = next[next[index]] + 1` \
> 如果不等，则继续反复。 \
> 那么终点在哪儿呢？一直next会到达0, 而next数组的第一位第二位定义为-1, 0,所以 \
> 终点就在`next[] = -1` 的时候终止

* 算法内部的变量设计 \
一个next数组，数组长度为字符串的长度
数组的第一个元素为-1
一个记录当前数组索引的变量i
一个记录当前匹配值 k
使用一个循环，当发现相等的时候，或者发现-1的时候，继续往后进行
否则，`k = next[k]`; 往后跳一位 
其中m的值，只有在成功通过的时候留下+1，而且可以作为下一轮的条件
下一轮中m可以理解为`next[index-1]`, 如果此时还是相等的，那么就可以直接+1
如果不相等，就需要把m减小。直到等于-1或者发现相等的。

```c++
    static int *find_next(std::string str) {
        unsigned long long length = str.length();
        int *next = new int[length]{0};
        // 获取字符串长度与创建next数组

        int index = 0;
        int m = -1;
        next[0] = -1;
        while (index < str.length() - 1) {
            if (m == -1 || str[index] == str[m]) {
                index++;
                m++;
                next[index] = m;
                // m 可以理解为上一层的next值，可以借助此变量直接推理下一层的next数组
            } else {
                m = next[m];
            }
        }
        return next;
    }
```

#### KMP算法

---
前面介绍的就基本上是KMP的精髓了，kmp就是为了简化匹配的重复度

现在把被匹配数组，和匹配数组同时列举出来，标记索引
如果此时发现在匹配数组的i位置上出现错误，那么就只需要往后从next[i]处重新开始匹配
如果一开始就不对，那么直接continue
如果被匹配数组的余下长度小于匹配数组，那么直接返回false，如果匹配数组的索引 == 长度 - 1
那么返回真。

```c++
static int kmp(const std::string &templateStr, const std::string &value) {
    int *next = find_next(value);
    int index = 0;
    for (int i = 0; i < templateStr.length() - value.length() + 1; i++) {
    if (value[index] != templateStr[i] && index == 0) {
        continue;
    } else if (value[index] != templateStr[i]) {
        index = next[index];
    } else {
        index ++;
    }
    if (index == value.length() - 1)
    {
        return true;
    }
    }
    return false;
}
```