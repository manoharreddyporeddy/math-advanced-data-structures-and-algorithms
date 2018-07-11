#include "binaryheap.h"

// max heap
//  parent >= child
//  all level are same, filled from left to right

// min heap
//  parent <= child
//  all level are same, last level filled from left to right

// FIXME: hack to reuse in BST, only for printf format
extern char *bintree_format;
extern char *bintree_format_int;

bh_node* binaryheap_create_from_array(int arr[], int len)
{
    bintree_format = bintree_format_int;

    bh_node *start = NULL;
    if (len > 0)
    {
        bh_node *new_node = (bh_node *) malloc(sizeof(bh_node));
        new_node->data = new_node->key = arr[0];		// 1st ele	// FIXME: For now, data & key are same, so data cannot be unique
        new_node->left = NULL;
        new_node->right = NULL;

        start = new_node;

        for (int i = 1; i < len; i++)					// i from 1, for rest of eles
        {
            binaryheap_insert(start, arr[i]);
        }
    }

    return start;
}

void binaryheap_insert(bh_node *root, int ele)
{
    // implementing max-heap (parent >= child, and so root has highest key)

    bh_node *new_node = (bh_node *) malloc(sizeof(bh_node));
    new_node->data = new_node->key = ele;
    new_node->left = NULL;
    new_node->right = NULL;



    static bool to_left = true;      // ********* changed value, for this variable, is retained, between function calls



    bh_node *current = root;
    {
        if (new_node->key < current->key)  // new val is less the current node's left, so move the current node down, <= is not put to reduce up-heap?
        {
            if (to_left == true) // add to left
            {
                while (current->left)
                {
                    if ((new_node->key < current->left->key) && (current->right))
                        current = current->left; // while current left exists, go to it
                    else
                        break;
                }
                if (!(current->right))
                {
                    current->right = new_node;
                }
                else
                {
                    new_node->left = current->left;
                    current->left = new_node;
                }
            }
            else        // add to right
            {
                while (current->right)
                {
                    if ((new_node->key < current->right->key) && (current->left))
                        current = current->right; // while current left exists, go to it
                    else
                        break;
                }
                if (!(current->left))
                {
                    current->left = new_node;
                }
                else
                {
                    new_node->right = current->right;
                    current->right = new_node;
                }
            }
        }
        else if (new_node->key > current->key)
        {
            if (to_left == true) // add to left
            {
                new_node->left = current;
                root = new_node;
            }
            else
            {
                new_node->right = current;
                root = new_node;
            }
        }

        to_left = !to_left;   // next time insert to right/left

        // else
        // {
        //     printf("invalid, key shud be unique\n");	// TODO: == looks invalid, key shud be unique
        //     break;
        // }
    }
    // if (new_node->key < current->key)
    // {
    //     // new node shud be in left subtree
    //     current->left = new_node;
    // }
    // else if (new_node->key > current->key)
    // {
    //     // new node shud be in right subtree
    //     current->right = new_node;
    // }
}

void binaryheap_delete(bh_node *root, int ele)
{
    bh_node *parent = NULL;
    bh_node *foundnode = (bh_node *)bintree_find((bintree_node *)root, (bintree_node **)&parent, ele);
    if (foundnode != NULL)
    {
        // node found

        // both left and right of node found, are null
        if (((foundnode)->left == NULL) && ((foundnode)->right == NULL))
        {   // SAME AS BINTREE
            // adjacent parent's link to this found node to null
            (parent->left == foundnode) ? (parent->left = NULL) : (parent->right = NULL);

            // delete found node
            free(foundnode);
            foundnode = NULL;
        }
        // either left or right of node found, is [not, see above] null
        else if (((foundnode)->left == NULL) || ((foundnode)->right == NULL))
        {   // SAME AS BINTREE
            // adjacent parent's link to this found node to found node's non-null child
            bh_node  *foundnodechild = ((foundnode)->left != NULL ? (foundnode)->left : (foundnode)->right); // get the non-null child
            (parent->left == foundnode) ? (parent->left = foundnodechild) : (parent->right = foundnodechild);

            // delete found node
            free(foundnode);
            foundnode = NULL;
        }
        // both left and right of node found, are   not null
        else
        {
            // find the immediate predecessor
            //		copy immediate predecessor to found node
            //		free immediate predecessor, thru its parent

            // find the immediate predecessor
            bh_node *foundnode_immpredecessorchild = (foundnode)->left;
            bh_node *foundnode_immpredecessorchild_parent = foundnode;
            while (foundnode_immpredecessorchild->right)
            {
                foundnode_immpredecessorchild_parent = foundnode_immpredecessorchild;
                foundnode_immpredecessorchild = foundnode_immpredecessorchild->right;
            }

            // copy thru parent into foundnode, from foundnode's immpredecessorchild
            foundnode->data = foundnode->key = foundnode_immpredecessorchild->data;

            // delete foundnode's immpredecessorchild, thru its parent
            if (foundnode_immpredecessorchild_parent->left == foundnode_immpredecessorchild)
            {
                free(foundnode_immpredecessorchild_parent->left);
                foundnode_immpredecessorchild_parent->left = NULL;
            }
            else
            {
                free(foundnode_immpredecessorchild_parent->right);
                foundnode_immpredecessorchild_parent->right = NULL;
            }
        }
    }
    else
    {
        printf("node with %c not found\n", ele);
    }
}
