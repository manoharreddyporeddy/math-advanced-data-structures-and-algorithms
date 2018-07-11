#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#include "common.h"

// fixed size is restriction, should take large enough for the problem domain, or go dynamic array
#define STACK_CAPACITY 100

typedef struct
{
	int eles[STACK_CAPACITY];
	int top;            // index of eles

	int invalid_ele;
} stack;

void stack_init(stack *ps, int invalid_ele);

void stack_push(stack *ps,  int ele);   // NOTE: prefixing with filename to eliminate naming conflits
int  stack_pop(stack *ps);
bool stack_empty(stack *ps);			// is empty

#endif // STACK_H_INCLUDED
