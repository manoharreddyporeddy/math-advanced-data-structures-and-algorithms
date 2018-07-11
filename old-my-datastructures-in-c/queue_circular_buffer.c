#include "queue_circular_buffer.h"

#define CB_SIZE_NO_WRAP (pcb->rear - pcb->front + 1)
#define CB_SIZE         ((pcb->rear_wrapped == false)? CB_SIZE_NO_WRAP:  CB_CAPACITY - CB_SIZE_NO_WRAP)
#define CB_IS_EMPTY     (CB_SIZE == 0)
#define CB_IS_NOT_EMPTY (!CB_IS_EMPTY)
#define CB_IS_FULL      (CB_SIZE == CB_CAPACITY)

void cb_init(circular_buffer *pcb, const int invalid_ele)
{
	pcb->rear = -1;					// index of eles
    pcb->front = 0;					// index of eles

	pcb->rear_wrapped = false;

	pcb->invalid_ele = invalid_ele;
}

int cb_size(const circular_buffer *pcb)
{
    return CB_SIZE;
}

bool cb_empty(const circular_buffer *pcb)
{
    if (CB_IS_EMPTY) {
        printf("cb empty. ");
        return true;
    }

    return false;
}

int cb_rear(const circular_buffer *pcb)
{
    if (cb_empty(pcb)) {
        return pcb->invalid_ele;
	}

	return pcb->eles[pcb->rear];
}

int cb_front(const circular_buffer *pcb)
{
    if (cb_empty(pcb)) {
        return pcb->invalid_ele;
	}

	return pcb->eles[pcb->front];
}

void cb_push(circular_buffer *pcb, const int ele)
{
    if (CB_IS_FULL) {
        printf("cb full. ");
        return;
    }

    pcb->rear++;
    if (pcb->rear == CB_CAPACITY)
    {
        pcb->rear = 0;
        pcb->rear_wrapped = true; // rear pointer rear_wrapped from end to begin
    }

    pcb->eles[pcb->rear] = ele;
}

int cb_pop(circular_buffer *pcb)
{
    if (cb_empty(pcb)) {
        return pcb->invalid_ele;
    }

    int ele = pcb->eles[pcb->front];
    pcb->front++;
    if (pcb->front == CB_CAPACITY)
    {
        pcb->front = 0;
        if (pcb->rear == CB_CAPACITY - 1)
        {
            pcb->rear = -1;
        }

        pcb->rear_wrapped = false;
    }

    return ele;
}
