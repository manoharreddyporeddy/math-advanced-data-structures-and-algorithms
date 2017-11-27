#include <iostream>
#include <sstream> // stringstream
#include <fstream> // ifstream
//
#include <limits> // numeric_limits
//
#include <tuple> // tuple

#include <vector> // vector
#include <stack>  // stack
#include <set> // set
#include <unordered_set> // unordered_set
#include <map> // map, multimap
#include <deque>

#include <bitset>

#include <algorithm> // min
//
#include <iomanip> // setw, setfill
#include <cassert> // assert

/*
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <numeric>
using namespace std;
*/

// #include <cmath>
// #include <cstdio>
// #include <cstdint> // uint8_t

using namespace std;




namespace ns_seg_tree {
  class STNode {
  public:
    // here it can be other than max, like sum, etc.
    int max_of_all_children, max_child_index;
    int sum_of_all_children;
    STNode() {
      max_of_all_children = 0;  // maximum value      // NOTE: 0 is assumed to be good for max value
      max_child_index = -1;     // extra information  // NOTE: -1 is good for index, remains -1 if unused child after building segtree
      sum_of_all_children = 0;
    }
  };
  class SegTree {
  public:
    vector<STNode> seg_tree;
    vector<bool> lazy_tree;
    vector<int> A;
    int N;

    SegTree(vector<int> &v1) {
      seg_tree.resize(2 * v1.size());   // CHECK, why others have 4 * ?
      lazy_tree.resize(2 * v1.size());

      N = v1.size();
      A.resize(N);
      for (int i = 0; i < N; i++) {
        A[i] = v1[i];
      }
    }

    // NOTE: Input is nodes
    // similar to parent = max(left,right)
    void Merge_CalcMergeLeftRightChildrenInfoCopyIntoOneUsuallyParent(
      STNode &parent_node,
      STNode &left_child_node, STNode &right_child_node
    ) {
      // Part1: CalcMergeLeftRightChildrenInfo
      // non-crucial trick - get the address of max child parent_label_index
      STNode *p_max_child_node = NULL;
      if (right_child_node.max_of_all_children > left_child_node.max_of_all_children) {
        p_max_child_node = &right_child_node;
      }
      else {
        p_max_child_node = &left_child_node;
      }

      // Part2: CopyIntoParent
      // put max in parent
      parent_node.max_of_all_children = (*p_max_child_node).max_of_all_children;
      parent_node.max_child_index = (*p_max_child_node).max_child_index;

      seg_tree[parent_label_index].sum_of_all_children +=
        right_child_node.sum_of_all_children;
      seg_tree[parent_label_index].sum_of_all_children +=
        left_child_node.sum_of_all_children;
    }

    // call   Build_TopDownBuildSegTree_SetLeafNodesAndMergePropogateInfoUpInSegTree(1, 0, N-1);
    // NOTE: Input is indexes
    // similar to top-down merge sort
    void Build_TopDownBuildSegTree_SetLeafNodesAndMergePropogateInfoUpInSegTree(
      int parent_label_index,                                               // index    doubles(doubles+1) each call
      int parent_interval_begin_index, int parent_interval_end_index  // interval halves      each call
    ) {
      // Part1: SetLeafNode(s)
      // leaf parent_label_index
      // base case:   single-element interval => last level => array element
      if (parent_interval_begin_index == parent_interval_end_index) {
        // interval begin and parent_interval_end_index indexes are same, so its leaf parent_label_index
        //    bottom most, level with leaves, it the array value itself
        // Update_UpdateLeafNodeAndMergePropogateInfoUpInSegTree max_of_all_children as the parent_label_index's value itself
        // Update_UpdateLeafNodeAndMergePropogateInfoUpInSegTree max_child_index as the parent_label_index's value's index
        seg_tree[parent_label_index].max_of_all_children = A[parent_interval_begin_index]; // here it's actual value, not max, sum or other
        seg_tree[parent_label_index].max_child_index = parent_interval_begin_index;
        return;
      }

      // Part21: MergePropogateInfoUpInSegTree - Going down the seg_tree
      // non-leaf parent_label_index

      // parent_interval_mid_index represents half number of children for this sub seg_tree rooted at parent_label_index
      int parent_interval_mid_index = (parent_interval_begin_index + parent_interval_end_index) / 2;

      // build left subtree rooted at 2 * parent_label_index (2*i, 1-based)
      Build_TopDownBuildSegTree_SetLeafNodesAndMergePropogateInfoUpInSegTree(
        2 * parent_label_index,           // (2*i, 1-based) left child
        parent_interval_begin_index, parent_interval_mid_index    // takes left half of child elements
      );

      // build right subtree rooted at 2 * parent_label_index +1 (2*i + 1, 1-based)
      Build_TopDownBuildSegTree_SetLeafNodesAndMergePropogateInfoUpInSegTree(
        2 * parent_label_index + 1,       // (2*i + 1, 1-based) left child
        parent_interval_mid_index + 1, parent_interval_end_index  // takes right half of child elements
      );

      // Part22: MergePropogateInfoUpInSegTree - Actual propogation for this node
      // combine result of left subtree and right subtree into current STNode
      //    propagate updated information up the seg_tree
      Merge_CalcMergeLeftRightChildrenInfoCopyIntoOneUsuallyParent(
        seg_tree[parent_label_index],
        seg_tree[2 * parent_label_index], seg_tree[2 * parent_label_index + 1]
      );
    }


    // -------- update --------------------

    // NOTE: Input is indexes
    // similar to binary search, find and update
    void Update_UpdateOneLeafNodeAndMergePropogateInfoUpInSegTree(
      int parent_label_index,
      int parent_interval_begin_index, int parent_interval_end_index,
      int array_position_index_to_find_and_update,
      int value
    ) {

      // **** if leaf node, update it **** 

      // Part1: UpdateLeafNode
      // leaf parent_label_index
      // base case:   single-element interval => last level => array element
      // Current parent_label_index is a leaf parent_label_index
      if (parent_interval_begin_index == parent_interval_end_index) {
        // interval begin and parent_interval_end_index indexes are same, so its leaf parent_label_index
        // point where the actual updation is required
        seg_tree[parent_label_index].max_of_all_children = value; // here it's actual value, not max, sum or other
                                                                  // max_child_index remains same, because it same parent_label_index, and its segment seg_tree => static structure
        return;
      }


      // Part21: MergePropogateInfoUpInSegTree - Going down the seg_tree to find position to update in seg_tree
      // non-leaf parent_label_index

      // If not a leaf parent_label_index, recur for children.
      // parent_interval_mid_index represents half number of children for this sub seg_tree rooted at parent_label_index
      int parent_interval_mid_index =
        (parent_interval_begin_index + parent_interval_end_index) / 2;


      // recur for children appropriately depending on position index we are looking for
      //    call update only for that side, where our position resides
      if (array_position_index_to_find_and_update <= parent_interval_mid_index) {

        // **** if non-leaf node, call update on left segment, if pos is to left of the mid **** 

        Update_UpdateOneLeafNodeAndMergePropogateInfoUpInSegTree(
          2 * parent_label_index,
          parent_interval_begin_index, parent_interval_mid_index,
          array_position_index_to_find_and_update,
          value);
      }
      else {

        // **** if non-leaf node, call update on left segment, if pos is to right of the mid **** 

        Update_UpdateOneLeafNodeAndMergePropogateInfoUpInSegTree(
          2 * parent_label_index + 1,
          parent_interval_mid_index + 1, parent_interval_end_index,
          array_position_index_to_find_and_update,
          value);
      }

      // **** merge info in the left segment & right segment, copy to itself **** 

      // Part22: MergePropogateInfoUpInSegTree - Actual propogation
      // combine result of left subtree and right subtree into current STNode: propagate updated information up the seg_tree
      // Use the result of bove children calls to update this parent_label_index
      Merge_CalcMergeLeftRightChildrenInfoCopyIntoOneUsuallyParent(
        seg_tree[parent_label_index],
        seg_tree[2 * parent_label_index], seg_tree[2 * parent_label_index + 1]
      );
    }


    // -------- update range --------------------

    // NOTE: Input is indexes
    // similar to binary search, find and update
    void UpdateRange_UpdateLeafNodesOfSegmentsWrtRangeLRAndMergePropogateInfoUpInSegTree(
      int parent_label_index,
      int parent_interval_begin_index, int parent_interval_end_index,
      int L, int R,
      int value
    ) {

      // **** if current segment is not in? the range LR we are looking return **** 
      if (
        (parent_interval_begin_index > parent_interval_end_index) ||
        (parent_interval_end_index < L) ||    // this can be recursive child's parent_interval_end_index interval
        (parent_interval_begin_index > R)     // this can be recursive child's begin interval
        ) {
        // out of our segment/range?
        //  not out required range
        return;
      }


      // **** current segment is at least partially in the range LR we are looking **** 


      // **** missing in lazy ****

      // Part1: UpdateSegment
      // * update each leaf node in the segment we are looking for *
      // base case:   single-element interval => last level => array element
      // Current parent_label_index is a leaf parent_label_index
      if (parent_interval_begin_index == parent_interval_end_index) {
        // Add the difference to current parent_label_index
        // CHECK: difference?
        seg_tree[parent_label_index].sum_of_all_children += value;

        return;
      }

      // **** if non-leaf node, update it **** 

      // Part21: MergePropogateInfoUpInSegTree - Going down the seg_tree to find position to update in seg_tree
      // non-leaf parent_label_index

      // If not a leaf parent_label_index, recur for children.
      // parent_interval_mid_index represents half number of children for this sub seg_tree rooted at parent_label_index
      int parent_interval_mid_index =
        (parent_interval_begin_index + parent_interval_end_index) / 2;


      // **** if non-leaf node, call update on left segment **** 

      //    call update for left range
      UpdateRange_UpdateLeafNodesOfSegmentsWrtRangeLRAndMergePropogateInfoUpInSegTree(
        2 * parent_label_index,
        parent_interval_begin_index, parent_interval_mid_index,
        L, R,
        value);


      // **** if non-leaf node, call update on right segment **** 

      //    call update for right range
      UpdateRange_UpdateLeafNodesOfSegmentsWrtRangeLRAndMergePropogateInfoUpInSegTree(
        2 * parent_label_index + 1,
        parent_interval_mid_index + 1, parent_interval_end_index,
        L, R,
        value);


      // **** merge info in the left segment & right segment, copy to itself **** 

      // Part22: MergePropogateInfoUpInSegTree - Actual propogation for this node
      // combine result of left subtree and right subtree into current STNode: propagate updated information up the seg_tree
      // Use the result of bove children calls to update this parent_label_index
      Merge_CalcMergeLeftRightChildrenInfoCopyIntoOneUsuallyParent(
        seg_tree[parent_label_index],
        seg_tree[2 * parent_label_index], seg_tree[2 * parent_label_index + 1]
      );
    }


    // -------- query range --------------------

    // Get information (say, max) for required interval
    // NOTE: Input is indexes
    // similar to binary search, find and update
    // NOTE: returns new parent_label_index created from copy of the interval nodes found
    STNode QueryRange_QueryLRFromOneOrTwoSegmentInfosCreateNodeAndReturn(
      int parent_label_index,
      int parent_interval_begin_index, int parent_interval_end_index,
      int L, int R
    ) {
      STNode ret;

      // **** if current segment is not in? the range LR we are looking return **** 

      if (
        (parent_interval_begin_index > parent_interval_end_index) ||
        (parent_interval_end_index < L) ||    // this can be recursive child's parent_interval_end_index interval
        (parent_interval_begin_index > R)     // this can be recursive child's begin interval
        ) {
        // out of our segment/range?
        //  not out required range
        return ret; // return 0;
      }


      // **** current segment is at least partially in the range LR we are looking **** 

      // current segment lies completely in the required interval i.e [L,R]
      //    <= possible because, partially on left seg_tree, partially on right subtree
      //    only 1 will satisfy
      if (
        L <= parent_interval_begin_index &&
        /**/ parent_interval_end_index <= R
        ) {

        // **** current segment is fully within required range, return node representing segment ****

        return seg_tree[parent_label_index];
      }


      // **** if current segment is not fully within required range ****

      // parent_interval_mid_index represents half number of children for this sub seg_tree rooted at parent_label_index
      int parent_interval_mid_index =
        (parent_interval_begin_index + parent_interval_end_index) / 2;


      // **** if current segment is not fully within required range, call query on on left segment ****

      // extracting information from the left if left segment contains part of our interval
      // NOTE: this is a copy of parent_label_index in segtree
      // query left child
      STNode left =
        QueryRange_QueryLRFromOneOrTwoSegmentInfosCreateNodeAndReturn(
          2 * parent_label_index,
          parent_interval_begin_index, parent_interval_mid_index,
          L, R);

      // **** if current segment is not fully within required range, call query on on right segment ****

      // extracting information from the right if right segment contains part of our interval
      // NOTE: this is a copy of parent_label_index in segtree
      // query right child
      STNode right =
        QueryRange_QueryLRFromOneOrTwoSegmentInfosCreateNodeAndReturn(
          2 * parent_label_index + 1,
          parent_interval_mid_index + 1, parent_interval_end_index,
          L, R);


      // **** merge info in the left segment if any & right segment if any, copy to a node, return **** 

      // combining left and right information
      // NOTE: this is a merging of copy of nodes in segtree
      Merge_CalcMergeLeftRightChildrenInfoCopyIntoOneUsuallyParent(ret, left, right);
      return ret;
    }


    // -------- update range - lazy --------------------

    /*
    if segments is found to be part or full of LR
    then update node representing LR with given value, and mark children as lazy

    if a node was found to be updated lazily
    then update node representing LR with given lazy-value, and mark children as lazy

    if a node was updated, propoate the changes up to root
    ---
    leave the children of nodes, to update lazily in future
    */
    void UpdateRangeLazy_UpdateOneOrTwoSegmentInfoNodesOfSegmentsWrtRangeLRAndMergePropogateInfoUpInSegTree_LeaveChildrenToUpdateLazily(
      int parent_label_index,
      int parent_interval_begin_index, int parent_interval_end_index,
      int L, int R,
      int value
    ) {


      // **** only in lazy ****

      if (lazy_tree[parent_label_index] != 0) {

        // **** this node at parent_label_index has a lazy value, so needs to be updated

        // **** get the value from lazy array to update it now ****
        auto lazy_value = lazy_tree[parent_label_index];

        // update this node
        seg_tree[parent_label_index].sum_of_all_children +=
          (parent_interval_end_index - parent_interval_begin_index + 1) * lazy_value;

        // **** if children exist, mark them to be updated in future when required (lazy) ****
        // **** CHECK: future is when? ****
        if (parent_interval_begin_index != parent_interval_end_index) {
          // Not a leaf node, mark children to update lazy later
          lazy_tree[parent_label_index * 2] += lazy_value;
          lazy_tree[parent_label_index * 2 + 1] += lazy_value;
        }

        // **** update competed, remove lazy value for this node at parent_label_index
        lazy_tree[parent_label_index] = 0;
      }


      // **** if current segment is not in? the range LR we are looking return **** 

      if (
        (parent_interval_begin_index > parent_interval_end_index) ||
        (parent_interval_end_index < L) ||    // this can be recursive child's parent_interval_end_index interval  // CHECK: what about L < begin?   // from input error
        (parent_interval_begin_index > R)     // this can be recursive child's begin interval // CHECK: what about R > parent_interval_end_index?     // from input error
        ) {
        // out of our segment/range?
        //  not out required range
        return;
      }


      // **** current segment is at least partially in the range LR we are looking **** 

      // current segment lies completely in the required interval i.e [L,R]
      //    <= possible because, partially on left seg_tree, partially on right subtree
      //    only 1 will satisfy
      if (
        L <= parent_interval_begin_index &&
        /**/ parent_interval_end_index <= R
        ) {

        // **** current segment is fully within required range, update it ****

        seg_tree[parent_label_index].sum_of_all_children +=
          (parent_interval_end_index - parent_interval_begin_index + 1) * value;

        // **** only in lazy ****

        // **** if children exist, mark them to be updated in future when required (lazy) ****
        // **** CHECK: future is when? ****
        if (parent_interval_begin_index != parent_interval_end_index) {
          // Not a leaf node, mark children to update lazy
          lazy_tree[parent_label_index * 2] += value;
          lazy_tree[parent_label_index * 2 + 1] += value;
        }
        return;
      }


      // **** current segment is Not fully within required range ****

      // Part21: MergePropogateInfoUpInSegTree - Going down the seg_tree to find position to update in seg_tree
      // non-leaf parent_label_index

      // If not a leaf parent_label_index, recur for children.
      // parent_interval_mid_index represents half number of children for this sub seg_tree rooted at parent_label_index
      int parent_interval_mid_index =
        (parent_interval_begin_index + parent_interval_end_index) / 2;


      // **** current segment is Not fully within required range, call update on left segment ****

      //    call update for left range
      UpdateRangeLazy_UpdateOneOrTwoSegmentInfoNodesOfSegmentsWrtRangeLRAndMergePropogateInfoUpInSegTree_LeaveChildrenToUpdateLazily(
        2 * parent_label_index,
        parent_interval_begin_index, parent_interval_mid_index,
        L, R,
        value);


      // **** current segment is Not fully within required range, call update on right segment ****

      //    call update for right range
      UpdateRangeLazy_UpdateOneOrTwoSegmentInfoNodesOfSegmentsWrtRangeLRAndMergePropogateInfoUpInSegTree_LeaveChildrenToUpdateLazily(
        2 * parent_label_index + 1,
        parent_interval_mid_index + 1, parent_interval_end_index,
        L, R,
        value);


      // **** merge info in the left segment & right segment, copy to itself **** 

      // Part22: MergePropogateInfoUpInSegTree - Actual propogation for this node
      // combine result of left subtree and right subtree into current STNode: propagate updated information up the seg_tree
      // Use the result of bove children calls to update this parent_label_index
      Merge_CalcMergeLeftRightChildrenInfoCopyIntoOneUsuallyParent(
        seg_tree[parent_label_index],
        seg_tree[2 * parent_label_index], seg_tree[2 * parent_label_index + 1]
      );
    }


    // -------- query range - lazy --------------------

    // Get information (say, max) for required interval
    // NOTE: Input is indexes
    // similar to binary search, find and update
    // NOTE: returns new parent_label_index created from copy of the interval nodes found
    STNode QueryRangeLazy_QueryOneOrTwoIntervalInfosCreateNodeAndReturn(
      int parent_label_index,
      int parent_interval_begin_index, int parent_interval_end_index,
      int L, int R
    ) {
      STNode ret;

      // **** if current segment is not in? the range LR we are looking return **** 

      if (
        (parent_interval_begin_index > parent_interval_end_index) ||
        (parent_interval_end_index < L) ||    // this can be recursive child's parent_interval_end_index interval  // CHECK: what about L < begin?   // from input error
        (parent_interval_begin_index > R)     // this can be recursive child's begin interval // CHECK: what about R > parent_interval_end_index?     // from input error
        ) {
        // out of our segment/range?
        //  not out required range
        return ret; // return 0;
      }


      // **** current segment is at least partially in the range LR we are looking **** 

      // **** only in lazy ****

      if (lazy_tree[parent_label_index] != 0) {

        // **** this node at parent_label_index has a lazy value, so needs to be updated

        // **** get the value from lazy array to update it now ****
        auto lazy_value = lazy_tree[parent_label_index];

        // update this node
        seg_tree[parent_label_index].sum_of_all_children +=
          (parent_interval_end_index - parent_interval_begin_index + 1) * lazy_value;

        // **** if children exist, mark them to be updated in future when required (lazy) ****
        // **** CHECK: future is when? ****
        if (parent_interval_begin_index != parent_interval_end_index) {
          // Not a leaf node, mark children to update lazy
          lazy_tree[parent_label_index * 2] += lazy_value;
          lazy_tree[parent_label_index * 2 + 1] += lazy_value;
        }

        // **** update competed, remove lazy value for this node at parent_label_index
        lazy_tree[parent_label_index] = 0;
      }


      // **** current segment is at least partially in the range LR we are looking **** 

      // current segment lies completely in the required interval i.e [L,R]
      //    <= possible because, partially on left seg_tree, partially on right subtree
      //    only 1 will satisfy
      if (
        L <= parent_interval_begin_index &&
        /**/ parent_interval_end_index <= R
        ) {

        // **** current segment is fully within required range, return node representing segment ****

        return seg_tree[parent_label_index];
      }


      // **** if current segment is not fully within required range ****

      // parent_interval_mid_index represents half number of children for this sub seg_tree rooted at parent_label_index
      int parent_interval_mid_index =
        (parent_interval_begin_index + parent_interval_end_index) / 2;


      // **** if current segment is not fully within required range, call query on on left segment ****

      // extracting information from the left if left segment contains part of our interval
      // NOTE: this is a copy of parent_label_index in segtree
      // query left child
      STNode left =
        QueryRangeLazy_QueryOneOrTwoIntervalInfosCreateNodeAndReturn(
          2 * parent_label_index,
          parent_interval_begin_index, parent_interval_mid_index,
          L, R);

      // **** if current segment is not fully within required range, call query on on right segment ****

      // extracting information from the right if right segment contains part of our interval
      // NOTE: this is a copy of parent_label_index in segtree
      // query right child
      STNode right =
        QueryRangeLazy_QueryOneOrTwoIntervalInfosCreateNodeAndReturn(
          2 * parent_label_index + 1,
          parent_interval_mid_index + 1, parent_interval_end_index,
          L, R);


      // **** merge info in the left segment if any & right segment if any, copy to a node, return **** 

      // combining left and right information
      // NOTE: this is a merging of copy of nodes in segtree
      Merge_CalcMergeLeftRightChildrenInfoCopyIntoOneUsuallyParent(ret, left, right);
      return ret;
    }

  };
};


#define NType int
#define VType int
// parent_interval_begin_index solve
void Solve_ChangingBits(bitset<100000> &A, bitset<100000> &B, int &N) {
  // void Solve_ChangingBits(vector<VType> &vMt1, vector<VType> &vD1, NType &N) { // sometimes // vector<VType> &v1, NType &N  // multimap<NType, VType> &mm1 // , NType &K // vector<VType> &v1, vector<VType> &v2
  // void Solve_TaskScheduling(string &s, NType N, VType A, VType B) {
    // #define NType int
    // #define VType int

    // cout << endl << endl << s << " " << N << " " << A << " " << B << endl;

  // int max_overshoot = 0;
  // stack<int> st1_max_overshoots;

  set<pair<VType, VType>> s1;
  for (NType i = 0; i < N; i++) {
    // s1.insert({ vD1[i], vMt1[i] });
  }

  string str;
}
// INPUT input
void Input_ChangingBits() {
  stringstream ss;

  ss << "5 5" << endl;

  ss << "00000" << endl;
  ss << "11111" << endl;

  ss << "set_a 0 1" << endl;
  ss << "get_c 5" << endl;
  ss << "get_c 1" << endl;
  ss << "set_b 2 0" << endl;
  ss << "get_c 5" << endl;

  // #define MYTESTING
#ifdef MYTESTING
  istream &cin_ = ss;   // cin_.ignore(numeric_limits<streamsize>::max(), '\n'); // skip bad input till new line
  // ifstream ifs1("task_sheduling_input04_small.txt");    istream &cin_ = ifs1;
#else
  istream &cin_ = cin;
#endif

#define MULTIPLE_TESTS1
#ifdef MULTIPLE_TESTS
  long long T; cin_ >> T; while (T--)
#endif
  {
    NType N; cin_ >> N;
    NType Q; cin_ >> Q;
    // NType A; cin_ >> A;
    // NType B; cin_ >> B;
    // NType M; cin_ >> M;
    // NType K; cin_ >> K;
    // short diff; cin_ >> diff;
    // string s; cin_ >> s;

    // VType t_ele;
    // VType t_ele1, t_ele2;

    // vector<vector<VType>> v1(N, vector<VType>(M));
    // vector<VType> v1(N + 1);  // NOTE: v1(N), v1(N+1), v1(M) sometimes
    // vector<VType> v2(N);  // NOTE: v1(N), v1(N+1), v1(M) sometimes
    // multimap<NType, VType> mm1;

    // vector<VType> v1(N), v2(N);

    // for (NType i = 0; i < N; i++) {
      // for (NType j = 0; j < M; j++) {
      // cin_ >> t_ele;  v1[i][j] = t_ele;
      // cin_ >> t_ele;  mm1.insert({ t_ele, i });
      // cin_ >> t_ele1 >> t_ele2;  v1[i] = t_ele1; v2[i] = t_ele2;
      // cin_ >> t_ele1 >> t_ele2;  mm1.insert({ t_ele1, t_ele2 });
    // }

    string s1;    cin >> s1;    bitset<100000> A(s1);
    string s2;    cin >> s2;    bitset<100000> B(s2);

    for (NType i = 0; i < Q; i++) {
      Solve_ChangingBits(A, B, N);
      cout << endl;
    }
  }
}

int main(int argc, char** argv) {
  Input_ChangingBits();
  return 0;
}
