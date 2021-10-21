#include <iostream>
#include "../wheel/lib/stack_array.h"

int main()
{
    stack_array<char> *stack = new stack_array<char>(5);
    stack->push('A');
    stack->push('B');
    stack->push('C');
    stack->push('D');

    while (!stack->isEmpty())
    {
        std::cout << stack->pop() << std::endl;
    }
}