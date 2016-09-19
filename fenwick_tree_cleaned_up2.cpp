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

  template <class NType, class VType, class VBigType>
  class fenwik {

    NType N, K;
    // vector<VType> v1;   // input array, with N+1 elements - element at index 0, is not used
    // vector<vector<VType>> BIT;  // BIT array, with N+1 elements - element at index 0, is not used
    map<VType, vector<VType>> BIT;  // BIT array, with N+1 elements - element at index 0, is not used

    // vector1<vector<VType>> graph, graph_reverse_c_p;
    map<VType, vector<VType>> graph, graph_reverse_c_p;

    NType root;
    vector<NType> visited;
    VBigType sum; // Iniialize result

  public:

    /// CHECKKKKKK: KType is NType
    fenwik(istream &cin_, NType N1, NType K1) {
      sum = 0; // Iniialize result

      N = N1;
      K = K1;

      /*
      v1.resize(N + 1);
      v1[0] = -1; // dummy ele, at index 0
      for (NType i = 1; i <= N; i++) {
        v1[i] = i; // all values from 1 to N
      }*/

      ///////////// graph.resize(N + 1);    // element at index 0, is not used
      ///////////// graph_reverse_c_p.resize(N + 1);    // element at index 0, is not used
      visited.resize(N + 1);  // element at index 0, is not used

      NType v, u;
      for (NType i = 1; i <= N - 1; i++) {
        cin_ >> v >> u;
        graph[v].push_back(u);
        graph_reverse_c_p[u].push_back(v);
      }

      // find root
      NType node = 1;
      root = node;
      for (NType parent : graph_reverse_c_p[node]) {
        if (parent) { root = parent; }
        else { break; }
      }
      graph_reverse_c_p.clear();
      //////////////// graph_reverse_c_p.shrink_to_fit();
    }
    /*
    void print_array() {
      cout << setw(5) << "";
      for (int i = 1; i <= N; i++) { cout << setw(2) << i << " "; }      cout << endl;
      cout << setw(5) << "";
      for (int i = 1; i <= N; i++) { cout << setw(2) << v1[i] << " "; }      cout << endl;
    }

    void print_BIT_array() {
      cout << setw(5) << "";
      ///////// for (int i = 1; i <= N; i++) { cout << setw(2) << BIT[i] << " "; }      cout << endl;
    }

    void print_everything() {
      print_array();
      print_BIT_array();
    }*/

    // NOTE:   Must be KType, but is same as NType
    void calc() {

      // create bit tree
      construct_BIT_array___point_update_BIT(K);
      return;

      /*
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
      // needs work
      // udate a range - this seems to be different, depending on if there will be a point query or range query for the rest of the calls
      // range_update___needs_work(6, 7, 1);
      */
    }

    void construct_BIT_array___point_update_BIT(NType K) {
      // cout << "** construct BIT **  " << endl;

      /////////// print_array();

      /////////// BIT.resize(N + 1);

      /////////// BIT[0] = -1; // dummy ele, at index 0
      /////////// for (int i = 1; i <= N; i++) { BIT[i] = 0; } // initialize BIT

      dfs(root);
      graph.clear();
      ///////////// graph.shrink_to_fit();


      // for (int i = 1; i <= N; i++) { point_update_BIT__add_subtract_append___by_update_at_index_and_above__with_a_value(i, v1[i], true); } // update BIT

      // print_BIT_array();
      for (NType i : BIT[root]) {
        if (abs(i) <= K) {
          sum++;
        }
      }
      cout << sum;
    }

    void dfs(int node) {
      // if (!visited[node])
      {
        // cout << node << "->" << endl;
        visited[node] = true;
        for (int next : graph[node]) {

          if (!visited[next]) {
            point_update_BIT__add_subtract_append___by_update_at_index_and_above__with_a_value(node, next, true); // update BIT
            // cout << ":" << next;
            dfs(next);

            // move(BIT[next].begin(), BIT[next].end(), back_inserter(BIT[node]));
            // std::for_each(BIT[next].begin(), BIT[next].end(), [](int &child) { this.BIT[node].push_back(child - node) });
            NType diff = next - node;
            for (NType child : BIT[next]) {
              BIT[node].push_back(diff + child);
              if (abs(child) <= K) {
                sum++;
              }
            }
            
            ///////////// BIT[next].clear();
            BIT.erase(next);

            ///////////// graph[next].clear();
            ////// graph.erase(next);
            //graph.shrink_to_fit();
          }
        }

        graph.erase(node);
        ///////////graph[node].clear();
        // graph.shrink_to_fit();
        // graph.erase(node);

        // cout << endl << endl << endl;
      }
    }
    /*
      void update_at_index_with_value___then_point_update_BIT(NType index_to_update1, VType value_to_update1, bool indent_print_everything = false) {
        // cout << "** UPDATE **  [" << index_to_update1 << "] += " << value_to_update1 << endl;
        v1[index_to_update1] += value_to_update1;
        point_update_BIT__add_subtract_append___by_update_at_index_and_above__with_a_value(index_to_update1, value_to_update1, false);
        //////// if (!indent_print_everything) { cout << endl; }
      }
      */

      // index1 = node = parent
    void point_update_BIT__add_subtract_append___by_update_at_index_and_above__with_a_value(NType index1, NType ori_arr_val1, bool indent_print_everything = false) {
      ///cout << setw(5) << "" << "** UPDATE BIT **  for [" << index1 << "] += " << ori_arr_val1;

      ///// if (!indent_print_everything) { cout << endl; }
      ///// else cout << setw(5) << "";

      // if (!indent_print_everything) { print_everything(); }

      // BIT[index1].push_back(ori_arr_val1);
      BIT[index1].push_back(ori_arr_val1 - index1);




      /*
      // Traverse all ancestors and add 'ori_arr_val1'
      while (index1 <= N) {
        cout << index1 << "(" << ori_arr_val1 << ")  ";

        // Add 'ori_arr_val1' to current node of BI Tree
        ////////// BIT[index1] += ori_arr_val1;
        // BIT[index1].push_back(ori_arr_val1 - index1);
        BIT[index1].push_back(ori_arr_val1);

        // Update index1 to that of parent in update View
        index1 += index1 & (-index1);
        ///////////// index1 += index1 & (index1 - 1);
      }
      cout << endl;*/

      /////// if (!indent_print_everything) { print_everything(); }
    }

    /*
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
        // BIT[index1].push_back()

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

    void range_update___needs_work(NType from_index_to_update1, NType to_index_to_update1, VType value_to_update1, bool indent_print_everything = false) {
      // needs work
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
    */

  };
}
