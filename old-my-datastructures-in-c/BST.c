#include "BST.h"

// BST
//  all left childs < current node < all right childs
//      no duplicate values
//  On average, binary search trees with n nodes have O(log n) height.
//      However, in the worst case, binary search trees can have O(n) height.
// each comparison allows the operations to skip over half of the tree, so that each lookup/insertion/deletion takes time proportional to the logarithm of the number of items stored in the tree
//      complete binary
//      degenerate tree

//          complete binary
// self - balancing (or height - balanced) BST
//  automatically keeps its height (maximal number of levels below the root) small
//  in the face of arbitrary item insertions and deletions.
//  lookup, insertion, and removal of an item in O(log n) worst - case
//      or
//          degenerate tree

// A red–black tree
//      BST
//      with extra color bit of data per node,
//          which can be either red or black.
//      [1]The extra bit of storage ensures an approximately balanced tree by constraining 
//          how nodes are colored from any path from the root to the leaf.[1]
//               Thus, it is a data structure which is a type of self-balancing binary search tree.
//      When the tree is modified, the new tree is subsequently rearranged and repainted to restore the coloring properties
//  search, insertion, and removal of an item in O(log n)
//      tree rearrangement and recoloring in O(log n)
//  memory footprint    red–black tree (worst 200 MB bits/ 5 GB data+links) ~ BST (5 GB data+links)

// A red–black tree is a special type of binary tree, used in computer science to organize pieces of comparable data, such as text fragments or numbers.

//  BST + below requiremeents:
//          1.A node is either red or black.
//          2.The root is black. (This rule is sometimes omitted.Since the root can always be changed from red to black, but not necessarily vice versa, this rule has little effect on analysis.)
//          3.All leaves(NIL) are black. (All leaves are same color as the root.)
//          4.Every red node must have two black child nodes.
//          5.Every path from a given node to any of its descendant NIL nodes contains the same number of black nodes.


// AVL trees and
// red - black trees
//       are both forms of
//          self - balancing binary search trees.
// AVL tree
// self - balancing BST
//  the heights of the two child subtrees of any node differ by at most one;
//      if at any time they differ by more than one, rebalancing is done to restore this property
// Lookup, insertion, and deletion all take O(log n) time in both the average and worst cases
//  Insertions and deletions may require the tree to be rebalanced by one or more tree rotations.

//  {{{{{{{{ all level are same, last level filled a random }}}}}}}}}}}}}}}}
//  not weight - balanced nor   mue - balanced, that is, sibling nodes can have hugely differing numbers of descendants.


// avl vs red-black tree
//      avl tree height < 1.44 x log base2(n + 2) - 0.328
//      red-black tree height < 2 x log base2(n + 1)
//  For lookup - intensive applications, AVL trees are faster than red - black trees because they are more rigidly balanced
//  AVL trees are more rigidly balanced than red-black trees, leading to slower insertion and removal but faster retrieval.



// red - black trees
//  Lookup, insertion, and deletion all take O(log n) time in both the average and worst cases




//  A splay tree is a binary search tree that automatically moves frequently accessed elements 
//      nearer to the root.
//  insertion, look - up and removal
//      avg case - O(log n)
//      worst case - O(log n) amortized time
//  splaying on node => get it to root


//  In a treap(tree heap), each node also holds a(randomly chosen) priority and
//   the parent node has higher priority than its children.Tango trees are trees optimized
//      for fast searches.


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
