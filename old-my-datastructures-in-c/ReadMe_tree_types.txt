--------------------------------

2–3 tree:       Tree +
                        forall INTERNAL NODES
                            2-node (2 children + 1 data), or,
                            3-node (3 children + 2 data)
                        forall EXTERNAL NODES
                            0 children + 1or2 data
                        balanced
                        data is sorted
    2–3 trees are an isometry of AA trees, meaning that they are equivalent data structures. In other words, for every 2–3 tree, there exists at least one AA tree with data elements in the same order. 
    2–3 trees are balanced, meaning that each right, center, and left subtree contains the same or close to the same amount of data.
--------------------------------

A-A tree











--------------------------------

Heap
	tree + heap property
    where, heap property =     key(parent) >= key(child)   => root has greatest key, so such its a max-heap.
                                    or
                               key(parent) <= key(child),  its a min-heap.

    child count can be 0 to many

	Heap is one maximally-efficient implementation of an abstract data type called a priority queue.
	Heaps are crucial in several efficient graph algorithms such as Dijkstra's algorithm.

	Heaps are usually implemented in an array, and do not require pointers between elements[citation needed].
	Operations:
		find-max or find-min:			find the maximum item of a max-heap or a minimum item of a min-heap, respectively 
		delete-max or delete-min:		removing the root node of a max- or min-heap, respectively 
		increase-key or decrease-key:	updating a key within a max- or min-heap, respectively 
		insert:							adding a new key to the heap 
		merge:							joining two heaps to form a valid new heap containing all the elements of both. 
	Heaps are used in the sorting algorithm heapsort.

--------------------------------
 Binary heaps
    A binary max-heap or min-heap, is an ordered structure where
		some nodes are guaranteed greater than other nodes,
		e.g. the parent vs two children.
	A binary heap can be stored in an array , where ,
	- given a position i (the parent) , i*2 is the left child, and i*2+1 is the right child.
			- ( C arrays begin at position 0, but 0 * 2 = 0, and 0 *2 + 1= 1, which is incorrect , so start the heap at position 1, or add 1 for parent-to-child calculations, and subtract 1 for child-to-parent calculations ).
		try to model this using with a pencil and paper, using 10 random unsorted numbers, and inserting each of them into a "heapsort" array of 10 elements.
		To insert into a heap, end-add and swap-parent if higher, until parent higher.
		To delete the top of a heap, move end-to-top, and defer-higher-child or sift-down , until no child is higher.
		try it on a pen and paper the numbers 10, 4, 6 ,3 ,5 , 11.
	pen-and-paper-solution
		10, 4, 6, 3, 5, 11 -> 10
		4, 6,3, 5, 11 -> 10, 4  : 4 is end-added, no swap-parent because 4 < 10.
		6, 3, 5, 11 -> 10, 4, 6  : 6 is end-added, no swap-parent because 6 < 10.
		3, 5, 11 -> 10, 4, 6, 3 : 3 is end-added, 3 is position 4 , divide by 2 = 2, 4 at position 2, no swap-parent because 4 > 3.
		5 , 11 -> 10, 4, 6, 3 , 5 : 5 is end-added , 5 is position 5, divided by 2 = 2, 4 at position 2, swap-parent as 4 < 5; 5 at position 2, no swap-parent because 5 < 10 at position 1.
	- 10 , 5, 6, 3, 4
		11 -> 10, 5, 6, 3, 4, 11 : 11 is end-added, 11 is position 6, divide by 2 = 3, swap 6 with 11, 11 is position 3, swap 11 with 10, stop as no parent.
	- 11, 5, 10, 3, 4, 6
	- 11 has children 5, 10 ; 5 has children 3 and 4 ; 10 has child 6. Parent always > child.

		the answer was 11, 5, 10, 3, 4 , 6.
		EXERCISE: Now try removing each top element of 11, 5, 10, 3, 4, 6 , using end-to-top and sift-down ( or swap-higher-child) to get the numbers
	in descending order.
--------------------------------
