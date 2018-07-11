#ifndef BINARYHEAP_H_INCLUDED
#define BINARYHEAP_H_INCLUDED
#include "common.h"
#include "binarytree.h"



typedef struct bh_node bh_node;
struct bh_node
{
    int key;
    int data;
    bh_node *left, *right;
};

// build tree
bh_node* binaryheap_create_from_array(int arr[], int len);

// insert
void binaryheap_insert(bh_node *root, int ele);

// delete
void binaryheap_delete(bh_node *root, int ele);

#endif // BINARYHEAP_H_INCLUDED
