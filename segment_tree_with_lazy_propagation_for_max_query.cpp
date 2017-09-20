//
// beautiful code
//

// #include "stdafx.h"

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
#define NTypeVal int
#define EleTypeVal int
#define EleTypeVeryLargVal unsigned long long
// #define SizeT unsigned int
// -----------------------------------

/*
struct Node
{
	NTypeVal i;
	EleTypeVal d;
	Node *l, *r, *p;	// left, right, parent
};
*/

template <class NType, class EleType>
class seg_tree_lazy {

	NType N;
	EleType Ai;

	typedef deque<NType> container_NType;

	container_NType v1;   // input array, with N+1 elements - element at index 0, is not used
	container_NType seg;  // seg array, with N+1 elements - element at index 0, is not used
	container_NType lazy;  // seg array, with N+1 elements - element at index 0, is not used

	// unordered_set <EleType> s1;
	// unordered_multimap <NTypeVal, pair<NTypeVal, EleTypeVal>> m1;
	// unordered_map <pair<NTypeVal, NTypeVal >, EleTypeVal> m1;

	// unordered_multimap <NTypeVal, pair<NTypeVal, EleTypeVal>>
	// pair<NTypeVal, EleTypeVal> least_gr_eq;

	//NType   least_gr_eq_ri;
	//EleType least_gr_eq_rmin;

public:

	seg_tree_lazy(istream &cin) {
		cin >> N;

		// v1.reserve(N);
		v1.resize(N);

		// get arr
		for (NType i = 0; i <= N - 1; i++) {
			cin >> Ai;
			v1[i] = Ai;
		}

		///////// cout << one_till(N) << endl;
		// cout << v1 << endl;
		// cout << setw(4) << Ai << " ";
	}

	void build_for_lazy_Range_Query_Max_wrapper() {

		seg.resize(4 * N);
		lazy.resize(4 * N);

		/////////// fill(seg.begin(), seg.end(), numeric_limits<EleType>::min());
		/////////// fill(lazy.begin(), lazy.end(), numeric_limits<EleType>::min());

		build_for_lazy_Range_Query_Max(0, N - 1, 0);
	}

	// al, ah & a_mid are indexes of array, and   si is index of segtree array
	void build_for_lazy_Range_Query_Max(const NType &al, const NType &ah, const NType &si) {

		if (al == ah) {
			seg[si] = v1[al];
			return;
		}

		auto a_mid = (al + ah) / 2;

		// build left and right seg trees
		build_for_lazy_Range_Query_Max(al, a_mid, 2 * si + 1);			// si * 2 + 1 is left  child (1 initially)
		build_for_lazy_Range_Query_Max(a_mid + 1, ah, 2 * si + 2);	// si * 2 + 2 is right child (2 initially)

		// update parent in seg tree from its children
		seg[si] = max(seg[2 * si + 1], seg[2 * si + 2]);
	}

	void lazy_Range_Update_wrapper(
		const NType &ul, const NType &uh,
		const EleType &ele
	) {
		lazy_Range_Update(ul, uh, ele, 0, N - 1, 0);
	}

	void lazy_Range_Update(
		const NType &ul, const NType &uh,
		const EleType &ele,
		const NType &sl, const NType &sh,
		const NType &si) {

		if (sh < sl) {
			return;
		}

		// propogate any pending updates
		if (lazy[si]) {
			seg[si] += lazy[si];
			if (sl != sh) {
				lazy[2 * si + 1] = lazy[si];
				lazy[2 * si + 2] = lazy[si];
			}
			lazy[si] = 0;
		}

		// seg has no overlap
		if (sh < ul ||	// current seg position is outside left of queried range
			uh < sl		// current seg position is outside right of queried range
			) {
			return;
		}

		// seg has full overlap
		//		current seg position (range in array) is inside queried range, so return that aggregate
		if (ul <= sl && sh <= uh) {
			seg[si] += ele;
			if (sl != sh) {
				lazy[2 * si + 1] = ele;
				lazy[2 * si + 2] = ele;
			}
			return;
		}

		// seg has partial overlap
		NType smid = (sl + sh) / 2;
		lazy_Range_Update(ul, uh, ele, sl, smid, 2 * si + 1);
		lazy_Range_Update(ul, uh, ele, smid + 1, sh, 2 * si + 2);

		seg[si] = max(
			seg[2 * si + 1],
			seg[2 * si + 2]
		);
	}

	void lazy_Range_Query_Max_wrapper() {

		for (NType ql = 0; ql <= N - 1; ql++) {
			for (NType qh = ql; qh <= N - 1; qh++) {

				auto min = lazy_Range_Query_Max(ql, qh, 0, N - 1, 0);
				cout << "[" << ql << "," << qh << "] = " << min << endl;
			}
		}
	}

	EleType lazy_Range_Query_Max(
		const NType &ql, const NType &qh,	// query		low high
		const NType &sl, const NType &sh,	// seg array	low high
		const NType &si							// seg array	position
	) { // rmq

		if (sh < sl) {
			return numeric_limits<EleType>::min();
		}

		// propogate any pending updates
		if (lazy[si]) {
			seg[si] += lazy[si];
			if (sl != sh) {
				lazy[2 * si + 1] = lazy[si];
				lazy[2 * si + 2] = lazy[si];
			}
			lazy[si] = 0;
		}


		// seg has no overlap
		if (sh < ql ||	// current seg position is outside left of queried range
			qh < sl		// current seg position is outside right of queried range
			) {
			return numeric_limits<EleType>::min();
		}

		// seg has full overlap
		//	current seg position (range in array) is inside queried range, so return that aggregate
		if (ql <= sl && sh <= qh) {
			return seg[si];
		}

		// seg has partial overlap, so get min of both
		auto smid = (sl + sh) / 2;
		return max(
			lazy_Range_Query_Max(ql, qh, sl, smid, 2 * si + 1),		// si * 2 + 1 is left  child (1 initially)
			lazy_Range_Query_Max(ql, qh, smid + 1, sh, 2 * si + 2)	// si * 2 + 2 is right child (2 initially)
		);

	}


	void doMain() {

		build_for_lazy_Range_Query_Max_wrapper();
		lazy_Range_Update_wrapper(1, 2, 3);
		lazy_Range_Query_Max_wrapper();
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
		/*
		*/
	{
					{
						"5 3",
						"1 2 100",
						"2 5 100",
						"3 4 100"
					},
					{ 0, 0, 0, 0, 0, 0, 0, 0 } // 4(new) 3 (old)		5*10 = 50
				},
	/*
	{
					{
						"12",
							"9 3  7 1 8  12 12 10 20  15 18 5"
					},
					{ 0, 0, 0, 0, 0, 0, 0, 0 } // 4(new) 3 (old)	6*10 = 50
				},

{
		{
			"5",
			"1 2 3 4 5"
		},
		{ 0, 0, 0, 0, 0, 0, 0, 0 } // 4(new) 3 (old)
	}*/
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


		seg_tree_lazy <NType, EleType> o1(cin);
		o1.doMain();


		auto actual_result = 0;
		res.push_back(actual_result);

		return res;
	}

};


int main() {

	if (!DEBUG_MODE) {

		Cls1<NTypeVal, EleTypeVal> o;
		o.testFunction(cin);

		return 0;
	}
	else {

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

			/*
			ifstream ifs;
			// ifs.open("../lr_input09_dummy.txt");
			ifs.open("../lr_input09.txt");
			string temp;
			vector<string> a;
			getline(ifs, temp); 	ss << temp << endl;
			getline(ifs, temp); 	ss << temp << endl;
			*/


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

		} // for tests.size()

		return 0;
	}

	return 0;
}
