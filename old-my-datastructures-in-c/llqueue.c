#include "llqueue.h"

void initialise_llqueue(llqueue *llqueue1)
{
    llqueue1->front = llqueue1->rear = NULL;
}

bool llqueue_empty(const llqueue *llqueue1)		// is empty
{
    if (llqueue1->rear == NULL)
    {
        return true;
    }

    return false;
}

void llqueue_push(llqueue *llqueue1, unsigned int ele)	// at rear
{
	if (llqueue1->rear == NULL)
	{
		llqueue1->front =
            llqueue1->rear =
                ll_insert_at_begin(llqueue1->rear, ele);
        return;
	}

    llqueue1->rear = ll_insert_after_node(llqueue1->rear, ele);
}

unsigned int llqueue_pop(llqueue *llqueue1)					// at front
{
	unsigned int temp = (unsigned int)llqueue1->front->data;

	llqueue1->front = llqueue1->front->next;
	if (llqueue1->front == NULL)
	{
		llqueue1->rear = NULL;
	}

	return temp;
}

unsigned int llqueue_rear_data(const llqueue *llqueue1)			// get rear
{
	if (llqueue1->rear != NULL)
	{
		return llqueue1->rear->data;
	}
	else
	{
		return -1;	// FIXME: using -1 as error code
	}
}

unsigned int llqueue_front_data(const llqueue *llqueue1)			// get front
{
	if (llqueue1->front != NULL)
	{
		return llqueue1->front->data;
	}
	else
	{
		return -1;	// FIXME: using -1 as error code
	}
}
