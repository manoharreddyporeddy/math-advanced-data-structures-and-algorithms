Implement all "data structures" in C language

Following: DS thorugh C++
	Building binary tree (BT)
	BT thru Linked list (LL)
		In-order traversal (InOT)
		Pre-order traversal (PrOT)
		Post-order traversal (PoOT)
	Delete node
		Both children Empty
		One children Empty
		Both children Non-Empty
	ReConstruction of BT from InOT & PrOT
	Tree as BT
	Forest as BT

	A weight-balanced binary tree is
		a binary tree which is
			balanced based on knowledge of the probabilities of searching for each individual node.
				Within each subtree, the node with the highest weight appears at the root.
				This can result in more efficient searching performance.
		1. greatest weight is root of tree
		2. order by values
		3. hightest weight node of all nodes in left & right subtrees, are roots of subtrees

	Construction of such a tree is similar to that of a Treap, but node weights are chosen randomly in the latter.
	A weight balanced tree gives close to optimal values for the   expected length of successful search (ELOSS)   calculations
		ELOSS = sum of   depth*probability   for all nodes
			This is the expected number of nodes that will be examined before finding the desired node.





Following: http://en.wikipedia.org/wiki/Data_structure
Also, building more on this.

data structure types
	array
	one-dimensional array (vector)
	multi-dimensional array
	records/structures/tuples
	hash table/dictionary/map
	union
	tagged union
	set
	graphs
	trees
	linked
	object

		Data structures are generally based on the
		ability of a computer to
		fetch and store data at any place in its memory, specified by an address – a bit string that can be
		itself stored in memory and manipulated by the program.
		Thus, the array and record data structures are based on
		computing the addresses of data items with arithmetic operations; while the
		linked data structures are based on
		storing addresses of data items within the structure itself.
		Many data structures use both principles, sometimes combined in non-trivial ways (as in XOR linking).

		The implementation of a data structure usually requires
		writing a set of procedures that
		build and manipulate   instances of that structure.
		The efficiency of a data structure
		cannot be analyzed separately from those operations.
		This observation motivates the theoretical concept of an abstract data type,
		abstract data type
		a data structure that is defined indirectly by the operations that may be performed   on it, and the
		mathematical properties of those operations (including their space and time cost).
		Many known data structures have
		concurrent versions that
		allow   multiple computing threads   to access the data structure simultaneously.

		Data structure is a
		particular way of organizing data in a computer
		so that it can be used efficiently.
		provide a means to manage large amounts of data efficiently, such as
		large databases and
		internet indexing services.
		Usually, efficient data structures are a key in designing efficient algorithms.
		Some formal design methods and programming languages emphasize
		data structures, rather than algorithms, as the key organizing factor in software design.
		Different kinds of data structures are suited to different kinds of applications
		and some are highly specialized to specific tasks.
		For example,

		stack
			Following: http://en.wikipedia.org/wiki/Stack_(abstract_data_type)
			stack is a Last-In-First-Out (LIFO) data structure.
				In a LIFO data structure, the last element added to the structure must be the first one to be removed.
			Main operations:
				push(data) to add data to stack at top
				pop() to remove data from stack at top
				isempty() to know if stack is empty or not



		http://en.wikipedia.org/wiki/Double-ended_queue

		http://en.wikipedia.org/wiki/Priority_queue
			To improve performance, priority queues typically use a 
				heap as their backbone, giving 
					O(log n) performance for inserts and removals, and 
					O(n) to build initially.
			Alternatively, when a 
				self-balancing binary search tree is used, 
					insertion and removal also take O(log n) time, although 
					building trees from existing sequences of elements takes O(n log n) time; 
			this is typical where one might already have access to these data structures, such as with third-party or standard libraries.
				specialized heap data structures 
				binary heap uses 
					O(log n) time for both operations, but also 
					allows queries of the element of highest priority without removing it in constant time.
				Binomial heaps add several more operations, but require 
					O(log n) time for requests.
				Fibonacci heaps can 
					insert elements, 
					query the highest priority element, and 
					increase an element's priority 
						in amortized constant time,[1] though 
					deletions are still O(log n).
				Brodal queues can do this in 
					worst-case constant time however Brodal calls them "quite complicated" and "[not] applicable in practice.".
					
		TODO:
			http://en.wikipedia.org/wiki/Priority_queue#Applications
			http://en.wikipedia.org/wiki/Hash_table#Collision_resolution
		Done:
			http://en.wikipedia.org/wiki/Double-ended_priority_queue
			http://en.wikipedia.org/wiki/Set_(abstract_data_type)
			http://en.wikipedia.org/wiki/Set_(abstract_data_type)#Multiset
				In efficient implementations, however, sets are implemented using self-balancing binary search trees or hash tables, rather than a list.
			http://en.wikipedia.org/wiki/Disjoint-set_data_structure
			http://en.wikipedia.org/wiki/Linked_list
			http://en.wikipedia.org/wiki/Unrolled_linked_list
			http://en.wikipedia.org/wiki/Association_list
			http://en.wikipedia.org/wiki/Skip_list
				In many situations, hash tables turn out to be more efficient than search trees or any other table lookup structure. For this reason, they are widely used in many kinds of computer software, particularly for associative arrays, database indexing, caches, and sets.
			http://en.wikipedia.org/wiki/Associative_array
				The most frequently used general purpose implementation of an associative array is with a hash table: an array of bindings, together with a hash function that maps each possible key into an array index
				Dictionaries may also be stored in binary search trees or in data structures specialized to a particular type of keys such as radix trees, tries, Judy arrays, or van Emde Boas trees, but these implementation methods are less efficient than hash tables as well as placing greater restrictions on the types of data that they can handle. The advantages of these alternative structures come from their ability to handle operations beyond the basic ones of an associative array, such as finding the binding whose key is the closest to a queried key, when the query is not itself present in the set of bindings.
			http://en.wikipedia.org/wiki/Hash_function
			http://en.wikipedia.org/wiki/Hash_table
			http://en.wikipedia.org/wiki/Map_(computer_science)
			http://en.wikipedia.org/wiki/Multimap
			http://en.wikipedia.org/wiki/Persistent_data_structure
			
			http://en.wikipedia.org/wiki/Persistent_data_structure
				a persistent data structure is a data structure that always preserves the previous version of itself when it is modified.
					Structures that are not persistent are called ephemeral.[1]
					A data structure is partially persistent if all versions can be accessed but only the newest version can be modified.
					The data structure is fully persistent if every version can be both accessed and modified.
					If there is also a meld or merge operation that can create a new version from two previous versions, the data structure is called confluently persistent.
			
		
		
		
		
		
		
		
		
		

			B-trees are particularly well-suited for implementation of databases, while
			compiler implementations usually use hash tables to look up identifiers.
			Storing and retrieving can be carried out on data stored in both main memory and in secondary memory.
				B-tree is a tree data structure that 
					keeps data sorted and 
						allows searches, sequential access, insertions, and deletions
						in logarithmic time.
					is a generalization of a binary search tree 
						in that a node can have   more than   two children
					Unlike self-balancing binary search trees,
						the B-tree is optimized for systems that read and write large blocks of data.
						It is commonly used in databases and filesystems.
									Average		Worst case 
							Space	O(n)		O(n) 
							Search	O(log n)	O(log n) 
							Insert	O(log n)	O(log n) 
							Delete	O(log n)	O(log n) 

						--------------------
						A SELF-BALANCING (or height-balanced) BINARY SEARCH TREE is 
							any node-based binary search tree that 
								automatically keeps its height (maximal number of levels below the root) small
								in the face of arbitrary item insertions and deletions.
							provide efficient implementations for mutable ordered lists, and can be used for other abstract data structures such as associative arrays, priority queues and sets.
							?? DOESNT work well with 
							?? 	nodes containing identical keys
							?? 	All tree operations preserve the order of the identical nodes within the tree, 
							?? 		which is a property similar to stable sorting algorithms.
							types
								AVL trees
								red-black trees
									red-black tree was found to have the smallest amount of performance variations.
								--------------------
								BINARY SEARCH TREE (BST, ordered or sorted binary tree) is a 
									node-based binary tree data structure where
										each node has a 
											comparable key (and an associated value) and 
											satisfies the restriction that 
												the key in any node is
													larger   than the keys in   all nodes in that node's left subtree and 
													smaller  than the keys in   all nodes in that node's right sub-tree
													(no duplicate nodes)
											has 0 to 2 child nodes.
									Main advantage of binary search trees is that 
										it remains ordered, 
										which provides   quicker search times   than many other data structures
									D. A. Heger (2004)[2] presented a performance comparison of binary search trees.
										Treap was found to have the best average performance, while
											In a treap (tree heap), each node also holds a (randomly chosen) priority and the parent node has higher priority than its children.
										Tango trees are trees optimized for fast searches.
									TYPES
										SPLAY TREE
											self-adjusting binary search tree with the additional property that
												recently accessed elements are quick to access again.
												(automatically moves frequently accessed elements nearer to the root.)
													All normal operations on a binary search tree are combined with one basic operation, called splaying.
													Splaying the tree for a certain element   rearranges the tree   so that 
														the element is placed at the root of the tree.
													One way to do this is to first perform a standard binary tree search for the element in question, and
														then use  tree rotations in a specific fashion  to bring the element to the top
													Alternatively, a top-down algorithm can combine 
														the  search  and the  tree reorganization  into a single phase.
											Works well with 
												nodes containing identical keys
													contrary to other types of self-balancing trees.
												Even with identical keys, performance remains amortized O(log n).
												All tree operations preserve the order of the identical nodes within the tree, 
													which is a property similar to stable sorting algorithms.
											The worst-case height—though unlikely—is O(n), with the average being O(log n)
											It performs basic operations such as insertion, look-up and removal in O(log n) amortized time.
												Particularly useful for implementing 
													caches and 
													garbage collection algorithms
											Operations
												Zig Step:
													Input:
														p is parent & the root of x
													Process:
														The tree is rotated on the edge between x and p.
													Output:
														x will be root and p will be on right sub-tree
													Zig steps exist to deal with the parity issue and 
														will be done only as the last step in a splay operation and 
														only when x has odd depth at the begin of the operation.
												Zig-zig Step:
													Input:
														p is parent & not the root of x
														[g is parent of p which is parent x (g is grand parent of x, and parent of p)]
														x and p are either
															both right children of g, or
															both left children of g
														tree is rotated on the edge joining p with its parent g (g <-> p), then
														tree is rotated on the edge joining x with p. (p <-> x)
													Output:
														x is parent of p which is parent g (reversed from input)
														p & g  are either
															both left children of x, or (reversed from input)
															both right children of x (reversed from input)
														(g is grand parent of x, and parent of p)
													Note that zig-zig steps are the only thing that differentiate splay trees from the rotate to root method introduced by Allen and Munro[3] prior to the introduction of splay trees.
												Zig-zag Step:
													Input:
														[g is parent of p which is parent x (g is grand parent of x, and parent of p)]
														p is not the root and 
															x is a right child  and  p is a left child, or
															vice versa.
													Process:
														tree is rotated on the edge between p and x (x <-> p), and then 
														tree is rotated on the resulting edge between x and g. (x <-> p)
													Output:
														x will parent of both p & g
														p will be on left  sub-tree   and,   g will be on right sub-tree, or
														p will be on right sub-tree   and,   g will be on left  sub-tree

													Input:
													Process:
													Output:



========================================================================
    CONSOLE APPLICATION : datastructures Project Overview
========================================================================

AppWizard has created this datastructures application for you.

This file contains a summary of what you will find in each of the files that
make up your datastructures application.


datastructures.vcxproj
    This is the main project file for VC++ projects generated using an Application Wizard.
    It contains information about the version of Visual C++ that generated the file, and
    information about the platforms, configurations, and project features selected with the
    Application Wizard.

datastructures.vcxproj.filters
    This is the filters file for VC++ projects generated using an Application Wizard. 
    It contains information about the association between the files in your project 
    and the filters. This association is used in the IDE to show grouping of files with
    similar extensions under a specific node (for e.g. ".cpp" files are associated with the
    "Source Files" filter).

datastructures.cpp
    This is the main application source file.

/////////////////////////////////////////////////////////////////////////////
Other standard files:

StdAfx.h, StdAfx.cpp
    These files are used to build a precompiled header (PCH) file
    named datastructures.pch and a precompiled types file named StdAfx.obj.

/////////////////////////////////////////////////////////////////////////////
Other notes:

AppWizard uses "TODO:" comments to indicate parts of the source code you
should add to or customize.

/////////////////////////////////////////////////////////////////////////////
