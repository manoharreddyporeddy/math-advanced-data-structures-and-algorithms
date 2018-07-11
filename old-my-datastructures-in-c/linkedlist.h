#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED
#include "common.h"

typedef struct node node;

struct node
{
	unsigned int data;
	node *next;
};

node* _ll_create_new_node(ele);
node* ll_create_linked_list(node *start, int arr[], int len);
void  ll_traverse(node *start);

node* ll_insert_at_begin(node *start, unsigned int ele);
node* ll_insert_at_pos(node *start, unsigned int ele, const int at_position);
node* ll_insert_after_node(node *pafter_node, unsigned int ele);
node* unused_ll_insert_after_value(node *start, unsigned int ele, unsigned int after_ele);

node* ll_delete_begin(node *start);
node* ll_delete_at_pos(node *start, int at_position);

#endif // LINKEDLIST_H_INCLUDED
