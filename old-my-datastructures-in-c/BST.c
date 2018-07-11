#include "BST.h"

// FIXME: hack to reuse in BST, only for printf format
extern char *bintree_format;
extern char *bintree_format_int;

bst_node* _bst_create_new_node(const int ele)
{
    bst_node *new_node = (bst_node *)malloc(sizeof(bst_node));
    new_node->key = new_node->data = ele;		// FIXME: For now, data & key are same, so data cannot be unique (unique? or duplicate?)
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

bst_node* bst_create_from_array(int arr[], int len)
{
    if (!(len > 0))
    {
        return NULL;
    }

    bintree_format = bintree_format_int;	// FIXME: hack to reuse in BST, only for printf format

    bst_node *start = _bst_create_new_node(arr[0]);    // 1st ele

    for (int i = 1; i < len; i++)					    // rest of eles
    {
        bst_insert(start, arr[i]);
    }

    return start;
}

void bst_insert(bst_node *root, int ele)
{
    bst_node *new_node = _bst_create_new_node(ele);

    bst_node *temp = root;
    while (1)
    {
        // new node shud be in left subtree
        if (new_node->key < temp->key)
        {
            if (temp->left == NULL)
            {
                temp->left = new_node;
                break;
            }

            temp = temp->left;
        }
        // new node shud be in right subtree
        else if (new_node->key > temp->key)
        {
            if (temp->right == NULL)
            {
                temp->right = new_node;
                break;
            }

            temp = temp->right;
        }
        else
        {
            printf("invalid, key shud be unique\n");	// TODO: == looks invalid, key shud be unique
            break;
        }
    }
}

void bst_delete(bst_node *root, int ele)
{
    bst_node *parent = NULL;
    bst_node *foundnode = (bst_node *)bintree_find((bintree_node *)root, (bintree_node **)&parent, ele);
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
            bst_node *foundnodechild = ((foundnode)->left != NULL ? (foundnode)->left : (foundnode)->right); // get the non-null child
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
            bst_node *foundnode_immpredecessorchild = (foundnode)->left;
            bst_node *foundnode_immpredecessorchild_parent = foundnode;
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
