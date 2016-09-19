#include <iostream>
#include <sstream>  // stringstream
#include <fstream>  // ifstream
#include <limits>   // numeric_limits
#include <tuple>    // tuple
#include <vector>   // vector
#include <deque>    // deque
#include <stack>    // stack
#include <queue>    // priority_queue (greatest on top, by default, use greater for smallest on top)
#include <set>      // set
#include <unordered_set> // unordered_set
#include <map>      // map, multimap
#include <numeric>
#include <bitset>
#include <algorithm>  // min
#include <iomanip>  // setw, setfill
#include <cassert>  // assert
#include <functional> // greater

/*
#include <list>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstdint> // uint8_t
*/

using namespace std;

namespace ns_fenwik {

  // https://apps.topcoder.com/forums/?module=RevisionHistory&messageID=1352447
  //    https://apps.topcoder.com/forums/?module=Thread&threadID=715842&start=0&mc=8
  //        http://zobayer.blogspot.in/2013/11/various-usage-of-bit.html
  //    https://www.hackerearth.com/notes/binary-indexed-tree-made-easy-2/
  //    http://www.geeksforgeeks.org/binary-indexed-tree-or-fenwick-tree-2/
  //    https://www.topcoder.com/community/data-science/data-science-tutorials/binary-indexed-trees/

  template <class NType, class VBigType>
  class fenwik {

    NType N;
    vector<NType> v1;   // input array, with N+1 elements - element at index 0, is not used
    vector<NType> BIT;  // BIT array, with N+1 elements - element at index 0, is not used

  public:

    void print_array() {
      cout << setw(5) << "";
      for (int i = 1; i <= N; i++) { cout << setw(2) << i << " "; }      cout << endl;
      cout << setw(5) << "";
      for (int i = 1; i <= N; i++) { cout << setw(2) << v1[i] << " "; }      cout << endl;
    }

    void print_BIT_array() {
      cout << setw(5) << "";
      for (int i = 1; i <= N; i++) { cout << setw(2) << BIT[i] << " "; }      cout << endl;
    }

    void print_everything() {
      print_array();
      print_BIT_array();
    }

    fenwik(istream &cin_) {
      cin_ >> N;

      v1.resize(N + 1);
      v1[0] = -1; // dummy ele
      for (NType i = 1; i <= N; i++) {
        cin_ >> v1[i];
      }
    }

    void calc() {

      // create bit tree
      construct_BIT_array();

      cout << endl;
      // show results
      print_everything();

      // query a point - gives the aggregate result till the index in array/node in tree
      point_query_BIT__get_summary_of_all_till_index___from_values_at_index_and_any_left_siblings(6, true); // <= N 
      point_query_BIT__get_summary_of_all_till_index___from_values_at_index_and_any_left_siblings(7, true); // <= N 
      point_query_BIT__get_summary_of_all_till_index___from_values_at_index_and_any_left_siblings(8, true); // <= N 


      cout << endl;
      // update a point - updates the index in array and few more to it's right depending on index bits/node and updates it's parents in tree
      update_at_index_with_value___then_point_update_BIT(4, 1);

      // query a range - queries two ranges that start from begin, and some operation (like diff) gives result
      range_query_BIT__get_summary_of_all_between_from_and_to_indexes__uses_point_query_BIT(6, 7);

      cout << endl << endl;
      /* needs work */
      // udate a range - this seems to be different, depending on if there will be a point query or range query for the rest of the calls
      // range_update___needs_work(6, 7, 1);
    }

    void construct_BIT_array() {
      cout << "** construct BIT **  " << endl;

      print_array();

      BIT.resize(N + 1);
      for (int i = 1; i <= N; i++) { BIT[i] = 0; } // initialize BIT
      for (int i = 1; i <= N; i++) { point_update_BIT__add_subtract_append___by_update_at_index_and_above__with_a_value(i, v1[i], true); } // update BIT

      print_BIT_array();
    }

    void update_at_index_with_value___then_point_update_BIT(NType index_to_update1, NType value_to_update1, bool indent_print_everything = false) {
      cout << "** UPDATE **  [" << index_to_update1 << "] += " << value_to_update1 << endl;
      v1[index_to_update1] += value_to_update1;
      point_update_BIT__add_subtract_append___by_update_at_index_and_above__with_a_value(index_to_update1, value_to_update1, false);
      if (!indent_print_everything) { cout << endl; }
    }

    void point_update_BIT__add_subtract_append___by_update_at_index_and_above__with_a_value(NType index1, NType ori_arr_val1, bool indent_print_everything = false) {
      cout << setw(5) << "" << "** UPDATE BIT **  for [" << index1 << "] += " << ori_arr_val1;

      if (!indent_print_everything) { cout << endl; }
      else cout << setw(5) << "";

      // if (!indent_print_everything) { print_everything(); }

      // Traverse all ancestors and add 'ori_arr_val1'
      while (index1 <= N) {
        cout << index1 << "(" << ori_arr_val1 << ")  ";

        // Add 'ori_arr_val1' to current node of BI Tree
        BIT[index1] += ori_arr_val1;

        // Update index1 to that of parent in update View
        index1 += index1 & (-index1);
        ///////////// index1 += index1 & (index1 - 1);
      }
      cout << endl;

      if (!indent_print_everything) { print_everything(); }
    }

    VBigType point_query_BIT__get_summary_of_all_till_index___from_values_at_index_and_any_left_siblings(NType index1, bool indent_print_everything = false) {
      if (indent_print_everything) { cout << setw(2); } cout << "" << "** POINT QUERY **  [1," << index1 << "]"; if (!indent_print_everything) { cout << endl; }

      if (!indent_print_everything) { print_everything(); }

      //  7 has it's kind-of-left-siblings as 7, 6, 4
      //  8 has 8 only
      //  10 has 10 & 8

      VBigType sum = 0; // Iniialize result

      // Traverse ancestors of BIT[index1]
      if (!indent_print_everything) { cout << setw(2); ; cout << "" << "[ "; }
      while (index1 > 0) {
        if (!indent_print_everything) { cout << index1 << "(" << BIT[index1] << ") "; }

        // Add current element of BIT to sum
        sum += BIT[index1];

        // Move index1 to parent node in point_query View
        index1 -= index1 & (-index1);
        // parent index1 = remove last set bit from index1
        // index1 -= index1 & (index1 - 1);

        // i - ( i & (-i) ) will be same as
        // i & (i - 1)
      }

      if (!indent_print_everything) { cout << "]"; }
      cout << " = " << sum << endl;

      return sum;
    }

    VBigType range_query_BIT__get_summary_of_all_between_from_and_to_indexes__uses_point_query_BIT(NType from_index1, NType to_index1) {
      cout << "** RANGE QUERY **  [" << from_index1 << "," << to_index1 << "]" << endl;

      print_everything();

      //  7 has it's kind-of-left-siblings as 7, 6, 4
      //  8 has 8 only
      //  10 has 10 & 8

      VBigType sum1 = point_query_BIT__get_summary_of_all_till_index___from_values_at_index_and_any_left_siblings(to_index1, true); // <= N 
      VBigType sum2 = point_query_BIT__get_summary_of_all_till_index___from_values_at_index_and_any_left_siblings(from_index1 - 1, true); // <= N 

      VBigType sum = sum1 - sum2;
      cout << "    [1," << to_index1 << "]" << " - " << "[1," << from_index1 - 1 << "]" << " = " << sum << endl;

      return sum;
    }

    void range_update___needs_work(NType from_index_to_update1, NType to_index_to_update1, NType value_to_update1, bool indent_print_everything = false) {
      /* needs work */
      cout << "** RANGE UPDATE BIT **  [" << from_index_to_update1 << "," << to_index_to_update1 << "] = " << value_to_update1 << endl;
      // update [6,7] by 1
      //   = Update(6, 1)
      //        and Update(7 + 1, -1), i.e.Update(8, -1)

      // Update(6, 1)
      update_at_index_with_value___then_point_update_BIT(from_index_to_update1, value_to_update1, true);
      //        and Update(7 + 1, -1), i.e.Update(8, -1)
      update_at_index_with_value___then_point_update_BIT(to_index_to_update1 + 1, -value_to_update1);

      range_query_BIT__get_summary_of_all_between_from_and_to_indexes__uses_point_query_BIT(from_index_to_update1, to_index_to_update1);
    }
  };
}
