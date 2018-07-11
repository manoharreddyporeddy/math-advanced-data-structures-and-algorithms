#ifndef CB_H_INCLUDED
#define CB_H_INCLUDED
#include "common.h"

#define CB_CAPACITY 3

typedef struct
{
	int eles[CB_CAPACITY];
	int front;							// index of eles
	int rear;							// index of eles

	bool rear_wrapped;

	int invalid_ele;				// Example: = -1       or  = -999;    a value that pop returns when empty    cllient can decide
} circular_buffer;

void cb_init(circular_buffer *pcb, const int invalid_ele);

bool cb_empty(const circular_buffer *pcb);			// is empty
int  cb_size(const circular_buffer *pcb);			// get size
int  cb_rear(const circular_buffer *pcb);			// get rear
int  cb_front(const circular_buffer *pcb);			// get front
void cb_push(circular_buffer *pcb, const int ele);	// at rear		// NOTE: prefixing with filename to eliminate naming conflits
int  cb_pop(circular_buffer *pcb);					// at front

#endif // CB_H_INCLUDED
