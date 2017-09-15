// samplecpphr2.cpp : Defines the entry point for the console application.
//
// #include "stdafx.h"


using namespace std;

#include <algorithm>  // min
#include <bitset>
#include <cassert>  // assert
#include <cmath>
#include <csignal>
#include <deque>    // deque
#include <fstream>  // ifstream
#include <functional> // greater
#include <iomanip>  // setw, setfill
#include <iostream>
#include <limits>   // numeric_limits
#include <map>      // map, multimap
#include <numeric>
#include <queue>    // priority_queue (greatest on top, by default, use greater for smallest on top)
#include <set>      // set
#include <sstream>  // stringstream
#include <stack>    // stack
#include <tuple>    // tuple
#include <unordered_map>
#include <unordered_set> // unordered_set
#include <vector>   // vector


bool ON = 1;
bool OFF = 0;

#ifdef DEBUGG
bool DEBUG_MODE = ON;
bool LOGS = ON;
#else
bool DEBUG_MODE = OFF;
bool LOGS = OFF;
#endif

template <typename Arg, typename... Args>
void debug(Arg&& arg, Args&&... args) {

	if (LOGS) {
		std::ostream& out = std::cout;
		out << std::forward<Arg>(arg);
		using expander = int[];
		(

			void)expander {
			0, (void(out << ' ' << std::forward<Args>(args)), 0)...
		};
	}
}


// -----------------------------------
// -----------------------------------
// -----------------------------------

// #define PTypeVal short // 1 to 50
//
//#define NTypeValue int // 1 to 10^5
//#define MTypeValue int // 1 to 10^5
//#define XTypeValue int // 1 to 10^9
//#define VTypeValue int // 0 to 10^6
//#define TypeValue unsigned long long // 0 to 10^6
//#define PTypeVal unsigned long long
//#define VTypeVal unsigned short // long long
//#define PTypeVal long long
//#define DTypeVal long long
//#define TTypeVal unsigned long long
//#define LTypeVal unsigned long long
//#define SumOfLTypeVal unsigned long long

#define PTypeVal unsigned long long
#define NTypeVal long
#define SizeT unsigned int
#define VeryLargeTypeVal unsigned long long
// -----------------------------------


template <class NType, class VBigType>
class fenwik {

	// https://apps.topcoder.com/forums/?module=RevisionHistory&messageID=1352447
	//    https://apps.topcoder.com/forums/?module=Thread&threadID=715842&start=0&mc=8
	//        http://zobayer.blogspot.in/2013/11/various-usage-of-bit.html
	//    https://www.hackerearth.com/notes/binary-indexed-tree-made-easy-2/
	//    http://www.geeksforgeeks.org/binary-indexed-tree-or-fenwick-tree-2/
	//    https://www.topcoder.com/community/data-science/data-science-tutorials/binary-indexed-trees/

	NType N;
	vector<NType> v1;   // input array, with N+1 elements - element at index 0, is not used
	vector<NType> BITree;  // BITree array, with N+1 elements - element at index 0, is not used

public:

	fenwik(istream &cin_) {
		cin_ >> N;

		// get A
		v1.resize(N + 1);
		for (NType i = 1; i <= N; i++) {
			cin_ >> v1[i];
		}

		// initialize BITree with 0
		BITree.resize(N + 1);
		for (int i = 1; i <= N; i++) { BITree[i] = 0; }
	}

	void print_array_indexes() {
		stringstream output;
		output << "index:       ";
		for (int i = 1; i <= N; i++) { output << left << setw(4) << i; }
		cout << output.str() << endl;
	}

	void print_array() {
		stringstream output;
		output << "Ai   :       ";
		for (int i = 1; i <= N; i++) { output << left << setw(4) << v1[i]; }
		cout << output.str() << endl;
	}

	void print_BIT_indexes() {
		stringstream output;
		output << "BIT index:   ";
		for (int i = 1; i <= N; i++) { output << left << setw(4) << i; }
		cout << output.str() << endl;
	}

	void print_BIT_array() {
		stringstream output;
		output << "BITArray:    ";
		for (int i = 1; i <= N; i++) { output << left << setw(4) << BITree[i]; }
		cout << output.str() << endl;
	}

	void doMain() {
		cout << right << setw(21 + 77 + 23 + 17);
		print_array_indexes();
		cout << right << setw(21 + 77 + 23 + 17);
		print_array();

		// create bit tree
		construct_BIT_array();
		cout << endl;

		// query a point - gives the aggregate result till the index in array/node in tree

		cout << "** queries to BITree **  " << endl;
		cout << right << setw(21 + 77 + 23 + 17);
		print_BIT_indexes();
		cout << right << setw(21 + 77 + 23 + 17);
		print_BIT_array();
		for (int i = 1; i <= N; i++) {
			cout << left << setw(77);
			VBigType sum = query_point_BITarray(i); // <= N 
			cout << endl;
		}
		cout << endl;



		cout << "** update array, refresh update BITree **  " << endl;

		cout << right << setw(181);
		print_array_indexes();
		cout << right << setw(181);
		print_array();
		cout << right << setw(181);
		print_BIT_array();
		cout << endl;

		{
			stringstream output;

			// update a point - updates the index in array and few more to it's right depending on index bits/node and updates it's parents in tree
			output << "  update array at [" << 4 << "] with " << 1 << "      ";
			cout << left << setw(21) << output.str();

			cout << left << setw(86);
			update_array__refresh_BITtree(4, 1);

			cout << left << setw(1);
			print_array();
			cout << right << setw(181);
			print_BIT_array();
			cout << endl;
		}

		{
			stringstream output;

			output << "  update array at [" << 5 << "] with " << 3 << "      ";
			cout << left << setw(21) << output.str();

			cout << left << setw(86);
			update_array__refresh_BITtree(5, 3);

			cout << left << setw(91);
			print_array();
			cout << right << setw(181);
			print_BIT_array();
			cout << endl;
		}



		// query a range - queries two ranges that start from begin, and some operation (like diff) gives result
		query_range_BITarray(6, 7);

		return;

		cout << endl << endl;
		/* needs work */
		// udate a range - this seems to be different, depending on if there will be a point query or range query for the rest of the calls
		// range_update___needs_work(6, 7, 1);
	}

	void construct_BIT_array() {
		cout << endl;
		cout << "** construct BITree **  " << endl;
		cout << "acummulate each value Ai, at corresponding index in the BITarray, then prorate to all parents: " << endl;
		cout << "** updates to BITree **  " << endl;

		cout << right << setw(21 + 77 + 23 + 17);
		print_BIT_indexes();
		for (int i = 1; i <= N; i++) {
			cout << left << setw(77);
			update_point_BITarray(i, v1[i]);
			cout << left << setw(21);
			print_BIT_array();
		}

	}




	/*
bit array indexes
update operations
									 32(?  but >N)
									 /\
								   /     \
								 /          \
							   /               \
							 /                    \
						  16                       ?
						  /\
						/    \
					 /         \
				  /              \
			   /                   \
			  8                      12
		   /  |  \                  /  \
		 /    |    \              /     \
	   4      6     7            10      11
	 /  \      \                   \
   2     3      5                   9
	\
	 1

	*/

	// point update BIT  add subtract append   by update at index and above  with a value
	void update_point_BITarray(NType ib, NType Ai) {
		// Traverse all ancestors and add 'Ai'
		stringstream output;
		output << "update [" << ib << "]=" << Ai << "    accummulate: " << Ai << " to BITeles at  ";

		while (ib <= N) {
			output << "[" << ib << "]" << ", ";

			// Add Ai at ib, in BITtree
			BITree[ib] += Ai;

			// get parent ib, in update View --- to add to all parents too
			ib += ib & (-ib);
		}

		cout << output.str();
	}




	/*
bit array indexes
query operations

					   0 (DUMMY NODE)
				 /     /\    \                   \
			  /      /    \      \                    \
		   /       /       \         \                     \
		 1       2         4          8                   16(?)
				/         / \      /  |  \
			   3        5    6    9   10    12
						|             |
						7             11

	*/


	// point query BIT  get summary of all till index   from values at index and any left siblings
	VBigType query_point_BITarray(NType ib) {

		stringstream output;
		output << "get [" << ib << "] " << "    accummulate from: ";

		VBigType sum = 0; // Iniialize result

		// Traverse ancestors of BITree[ib]
		while (ib > 0) {
			output << right << setw(4) << "[" << ib << "]" << "(" << BITree[ib] << ") " << ", ";

			// Add current element of BITree to sum
			sum += BITree[ib];

			// Move ib to parent node in point_query View
			ib -= ib & (-ib);		// parent ib = remove last set bit from ib

			// ib -= ib & (ib - 1);
			// i - ( i & (-i) ) will be same as i & (i - 1)
		}

		cout << output.str();

		stringstream output2;
		output2 << right << setw(13) << " = " << sum;
		cout << output2.str();

		return sum;
	}

	// update at index with value  then point update BIT
	void update_array__refresh_BITtree(NType i, NType Ai) {
		v1[i] += Ai;

		update_point_BITarray(i, Ai);
	}

	// range query BIT  get summary of all between from and to indexes  uses point query BIT
	VBigType query_range_BITarray(NType ib_from, NType ib_to) {
		cout
			<< "[" << ib_from << ", " << ib_to << "]"
			<< " = [1, " << ib_to << "]" << " - " << "[1, " << ib_from - 1 << "]";

		print_BIT_array();

		//  7 has it's kind-of-left-siblings as 7, 6, 4
		//  8 has 8 only
		//  10 has 10 & 8

		// cout << left << setw(55) << output.str();

		cout << left << setw(77);
		VBigType sum1 = query_point_BITarray(ib_to); // <= N 
		cout << endl;

		cout << left << setw(77);
		VBigType sum2 = query_point_BITarray(ib_from - 1); // <= N 
		cout << endl;

		VBigType sum = sum1 - sum2;

		cout << left << setw(91) << "    " << sum << endl << endl << endl;

		return sum;
	}

	void range_update___needs_work(NType from_index_to_update1, NType to_index_to_update1, NType Ai, bool indent_print_everything = false) {
		/* needs work */
		cout << "** RANGE UPDATE BITree **  [" << from_index_to_update1 << "," << to_index_to_update1 << "] = " << Ai << endl;
		// update [6,7] by 1
		//   = Update(6, 1)
		//        and Update(7 + 1, -1), i.e.Update(8, -1)

		// Update(6, 1)
		update_array__refresh_BITtree(from_index_to_update1, Ai);
		//        and Update(7 + 1, -1), i.e.Update(8, -1)
		update_array__refresh_BITtree(to_index_to_update1 + 1, -Ai);

		query_range_BITarray(from_index_to_update1, to_index_to_update1);
	}
};


// testsss
#define ReturnCountTypeValue char
vector < pair < vector<string>, vector<ReturnCountTypeValue >>> tests = {
	{
		{
			"12",
			"2 1 1   3 2 3   4 5 6   7 8 9"
		},
		{ 0, 0, 0, 0, 0, 0, 0, 0 } // 4(new) 3 (old)
	}
};

template <class NType, class PType>
class ClsMain1 {
	NType N;
	deque<PType> p1;
public:

	ClsMain1() {
	}

	void doMain(istream &cin) {
		fenwik <NTypeVal, VeryLargeTypeVal> f1(cin);
		f1.doMain();
	}
};

// template <class NType, class VType, class PType, class DType>

template <class NType, class PType>
class Cls1 {

	//    HNType n;
	//    MType m;
	// deque <pair<VType, NType > > p1;
	//    XType x;
	//    string S;
	//    LenType k;
	//    TType type;
	//    HVType v;
	//    VType v;
	//    PType P;
	//    DType D;
	//    KType K;
	// Heap<NType, pair<LType, TType>> h1;
	// multiset<HVType> se1;
	// deque<HVType> p1;

public:

	Cls1() {
		// LOGS = OFF;
	}


	vector <ReturnCountTypeValue> testFunction(istream & cin) {
		// debug("testFunction - begin\n\n");
		vector <ReturnCountTypeValue> res;
		// --------------------

		// LOGS = 0;



		ClsMain1 <NType, PType> p1;
		p1.doMain(cin);



		auto actual_result = 0;
		res.push_back(actual_result);

		return res;
	}

};


int main() {

	if (DEBUG_MODE) {

		for (unsigned long i = 0; i < tests.size(); i++) {
			// debug("----------------------- input getting ready ----------------------------- ", "\n");
			auto input = tests[i].first;
			auto expected_output = tests[i].second;

			std::stringstream ss;
			istream &cin = ss;

			for (size_t i = 0; i < input.size(); i++) {
				// debug(input[i], "\n");
				ss << input[i] << endl;
			}



			// debug("----------------------- input ready ----------------------------- ", "\n");

			Cls1<NTypeVal, PTypeVal> o;
			// Cls1<NTypeVal, VTypeVal, PTypeVal, DTypeVal> o;
			// Cls1<NTypeVal, LTypeVal> o;
			// auto actual_result = o.testFunction(cin, q)[0];
			auto actual_result = o.testFunction(cin)[0];

			//            for (PTypeVal k = 0; k < q; k++) {
			//            Cls1<NTypeVal, LTypeVal, TTypeVal> o;
			//                // // debug("\tactual_result ", actual_result, " ", "expected_output ", expected_output[k], "\n");
			//
			//                // assert(actual_result == expected_output[k]);
			//            }

			// break;
		}
	}
	else {

		//        PTypeVal q;
		//        cin >>q;

		Cls1<NTypeVal, PTypeVal> o;
		// Cls1<NTypeVal, VTypeVal, PTypeVal, DTypeVal> o;
		// Cls1<NTypeVal, LTypeVal> o;
		o.testFunction(cin);

	}

	return 0;
}
