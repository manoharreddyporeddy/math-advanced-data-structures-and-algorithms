/*

Let L be the list, that contains N elements, say, from 0 to N-1
Make one pass from left to right of list L, from 0th index element to N-1 index element

Save the 1st element (0th index) in List S, continue the pass with 2nd element (1st index)
Also, SAVE, from which element this element came from (possibly index) (##), into list fromIndexL (for first element the value is -1) (#$)

While the pass is still on:
    If next is increasing of current
           SAVE into S, and then continue the pass, with next element in list (NOTE: S list has increasing elements)(#)
           Also, SAVE, from which element this next element came from (possibly index) (##), into list fromIndexL
    else:
           Find the next's position in S, using binary search (see, NOTE above, S list is ascending order)
           If S is found:
                   nothing to do
           else:
                   it is possible that next is not found, but you will find the element that is > next, say it nextOfnext
                   REPLACE nextOfnext with next, in S list (REPLACE is similar to SAVE above, #)
                   Also, SAVE, from which element this next element came from (possibly index), into list fromIndexL - similar to (##) above - this will be same as from which element nextOfnext came from

NOTE: From the above while, for each element (~N elements), there is binary search done (~ log N elements), so it is O(N * log N) runtime complexity

Now, we have 2 lists populated, list S, and list fromIndexL.
Take the last element of S list, print it, see from where it came from in fromIndexL list
    print that element, and see from where that element it came from in fromIndexL list
    continue this until we see from element as -1 (see #$ above)

We have printed longest increasing sequence
*/
