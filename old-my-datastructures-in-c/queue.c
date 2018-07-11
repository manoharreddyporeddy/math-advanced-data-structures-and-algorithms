#include "queue.h"

#define QUEUE_IS_EMPTY      (pq->rear + 1 == pq->front)
#define QUEUE_IS_NOT_EMPTY  (!QUEUE_IS_EMPTY)
#define QUEUE_SIZE          (pq->rear - pq->front + 1)
#define QUEUE_IS_FULL       (QUEUE_SIZE == QUEUE_CAPACITY)

void queue_init(queue *pq, const int invalid_ele)
{
	pq->rear = -1;					// index of eles
    pq->front = 0;					// index of eles

	pq->invalid_ele = invalid_ele;
}

int queue_size(const queue *pq)
{
	return QUEUE_SIZE;
}

bool queue_empty(const queue *pq)
{
	if (QUEUE_IS_EMPTY) {
		printf("queue empty. ");
		return true;
	}

	return false;
}

bool queue_full(const queue *pq)
{
    if (QUEUE_IS_FULL) {
        printf("queue full. \n");
        return true;
    }

    return false;
}

int queue_rear(const queue *pq)
{
    if (queue_empty(pq)) {
        return pq->invalid_ele;
	}

	return pq->eles[pq->rear];
}

int queue_front(const queue *pq)
{
    if (queue_empty(pq)) {
        return pq->invalid_ele;
	}

	return pq->eles[pq->front];
}

void queue_push(queue *pq, const int ele)
{
    if (queue_full(pq)) {
		return;
	}

	pq->rear++;
    pq->eles[pq->rear] = ele;
}

int queue_pop(queue *pq)
{
    if (queue_empty(pq)) {
		return pq->invalid_ele;
	}

	int ele = pq->eles[pq->front];
	pq->front++;
    return ele;
}
