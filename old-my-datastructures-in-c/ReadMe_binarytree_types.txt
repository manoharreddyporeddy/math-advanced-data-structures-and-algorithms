***************************************************************
* Tree
***************************************************************
* root node
*       The topmost node in a tree.
*
* edges or links
*   From root note, all other nodes can be reached by following these.
*
* external node/ outer node/ leaf node/ terminal node
*     node of a tree that does not have child nodes
* 
* internal node/ inner node/ inode/ branch node
*     node of a tree that has child nodes
* 
* height of a node
*     is the length of the "longest" downward path to a leaf from that node.
*       Ex: The height of the root = the height of the tree.
*           The height of the leaf nodes = 0, furthur levels down are 1, 2, ..., n
*
* depth of a node
*     is the length of the path to its root (i.e., its root path). 
*       Ex: The depth of the root node = 0, furthur levels down are 1, 2, ..., n
*
*   Tree with only a single node (hence both a root and leaf) has depth = height = 0
*   An empty tree (tree with no nodes, if such are allowed) has depth = height = -1
*
*
*
***************************************************************

binary tree
    tree with
        0 to 2 children  forall  nodes
        which are referred to as the left child and the right child
    can be empty set
                               1 
                            /      \
                         /            \
                      /                 \
                   /                      \
                 2                          3
              /    \                      /    \
            /        \                  /        \
          4            5              6            7
        /   \                       /            /   \
      8      9                    12            14    15
     /      / \                    \           / \    / \
    16     18 19                   25         28 29  30 31

A rooted binary tree
    tree with
        a root node &
        0 to 2 children  forall  nodes

FULL BINARY tree or PROPER binary tree
    (sometimes: 2-TREE, STRICTLY BINARY tree):     Tree  +  2 CHILDREN forall INTERNAL NODES
                               1 
                            /      \
                         /            \
                      /                 \
                   /                      \
                 2                          3
              /    \                      /    \
            /        \                  /        \
          4            5              6            7
        /   \        /   \          /   \
      8      9      10    11      12    13
     / \    / \    / \
    16 17  18 19  20 21


PERFECT BINARY tree:                                FULL binary tree  +  SAME DEPTH/LEVEL  forall LEAVES
                                            EX: Ancestry chart of a person to a given depth, as each person has exactly two biological parents (one mother and one father)
                               1 
                            /      \
                         /            \
                      /                 \
                   /                      \
                 2                          3
              /    \                      /    \
            /        \                  /        \
          4            5              6            7
        /   \        /   \          /   \        /   \
      8      9      10    11      12    13      14    15
     / \    / \    / \    / \    / \    / \    / \    / \
    16 17  18 19  20 21  22 23  24 25  26 27  28 29  30 31


COMPLETE binary tree:   Binary tree   +   EVERY LEVEL IS COMPLETELY FILLED, EXCEPT POSSIBLY THE DEEPEST
                                      +   ALL NODES ARE AS FAR LEFT AS POSSIBLE.
                               1 
                            /      \
                         /            \
                      /                 \
                   /                      \
                 2                          3
              /    \                      /    \
            /        \                  /        \
          4            5              6            7
        /   \        /   \          /   \        /   \
      8      9      10    11      12    13      14    15
     / \    /
    16 17  18
    ALMOST/NEARLY complete binary tree:     tree + LAST LEVEL IS NOT COMPLETELY FILLED.
            This type of tree is used as a specialized data structure called a heap.

INFINITE COMPLETE binary tree
    is a tree with a countably infinite number of levels
    in which every node has two children
    so that there are 2d nodes at level d.
        The set of all nodes is countably infinite
        the set of all infinite paths from the root is uncountable, having the cardinality of the continuum.
            These paths correspond by an order-preserving bijection to the points of the Cantor set, or (using the example of a Stern–Brocot tree) to the set of positive irrational numbers.

BALANCED binary tree:       Binary tree  +  DEPTH/LEVEL  forall LEAVES differ by 0 or 1
                            Binary tree  +  LEFT & RIGHT SUBTREES DIFFER <= 1
            in general,     BINARY TREE  +  NO LEAF IS MUCH FARTHER AWAY FROM THE ROOT, THAN ANY OTHER LEAF.
                                (Different balancing schemes allow different definitions of "much farther".[21])
    Binary trees that are balanced according to this definition have a predictable depth
        Depth/ Height = integer part of log2(n), where n is the number of nodes on the balanced tree.
        For example
            For a balanced tree with only 1 node, log2(1) = 0, so the depth of the tree is 0.
            For a balanced tree with 100 nodes, log2(100) = 6.64, so it has a depth of 6.
                               1 
                            /      \
                         /            \
                      /                 \
                   /                      \
                 2                          3
              /    \                      /    \
            /        \                  /        \
          4            5              6            7
        /   \        /   \          /   \        /   \
      8      9      10    11      12    13      14    15
     / \    /      /                            / \   
    16 17  18     20                           28 29           <<<---   looks like, last level has 0 to 2 leaves - tree hight = logBase2(n)

DEGENERATE/ PATHOLOGICAL) tree:     Tree + Each parent node has only 1 associated child node.
    This means that performance-wise, the tree will behave like a linked list data structure.

                                 1 
                                   \
                                      \
                                        \
                                          \
                                            3
                                          /
                                        /
                                      6
                                        \
                                         13
                                        /
                                      26

