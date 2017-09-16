//
// beautiful code
//

#include "stdafx.h"

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

using namespace std;


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

template <typename T>
ostream & operator<<(ostream &o1, const vector<T> &v1) {
	for (auto it = v1.begin(); it != v1.end(); it++) {
		o1 << setw(4) << *it << " ";
	}
	return o1;
}

template <typename T>
vector <T> range(T N1, T N2) {
	vector<T> numbers(N2 - N1);
	iota(numbers.begin(), numbers.end(), N1);
	return numbers;
}

template <typename T>
vector <T> zero_till(T N) {
	vector<T> numbers(N);
	iota(numbers.begin(), numbers.end(), 0);
	return numbers;
}

template <typename T>
vector <T> one_till(T N) {
	vector<T> numbers(N);
	iota(numbers.begin(), numbers.end(), 1);
	return numbers;
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

// #define PTypeVal unsigned long long
#define NTypeVal long
#define EleTypeVal long long
// #define SizeT unsigned int
// #define VeryLargeTypeVal unsigned long long
// -----------------------------------


struct Node
{
	NTypeVal i;
	EleTypeVal d;
	Node *l, *r, *p;	// left, right, parent
};


template <class NType, class EleType>
class cartesian_tree {

	// https://apps.topcoder.com/forums/?module=RevisionHistory&messageID=1352447
	//    https://apps.topcoder.com/forums/?module=Thread&threadID=715842&start=0&mc=8
	//        http://zobayer.blogspot.in/2013/11/various-usage-of-bit.html
	//    https://www.hackerearth.com/notes/binary-indexed-tree-made-easy-2/
	//    http://www.geeksforgeeks.org/binary-indexed-tree-or-fenwick-tree-2/
	//    https://www.topcoder.com/community/data-science/data-science-tutorials/binary-indexed-trees/

	NType N;
	vector<NType> v1;   // input array, with N+1 elements - element at index 0, is not used
	vector<NType> BITree;  // BITree array, with N+1 elements - element at index 0, is not used

	struct Node* getNewNode(EleType &data1, NType &index1) {
		struct Node* temp = new Node();

		temp->i = index1;
		temp->d = data1;

		temp->l = NULL;
		temp->r = NULL;
		temp->p = NULL;

		return temp;
	}

	struct Node *root = NULL, *right_most = NULL;

public:

	cartesian_tree(istream &cin) {
		cin >> N;

		///////// cout << one_till(N) << endl;
		// cout << v1 << endl;

		EleType Ai;
		for (NType i = 1; i <= N; i++) {
			cin >> Ai;

			///////// cout << setw(4) << Ai << " ";

			auto new1 = getNewNode(Ai, i);
			if (root == NULL) {
				root = new1;
				right_most = new1;
			}
			else {
				while (right_most->r) {
					right_most = right_most->r;
				}


				struct Node* temp = right_most;
				while (temp &&
					(temp->d >= new1->d)) {
					temp = temp->p;
				}

				if (temp) {
					new1->l = temp->r;
					temp->r = new1;


					new1->p = temp;
					if (new1->l) {
						new1->l->p = new1;
					}

					right_most = new1;
				}
				else {
					new1->l = root;
					root = new1;

					if (new1->l) {
						new1->l->p = new1;
					}

					right_most = root;
				}

			}
		}
		///////// cout << endl;
	}

	void print_array_indexes() {
		stringstream output;
		output << "index:       ";
		for (int i = 1; i <= N; i++) { output << left << setw(4) << i; }
		cout << output.str() << endl;
	}
  
};


// testsss
#define ReturnCountTypeValue char
vector < pair < vector<string>, vector<ReturnCountTypeValue >>> tests = {
	/*	{
			{
				"5",
				"5 10 40 30 28"
			},
			{ 0, 0, 0, 0, 0, 0, 0, 0 } // 4(new) 3 (old)
		}, */
		{
			{
				"12",
					"9 3  7 1 8  12 12 10 20  15 18 5"
			},
			{ 0, 0, 0, 0, 0, 0, 0, 0 } // 4(new) 3 (old)
		},
	/*
	{
			{
				"5",
				"1 2 3 4 5"
			},
			{ 0, 0, 0, 0, 0, 0, 0, 0 } // 4(new) 3 (old)
		}*/
};

template <class NType, class EleType>
class ClsMain1 {
	NType N;
	// deque<PType> p1;
public:

	ClsMain1() {
	}

	void doMain(istream &cin) {
		cartesian_tree <NType, EleType> o1(cin);
		o1.doMain();
	}
};

// template <class NType, class VType, class PType, class DType>

template <class NType, class EleType>
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


		ClsMain1 <NType, EleTypeVal> p1;


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

			Cls1<NTypeVal, EleTypeVal> o;
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

		Cls1<NTypeVal, EleTypeVal> o;
		// Cls1<NTypeVal, VTypeVal, PTypeVal, DTypeVal> o;
		// Cls1<NTypeVal, LTypeVal> o;
		o.testFunction(cin);

	}

	return 0;
}
