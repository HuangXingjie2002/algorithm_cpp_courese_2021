#include <iostream>
#include "../wheel/lib/stack_list.h"

int main()
{
    stack_list<char> *stack = new stack_list<char>;
    stack->push('A');
    stack->push('B');
    stack->push('C');
    stack->push('D');

    while (!stack->isEmpty())
    {
        std::cout << stack->pop() << std::endl;
    }
}