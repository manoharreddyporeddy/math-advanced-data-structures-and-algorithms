#include "binarytree.h"

// FIXME: hack to reuse in BST, only for printf format
char *bintree_format = "%1c ";
char *bintree_format_char = "%1c ";
char *bintree_format_int = "%3d ";

bintree_node* _create_bintree_node(const int ele)
{
    bintree_node *new_node = (bintree_node *)malloc(sizeof(bintree_node));
    new_node->data = ele;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

bintree_node* bintree_build_from_in_order_and_pre_order_arrays(int in_order_arr[], int pre_order_arr[], int in_order_begin_index, int in_order_end_index)
{
    bintree_format = bintree_format_char;	// FIXME: hack to reuse in BST, only for printf format

    if (in_order_begin_index > in_order_end_index)
        return NULL;

    static int pre_order_index = 0;
    int pre_order_data = pre_order_arr[pre_order_index++];

    bintree_node *new_node = _create_bintree_node(pre_order_data);
    // printf(bintree_format, new_node->data);

    for (int ii = in_order_begin_index; ii <= in_order_end_index; ii++)
    {
        if (in_order_arr[ii] == pre_order_data)
        {
            new_node->left = bintree_build_from_in_order_and_pre_order_arrays(in_order_arr, pre_order_arr, in_order_begin_index, ii - 1);
            new_node->right = bintree_build_from_in_order_and_pre_order_arrays(in_order_arr, pre_order_arr, ii + 1, in_order_end_index);
            break;
        }
    }

    return new_node;
}

bool bintree_empty(bintree_node *root)
{
    if (root == NULL)
        return true;

    return false;
}

void bintree_traverse_in_order(bintree_node *root)
{
    if (root != NULL)
    {
        bintree_traverse_in_order(root->left);
        printf(bintree_format, root->data);
        bintree_traverse_in_order(root->right);
    }
}

void bintree_traverse_pre_order(bintree_node *root)
{
    if (root != NULL)
    {
        printf(bintree_format, root->data);
        bintree_traverse_pre_order(root->left);
        bintree_traverse_pre_order(root->right);
    }
}

void bintree_traverse_post_order(bintree_node *root)
{
    if (root != NULL)
    {
        bintree_traverse_post_order(root->left);
        bintree_traverse_post_order(root->right);
        printf(bintree_format, root->data);
    }
}

void bintree_traverse_level_order(bintree_node *root)
{
    if (root == NULL)
    {
        return;
    }

    llqueue llq1;
    initialise_llqueue(&llq1);

    llqueue_push(&llq1, (unsigned int)root);
    llqueue_push(&llq1, (unsigned int)99999);       // dummy statement for printing purposes only

    bintree_node *ptemp = NULL;
    while (!llqueue_empty(&llq1))
    {
        ptemp = (bintree_node *)llqueue_pop(&llq1);
        if ((unsigned int)ptemp == 99999) // dummy statement for printing purposes only
        {
            printf("\t");
        }
        else
        {
            printf(bintree_format, ptemp->data);

            if (ptemp->left)
            {
                llqueue_push(&llq1, (unsigned int)ptemp->left);
            }
            if (ptemp->right)
            {
                llqueue_push(&llq1, (unsigned int)ptemp->right);
                llqueue_push(&llq1, (unsigned int)99999);       // dummy statement for printing purposes only
            }
        }
    }
}

void bintree_deleteall(bintree_node **root)
{
    if (*root != NULL)
    {
        bintree_deleteall(&(*root)->left);
        bintree_deleteall(&(*root)->right);

        free(*root);
        (*root) = NULL;
    }
}

// pre-order find
bintree_node* bintree_find(bintree_node *root, bintree_node **parent, const int ele)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == ele)
    {
        return root;
    }

    if (root->left)
    {
        bintree_node *left_node = bintree_find(root->left, &root, ele);
        if (left_node)
        {
            *parent = root;
            return left_node;
        }
    }
    if (root->right)
    {
        bintree_node *right_node = bintree_find(root->right, &root, ele);
        if (right_node)
        {
            *parent = root;
            return right_node;
        }
    }

    return NULL;
}

void bintree_delete(bintree_node *root, const int ele)
{
    bintree_node *parent = NULL;
    bintree_node *foundnode = bintree_find(root, &parent, ele);
    if (foundnode == NULL)
    {
        printf("node with %d not found\n", ele);
        return;
    }

    // node found

    // both left and right of node found, are null
    if (((foundnode)->left == NULL) && ((foundnode)->right == NULL))
    {
        // adjust parent's link to this found node to null
        (parent->left == foundnode) ? (parent->left = NULL) : (parent->right = NULL);

        // delete found node
        free(foundnode);
        foundnode = NULL;
    }
    // one of the left or right of node found, is null
    else if (((foundnode)->left == NULL) || ((foundnode)->right == NULL))
    {
        // adjust parent's link to this found node  to  found node's non-null child
        bintree_node *foundnodechild = ((foundnode)->left != NULL ? (foundnode)->left : (foundnode)->right); // get the non-null child
        (parent->left == foundnode) ? (parent->left = foundnodechild) : (parent->right = foundnodechild);

        // delete found node
        free(foundnode);
        foundnode = NULL;
    }
    // both left and right of node found, are   not null
    else
    {
        // delete will be unambiguous in binary tree
        //	many ways to choose a delete, replace the contents of node found, with any leaf (possibly right-most leaf of its children)
        //	leaving it to deal with it in binary search trees (BST)
    }
}

void bintree_insert(bintree_node *root, const int ele, bool to_left, int of_parent_ele, bool retain_parents_children_side)
{
    bintree_node *parent = NULL;
    bintree_node *foundnode = bintree_find(root, &parent, of_parent_ele);
    if (foundnode == NULL)
    {
        printf("node with %d not found\n", of_parent_ele);
        return;
    }

    // node found
    bintree_node *new_node = _create_bintree_node(ele);
    if (to_left == true)
    {
        // retain the link type (left/right) of foundnode to its child - to help balancing(?)
        if (retain_parents_children_side == true)
        {
            new_node->left = foundnode->left;
        }
        else
        {
            new_node->right = foundnode->left;
        }
        foundnode->left = new_node;
    }
    else
    {
        // retain the link type (left/right) of foundnode to its child - to help balancing(?)
        if (retain_parents_children_side == true)
        {
            new_node->left = foundnode->right;
        }
        else
        {
            new_node->right = foundnode->right;
        }
        foundnode->right = new_node;
    }
}
