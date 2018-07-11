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
