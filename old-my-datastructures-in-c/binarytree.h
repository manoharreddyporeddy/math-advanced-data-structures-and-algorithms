#ifndef BINARYREE_H_INCLUDED
#define BINARYREE_H_INCLUDED
#include "common.h"
#include "llqueue.h"

typedef struct bintree_node bintree_node;
struct bintree_node
{
    int data;
    bintree_node *left, *right;
};

// build tree
bintree_node* bintree_build_from_in_order_and_pre_order_arrays(int in_order_arr[], int pre_order_arr[], int in_order_begin_index, int in_order_end_index);

// check if empty
bool bintree_empty(bintree_node *root);

// depth first search traversal : in-order, pre-order, post-order
void bintree_traverse_in_order(bintree_node *root);
void bintree_traverse_pre_order(bintree_node *root);
void bintree_traverse_post_order(bintree_node *root);

// breadth first search traversal : level-order walk
void bintree_traverse_level_order(bintree_node *root);

// search
bintree_node* bintree_find(bintree_node *root, bintree_node **parent, const int ele);

// delete
void bintree_delete(bintree_node *root, const int ele);
void bintree_deleteall(bintree_node **root);

// insert
void bintree_insert(bintree_node *root, const int ele, bool to_left, int of_parent_ele, bool retain_parents_children_side);

#endif // BINARYREE_H_INCLUDED
