//
// Created by mushr on 2021/11/6.
//

#include "utility.h"


long stack_num(int n) {
    if (n == 1) {
        return 1l;
    }

    return (n - 1) * stack_num(n - 1) + 1l;
}