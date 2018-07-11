#include "linkedlist.h"

node* _ll_create_new_node(ele)
{
    node *new_node = (node*)malloc(sizeof(node));

    new_node->data = ele;
    new_node->next = NULL;

    return new_node;
}

node* ll_create_linked_list(node *start, int arr[], int len)
{
    if (len == 0)
        return NULL;

    int i = 0;
    node *temp = NULL;
    if (start == NULL)
    {
        temp = start = _ll_create_new_node(arr[i++]);
    }

    for (; i < len; i++)
    {
        temp->next = _ll_create_new_node(arr[i]);
        temp = temp->next;
    }

    return start;
}

void ll_traverse(node *start)
{
    node *ptemp = start;

    while (ptemp)
    {
        printf("%c  ", ptemp->data);
        ptemp = ptemp->next;
    }

    printf("\n");
}

node* ll_insert_at_begin(node *start, unsigned int ele)
{
    node *new_node = _ll_create_new_node(ele);

    new_node->next = start;
    start = new_node;

    return start;
}

node* ll_insert_at_pos(node *start, unsigned int ele, const int at_position)	// at_position could be another node as position here
{
    if (start == NULL)
    {
        printf("Linked List is null\n");
        return start;
    }
    if (at_position <= 0)
    {
        printf("Position should be > 0\n");
        return start;
    }

    node *ptemp = start;
    int pos;
    for (pos = 1; pos < at_position - 1; pos++)
    {
        ptemp = ptemp->next;
        if (ptemp == NULL)
            break;
    }

    if (pos != at_position - 1)
    {
        printf("Position could not be found within linked list\n");
        return start;
    }

    node *new_node = (node*)malloc(sizeof(node));
    new_node->data = ele;

    new_node->next = ptemp->next;
    ptemp->next = new_node;

    return start;
}

node* ll_insert_after_node(node *pafter_node, unsigned int ele)
{
    // NOTE: pafter_node could be a single or linked list, caller responsibility
    if (pafter_node)
    {
        node *new_node = (node*)malloc(sizeof(node));
        new_node->data = ele;

        new_node->next = pafter_node->next;
        pafter_node->next = new_node;

        return new_node;
    }
    else
    {
        printf("Position does not exist\n");
    }

    return pafter_node;
}

node* unused_ll_insert_after_value(node *start, unsigned int ele, unsigned int after_ele)
{
    node *ptemp = start;

    while ((ptemp != NULL) && (ptemp->data != after_ele))
    {
        ptemp = ptemp->next;
    }

    if (ptemp->data == after_ele)
    {
        node *new_node = (node*)malloc(sizeof(node));
        new_node->data = ele;
        new_node->next = ptemp->next;
        ptemp->next = new_node;
    }
    else
    {
        printf("Position does not exist\n");
    }

    return start;
}

bool ll_delete_node(node *delete_node)
{
    printf("%c is being deleted.. ", delete_node->data);
    free(delete_node);
    printf("done\n");
    delete_node = NULL;

    return true;
}

node* ll_delete_begin(node *start)
{
    node *ptemp = start;
    start = start->next;

    ll_delete_node(ptemp);

    return start;
}

node* ll_delete_at_pos(node *start, int at_position)
{
    if (at_position == 1)
        return ll_delete_begin(start);

    node *ptemp = start;
    int pos;
    for (pos = 1; pos < at_position - 1; pos++)
    {
        ptemp = ptemp->next;
        if (ptemp == NULL)
            break;
    }
    if (ptemp->next == NULL)
    {
        printf("Position does not exist in linked list\n");
        return start;
    }

    node *temp = ptemp->next;
    ptemp->next = ptemp->next->next;

    ll_delete_node(temp);

    return start;
}
