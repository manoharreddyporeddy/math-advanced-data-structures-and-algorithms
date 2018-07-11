#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED
#include "common.h"
#include "binarytree.h"

// Binary Search Tree (BST)

typedef struct bst_node bst_node;
struct bst_node
{
    int key;
    int data;
    bst_node *left, *right;
};

// build tree
bst_node* bst_create_from_array(int arr[], int len);

// insert
void bst_insert(bst_node *root, int ele);

// delete
void bst_delete(bst_node *root, int ele);

#endif // BST_H_INCLUDED
