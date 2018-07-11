#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
#include "common.h"

#define QUEUE_CAPACITY 100				// problem, since it is fixed. taking a big number that is large enough for the problem domain may be ok for today

typedef struct
{
	int eles[QUEUE_CAPACITY];

	int front;							// index of eles
	int rear;							// index of eles

	int invalid_ele;    // Example: = -1       or  = -999;    a value that pop returns when empty    cllient can decide
} queue;

void queue_init(queue *pq, const int invalid_ele);

void queue_push(queue *pq, const int ele);	// at rear		// NOTE: prefixing with filename to eliminate naming conflits
int  queue_pop(queue *pq);					// at front
int  queue_rear(const queue *pq);			// get rear
int  queue_front(const queue *pq);			// get front
bool queue_empty(const queue *pq);			// is empty
int  queue_size(const queue *pq);			// get size

#endif // QUEUE_H_INCLUDED
