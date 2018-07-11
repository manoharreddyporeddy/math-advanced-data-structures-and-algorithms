#ifndef LLQUEUE_H_INCLUDED
#define LLQUEUE_H_INCLUDED
#include "common.h"
#include "linkedlist.h"

typedef struct llqueue llqueue;
struct llqueue
{
    node *front;
	node *rear;
};

void initialise_llqueue(llqueue *llqueue1);
void llqueue_push(llqueue *llqueue1, unsigned int ele);	// at rear		// NOTE: prefixing with filename to eliminate naming conflits
unsigned int llqueue_pop(llqueue *llqueue1);					// at front
unsigned int llqueue_rear_data(const llqueue *llqueue1);			// get rear
unsigned int llqueue_front_data(const llqueue *llqueue1);		// get front
bool llqueue_empty(const llqueue *llqueue1);		// is empty
// TO DO ?
int llqueue_size(const llqueue *llqueue1);			// get size

#endif // LLQUEUE_H_INCLUDED
