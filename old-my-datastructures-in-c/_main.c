/**********************************
*    Topic:        Data structures
*    @author:    pgmreddy@outlook.com
*    @version:    0.5, 2014/08/08
*   @copyright: 2014 www.sortedINF.com
***********************************/

/**********************************
*    Code Blocks (www.codeblocks.org/) looks good, cross-platform too.
*        Downloaded and installed.
*        Built new C console project
*        New project > Console application > C language > datastructures > default GNU GCC compiler > Finish
*        Run the console app.. works fine.
*        Menu > Build > Run
*
*    OK, switched to Visual Studio 2013 Express
*       to get more productive, since I am used to its shortcuts
**********************************/


// treap
//  numeric priority as heap, keys as bst
// its name is a portmanteau of tree and heap
// It is a Cartesian tree in which each key is given a(randomly chosen) numeric priority.As with any binary search tree, the inorder traversal order of the nodes is the same as the sorted order of the keys.The structure of the tree is determined by the requirement that it be heap - ordered: that is, the priority number for any non - leaf node must be greater than or equal to the priority of its children.Thus, as with Cartesian trees more generally, the root node is the maximum - priority node, and its left and right subtrees are formed in the same manner from the subsequences of the sorted order to the left and right of that node.
//      An equivalent way of describing the treap is that it could be formed by inserting the nodes highest - priority - first into a binary search tree without doing any rebalancing
//  search => binary search
//  insert => generate random priority for new key, binary search, insert at null, tree rotate on priority
//  delete => delete as in BST, tree rotate on priority

//  Randomized binary search tree[edit]
//      Rather than storing random priorities on each node, the randomized binary search tree stores 
//          a small integer at each node, 
//          the number of its descendants (counting itself as one); 
//      these numbers may be maintained during tree rotation operations at only
//          a constant additional amount of time per rotation. 

// trie
//  The term trie comes from   re trie val
//      key = string prefixes = root is empty, childs have same common prefix
//      values = may or may not be present with every node
//               ()
//               / \ 
//            (t)   (i) 14
//            /
//          (te)
//          /   \
//    (ten) 213  (ted) 213

// hash table/ hash map
//      a structure that can    map         keys    to  values
//      used to implement an associative array
//  A hash table uses a 
//      hash function to compute 
//          an index into an 
//              array of buckets or slots, from which the correct value can be found.

//  index = f(key, array_size)
//          hash = hashfunc(key)
//          index = hash % array_size
//  value = hash_table[index]
//      index points to a bucket
//          bucket  can have 0 to 3 entries -- seperate chaining required if >1 entries
// B-Tree
//  Tree (instead of Binary tree)
//  generalization of a BST, i.e.; 2+ children
//  B-tree is optimized for systems that 
//      read and write large blocks of data.
//      It is commonly used in databases and filesystems.
// Each internal node of a B - tree will contain a number of keys.The keys act as separation values which divide its subtrees
//      if an internal node has 3 child nodes(or subtrees) then it must have 2 keys: a1 and a2.
//      All values in the leftmost subtree will be less than a1, all values in the middle subtree will be between a1 and a2, and
//          all values in the rightmost subtree will be greater than a2.

//  2–3 tree
//  B-Tree
//  Every internal node is a 2 - node or a 3 - node.
//      internal node = node with children
//          2-node => 2 children 1 data ele
//          3-node => 3 children 2 data ele
//      All leaves are at the same level.
//      All data is kept in sorted order.
//  move middle to parent & split
//      insert in 2-node
//      insert in 3-node, parent is 2-node
//      insert in 3-node, parent is 3-node


// AA tree
//      balanced tree
//          used for storing and retrieving ordered data efficiently
//      variation of the red - black tree
//      an enhancement to the binary search tree
//  Unlike red-black trees
//      red nodes on an AA tree can only be added as a right subchild.
//      In other words, no red node can be a left sub-child.
//  
//  AA trees require O(log(N)) bits of metadata per node, in the form of an integer "level". 
//  The following invariants hold for AA trees:
// 1.The level of every leaf node is one.
// 2.The level of every left child is exactly one less than that of its parent.
// 3.The level of every right child is equal to or one less than that of its parent.
// 4.The level of every right grandchild is strictly less than that of its grandparent.
// 5.Every node of level greater than one has two children.



//  In the B + tree, copies of the keys are stored in the internal nodes; the keys and records are stored in leaves; in addition, a leaf node may include a pointer to the next leaf node to speed sequential access(Comer 1979, p. 129).
//  The B*-tree balances more neighboring internal nodes to keep the internal nodes more densely packed(Comer 1979, p. 129).This variant requires non - root nodes to be at least 2 / 3 full instead of 1 / 2 (Knuth 1998, p. 488).To maintain this, instead of immediately splitting up a node when it gets full, its keys are shared with a node next to it.When both nodes are full, then the two nodes are split into three.Deleting nodes is somewhat more complex than inserting however.
//  B - trees can be turned into    order statistic trees   to allow rapid searches for the Nth record in key order, or counting the number of records between any two records, and various other related operations.[1]




#include "binaryheap.h"
int test_binaryheap()
{
    printf(" -- test_binaryheap --- \n");
    // ---------------------------------------------------

    bh_node *root = NULL;
    int arr[] = { 19, 14, 16, 15, 7, 6, 8, 5, 12, 1, 0, 3, 9, 4, 2, 10 };


    /**********************************
    *        BINARY HEAP CREATE
    ***********************************/
    printf("build binary heap from an array \n");
    root = binaryheap_create_from_array(arr, sizeof(arr) / sizeof(arr[0]));
    printf("\n");

    // bfs traversal
    printf("%-30s", "bintree_traverse_level_order: ");
    bintree_traverse_level_order((bintree_node *)root);                printf("\n");
    printf("\n");



    return 0;
}

#include "BST.h"
int test_bst()
{
    printf(" -- test_bst --- \n");
    // ---------------------------------------------------

    int arr[] = { 19, 14, 16, 15, 7, 6, 8, 5 };
    bst_node *root = NULL;


    /**********************************
    *        BST CREATE
    ***********************************/
    printf("build BST from an array \n");
    root = bst_create_from_array(arr, sizeof(arr) / sizeof(arr[0]));
    printf("\n");

    //            19
    //           /
    //         14
    //        /  \
    //      7     16
    //     / \    /
    //    6   8  15
    //   /
    //  5


    /**********************************
    *        BST TRAVERSAL
    ***********************************/
    // dfs traversal
    printf("%-30s", "bintree_traverse_pre_order: ");
    bintree_traverse_pre_order((bintree_node *)root);         printf("\n");
    printf("%-30s", "bintree_traverse_in_order: ");
    bintree_traverse_in_order((bintree_node *)root);          printf("\n");
    printf("%-30s", "bintree_traverse_post_order: ");
    bintree_traverse_post_order((bintree_node *)root);        printf("\n");
    printf("\n");

    // bfs traversal
    printf("%-30s", "bintree_traverse_level_order: ");
    bintree_traverse_level_order((bintree_node *)root);                printf("\n");
    printf("\n");

    /**********************************
    *        BST DELETE A NODE
    ***********************************/
    //            19
    //           /
    //         14
    //        /  \
    //      7     16
    //     / \    /
    //    6   8  15
    //   /
    //  5

    // delete with 1 child
    printf("bst_delete, 1 child node, 16: \n");
    bst_delete(root, 16);
    printf("%-30s", "bintree_traverse_level_order: ");
    bintree_traverse_level_order((bintree_node *)root);        printf("\n");

    //            19
    //           /
    //         14
    //        /  \
    //      7     15
    //     / \
    //    6   8
    //   /
    //  5


    // delete with 0 child
    printf("bst_delete, 0 child node,  5: \n");
    bst_delete(root, 5);
    printf("%-30s", "bintree_traverse_level_order: ");
    bintree_traverse_level_order((bintree_node *)root);        printf("\n");

    //            19
    //           /
    //         14
    //        /  \
    //      7     15
    //     / \
    //    6   8


    // delete with 2 child
    printf("bst_delete, 2 child node, 14: \n");
    bst_delete((bst_node *)root, 14);
    printf("%-30s", "bintree_traverse_level_order: ");
    bintree_traverse_level_order((bintree_node *)root);        printf("\n");
    printf("\n");

    //            19
    //           /
    //         8
    //        /  \
    //      7     15
    //     /
    //    6


    /**********************************
    *        BST INSERT A NODE
    ***********************************/

    printf("bst_insert, 14: \n");
    bst_insert((bst_node *)root, 14);
    printf("%-30s", "bintree_traverse_level_order: ");
    bintree_traverse_level_order((bintree_node *)root);        printf("\n");
    printf("\n");

    //            19
    //           /
    //         8
    //        /  \
    //      7     15
    //     /     /
    //    6     14




    /**********************************
    *        BST DELETE ALL NODES
    ***********************************/
    printf("bintree_deleteall: \n");
    bintree_deleteall(&(bintree_node *)root);
    printf("%-30s", "bintree_traverse_level_order: ");
    bintree_traverse_level_order((bintree_node *)root);        printf("\n");
    printf("\n");



    return 0;
}

#include "binarytree.h"
int test_binarytree()
{
    printf(" -- test_binarytree --- \n");
    // ---------------------------------------------------

    bintree_node *root = NULL;
    int in_order_arr[] = { 'D', 'B', 'E', 'A', 'F', 'C' };
    int pre_order_arr[] = { 'A', 'B', 'D', 'E', 'C', 'F' };


    /**********************************
    *        BINARY TREE CREATION
    ***********************************/
    printf("build tree from inorder and preorder sequence \n");
    root = bintree_build_from_in_order_and_pre_order_arrays(in_order_arr, pre_order_arr, 0, sizeof(in_order_arr) / sizeof(in_order_arr[0]) - 1);
    printf("\n");

    //       A
    //     /   \ 
    //   B       C
    //  / \     /
    // D   E   F



    /**********************************
    *        BINARY TREE TRAVERSAL
    ***********************************/
    printf("%-30s", "bintree_traverse_in_order: ");
    bintree_traverse_in_order(root);            printf("\n");
    printf("%-30s", "bintree_traverse_pre_order: ");
    bintree_traverse_pre_order(root);        printf("\n");
    printf("%-30s", "bintree_traverse_post_order: ");
    bintree_traverse_post_order(root);        printf("\n");
    printf("\n");

    printf("%-30s", "bintree_traverse_level_order: ");
    bintree_traverse_level_order(root);                printf("\n");
    printf("\n");


    /**********************************
    *        BINARY TREE DELETE A NODE
    ***********************************/
    //       A
    //     /   \ 
    //   B       C
    //  / \     /
    // D   E   F

    // delete with 2 child
    //  can't be done un-ambiguously, see BST


    // delete with 1 child
    printf("bintree_delete the C node: \n");
    bintree_delete(root, 'C');
    printf("%-30s", "bintree_traverse_level_order: ");
    bintree_traverse_level_order(root);        printf("\n\n");
    //       A
    //     /   \ 
    //   B       F
    //  / \
    // D   E

    // delete with 0 child
    printf("bintree_delete the F node: \n");
    bintree_delete(root, 'F');
    printf("%-30s", "bintree_traverse_level_order: ");
    bintree_traverse_level_order(root);        printf("\n\n");
    //       A
    //     /
    //   B
    //  / \
    // D   E





    /**********************************
    *        BINARY TREE INSERT A NODE
    ***********************************/

    //       A
    //     /
    //   B
    //  / \
    // D   E

    // insert to 0 child node
    printf("bintree_insert the F node, to A node, to right, orginal child to left: \n");
    bintree_insert(root, 'F', false, 'A', true);
    printf("%-30s", "bintree_traverse_level_order: ");
    bintree_traverse_level_order(root);        printf("\n\n");
    //       A
    //     /   \ 
    //   B       F
    //  / \
    // D   E

    // insert to 1 child node
    printf("bintree_insert the C node, to A node, to right, orginal child to left: \n");
    bintree_insert(root, 'C', false, 'A', true);
    printf("%-30s", "bintree_traverse_level_order: ");
    bintree_traverse_level_order(root);        printf("\n\n");
    //       A
    //     /   \ 
    //   B       C
    //  / \     /
    // D   E   F

    // insert to 2 child node
    printf("bintree_insert the b node, to A node, to left, orginal childs to left: \n");
    bintree_insert(root, 'b', true, 'A', true);
    printf("%-30s", "bintree_traverse_level_order: ");
    bintree_traverse_level_order(root);        printf("\n\n");
    //        A
    //      /   \ 
    //     b      C
    //    /      /
    //   B      F
    //  / \
    // D   E



    /**********************************
    *        BINARY TREE DELETE ALL NODES
    ***********************************/
    printf("bintree_deleteall: \n");
    bintree_deleteall(&root);
    printf("%-30s", "bintree_traverse_level_order: ");
    bintree_traverse_level_order(root);        printf("\n\n");



    return 0;
}

#include "linkedlist.h"
void test_linkedlist()
{
    printf(" -- test_linkedlist --- \n");

    int arr[] = { 'B', 'C', 'D', 'F' };
    node *start = NULL;

    printf("Building LL with B C D F \n");
    start = ll_create_linked_list(start, arr, sizeof(arr) / sizeof(arr[0]));
    ll_traverse(start);

    printf("insert A at begin\n");
    start = ll_insert_at_begin(start, 'A');
    ll_traverse(start);

    printf("insert E at position 5\n");
    start = ll_insert_at_pos(start, 'E', 5);
    ll_traverse(start);

    printf("insert 2 after node start\n");
    ll_insert_after_node(start, '2');
    ll_traverse(start);

    printf("delete at begin\n");
    start = ll_delete_begin(start);
    ll_traverse(start);

    printf("delete at position 5\n");
    start = ll_delete_at_pos(start, 5);
    ll_traverse(start);
    printf("delete at position 5\n");
    start = ll_delete_at_pos(start, 5);
    ll_traverse(start);
    printf("delete at position 5\n");
    start = ll_delete_at_pos(start, 5);
    ll_traverse(start);

    start = ll_delete_at_pos(start, 1);
    ll_traverse(start);
}

#include "queue_circular_buffer.h"
int test_queue_circular_buffer()
{
    printf(" -- test_queue_circular_buffer --- \n");
    // ---------------------------------------------------

    circular_buffer cb1;
    cb_init(&cb1, -1);

    printf("\npoping..  ");
    for (int i = 0; i < CB_CAPACITY; i++) {        // cb empty(s)
        printf("%d  ", cb_pop(&cb1));
    }
    printf("\n");

    printf("\npushing.. ");
    for (int i = 0; i < CB_CAPACITY + 1; i++) {    // 1 cb full
        printf("%d  ", i + 1);
        cb_push(&cb1, i + 1);
    }
    printf("\npoping..  ");
    for (int i = 0; i < CB_CAPACITY + 1; i++) {    // 1 cb empty
        printf("%d  ", cb_pop(&cb1));
    }
    printf("\n");


    printf("\npushing.. ");
    for (int i = 0; i < CB_CAPACITY; i++) {    // 1 cb full
        printf("%d  ", i + 1);
        cb_push(&cb1, i + 1);
    }
    printf("\npoping..  ");
    for (int i = 0; i < CB_CAPACITY - 2; i++) {    // 1 cb empty
        printf("%d  ", cb_pop(&cb1));
    }
    printf("\n");


    printf("\npushing.. ");
    for (int i = 0; i < CB_CAPACITY; i++) {
        printf("%d  ", i + 1);
        cb_push(&cb1, i + 1);
    }
    printf("\npoping..  ");
    for (int i = 0; i < CB_CAPACITY - 2; i++) {
        printf("%d  ", cb_pop(&cb1));
    }
    printf("\n");


    printf("\npushing.. ");
    for (int i = 0; i < CB_CAPACITY; i++) {
        printf("%d  ", i + 1);
        cb_push(&cb1, i + 1);
    }
    printf("\npoping..  ");
    for (int i = 0; i < CB_CAPACITY + 1; i++) {
        printf("%d  ", cb_pop(&cb1));
    }

    printf("\n");
    printf("\n");
    return 0;
}

#include "queue.h"
int test_queue()
{
    printf(" -- test_queue --- \n");
    // ---------------------------------------------------

    queue q1;
    queue_init(&q1, -1);

    printf("\n poping \n");
    for (int i = 0; i < QUEUE_CAPACITY; i++) {        // queue empty(s)
        printf("%d ", queue_pop(&q1));
    }

    printf("\n pushing \n");
    for (int i = 0; i < QUEUE_CAPACITY + 1; i++) {    // 1 queue full
        queue_push(&q1, i + 1);
    }

    printf("\n poping \n");
    for (int i = 0; i < QUEUE_CAPACITY + 1; i++) {    // 1 queue empty
        printf("%d ", queue_pop(&q1));
    }

    printf("\n");
    return 0;
}


#include "stack.h"
int test_stack()
{
    printf(" -- test_stack --- \n");

    // ---------------------------------------------------
    // test random operations
    // ---------------------------------------------------
    stack s1;
    stack_init(&s1, -1);
    for (int i = 0; i < STACK_CAPACITY; i++) {      // underflows
        printf("%d ", stack_pop(&s1));
    }

    for (int i = 0; i < STACK_CAPACITY + 1; i++) {    // 1 overflow, at the end of loop
        stack_push(&s1, i + 1);
    }

    for (int i = 0; i < STACK_CAPACITY + 1; i++) {    // 1 underflow, at the end of loop
        printf("%d ", stack_pop(&s1));
    }
    printf("\n");

    // ---------------------------------------------------
    // decimal to binary - D2B
    // ---------------------------------------------------
    int n = 8;
    stack_init(&s1, -1);
    printf("binary form of %d is ", n);
    while (n > 0)
    {
        stack_push(&s1, n % 2);
        n = n / 2;
    }
    while (!stack_empty(&s1))
    {
        printf("%d", stack_pop(&s1));
    }
    printf("\n");


    // ------------------------------
    // Evaluation of an infix expression that is [not] fully parenthesized. (Take 2 stacks for [not])
    //        (((234 * 5) - (1 * 2)) / (11 - 9))
    // ------------------------------
    char *p_infix_expr = "(((234 * 5) - (1 * 2)) / (11 - 9))";
    stack_init(&s1, -1);
    printf("Evaluation of an infix expression %s is ", p_infix_expr);
    for (char *p = p_infix_expr; *p; p++)
    {
        // igore Opening brackets
        if ((*p == '(') || (*p == ' '))
        {
            continue; // with next character
        }
        else if ((*p >= '0') && (*p <= '9'))
        {
            // printf("%c", *p);
            long l = strtol(p, &p, 10);
            stack_push(&s1, l); // push the number

            // since p jumped a number which could be multiple digits
            //  come back 1 char because loop increments 1 char.
            p--;

            continue; // with next character
        }
        else if ((*p == '*') || (*p == '/') || (*p == '+') || (*p == '-'))    // ASSUMTION: no other operator is input
        {
            // printf("%c", *p);
            stack_push(&s1, *p);                    // push the number
            continue; // with next character
        }
        // Closing brackets
        else if (*p == ')')
        {
            // pop 3 times, and evaluate
            int val2 = stack_pop(&s1);    // value2 first
            int op = stack_pop(&s1);
            int val1 = stack_pop(&s1);

            int result;
            switch (op)
            {
            case '*': result = val1 * val2; /* printf("  %d  ", result); */ stack_push(&s1, result); break;
            case '/': result = val1 / val2; /* printf("  %d  ", result); */ stack_push(&s1, result); break;
            case '+': result = val1 + val2; /* printf("  %d  ", result); */ stack_push(&s1, result); break;
            case '-': result = val1 - val2; /* printf("  %d  ", result); */ stack_push(&s1, result); break;
            }
            continue; // with next character
        }
    }

    printf("%d", stack_pop(&s1));

    printf("\n");
    return 0;
}


#include "array.h"
int test_array()
{
    printf(" -- test_array --- \n");

    int capacity = 6;
    dynamic_array_struct darr = { NULL, 0, 0 }, *pdynarr = &darr;

    /// build some arrays, use them, free them
    int *parr = NULL;
    parr = get_fixed_array(capacity);     printf("%d\n", sizeof(parr));
    pdynarr = create_dynamic_array(&darr, capacity);

    const int init1 = 100;
    const int init2 = 200;
    initialize_array(parr, capacity, init1);
    pdynarr->size = initialize_array(pdynarr->parr, pdynarr->size, init2);

    for (int i = 0; i < capacity; i++)
    {
        printf("A:  array_get_element_at %d is %d\n", i, array_get_element_at(parr, capacity, i));
    }
    printf("\n");
    for (int i = 0; i < capacity; i++)
    {
        printf("DA: array_get_element_at %d is %d\n", i, array_get_element_at(pdynarr->parr, pdynarr->size, i));
    }
    printf("\n");

    for (int i = 0; i < capacity; i++)
    {
        printf("A:  array_get_index_of %d is %d\n", init1 + i, array_get_index_of(parr, capacity, init1 + i));
    }
    printf("\n");
    for (int i = 0; i < capacity; i++)
    {
        printf("DA: array_get_index_of %d is %d\n", init2 + i, array_get_index_of(pdynarr->parr, pdynarr->size, init2 + i));
    }
    printf("\n");

    myprintf20("initial array: ");
    print_array(pdynarr->parr, capacity);


    capacity = array_insert_at_begin(pdynarr, 11);
    capacity = array_insert_at_end(pdynarr, 21);
    capacity = array_insert_at_middle(pdynarr, 31);
    printf("\n");

    capacity = array_insert_at_begin(pdynarr, 11);
    capacity = array_insert_at_end(pdynarr, 21);
    capacity = array_insert_at_middle(pdynarr, 31);
    printf("\n");

    capacity = array_insert_at_begin(pdynarr, 11);
    capacity = array_insert_at_end(pdynarr, 21);
    capacity = array_insert_at_middle(pdynarr, 31);
    printf("\n");
    printf("\n");

    capacity = array_delete_at_begin(pdynarr);
    capacity = array_delete_at_end(pdynarr);
    capacity = array_delete_at_middle(pdynarr);


    free_dynamic_array(&pdynarr->parr);
    free_dynamic_array(&pdynarr->parr); // no problem for us

    printf("\n");
    return 1;
}

/**
*  main() is starting point of execution
*
*  @param argc        gives number of arguments passed to this exe - ARGument Count
*  @param argv        gives arguments passed - ARGument Vector -- if argc != 0, then argv[0] gives name of this exe (platform dependent => you may get a blank)
*
*  @return 0
*
*/

int main(int argc, int **argv)
{
    // test_array();
    // test_stack();
    // test_queue();
    // test_queue_circular_buffer();

    // test_linkedlist();

    test_binarytree();
    // test_bst();
    // test_binaryheap();

    return 0;
}
