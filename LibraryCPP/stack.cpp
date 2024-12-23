#include "stack.h"
#include "list.h"
#include <iostream>

struct Stack {

    List* list;

};

Stack* stack_create()
{
    Stack* stack = new Stack;
    stack->list = list_create();
    return stack;
}

void stack_delete(Stack* stack)
{
    list_delete(stack->list);
    delete stack;
}

void stack_push(Stack* stack, Data data)
{
    list_insert(stack->list, data);
}

Data stack_get(const Stack* stack)
{
    if (list_first(stack->list) == nullptr) return (Data)0;
    return list_item_data(list_first(stack->list));
}

void stack_pop(Stack* stack)
{
    list_erase_first(stack->list);
}

bool stack_empty(const Stack* stack)
{
    return list_first(stack->list) == nullptr;
}

void stack_print(const Stack* stack) {
    ListItem* current = list_first(stack->list);
    while (current != nullptr) {
        std::cout << list_item_data(current) << " ";
        current = list_item_next(current);
    }
    std::cout << std::endl;
}