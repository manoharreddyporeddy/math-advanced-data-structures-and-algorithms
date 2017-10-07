//
// beautiful code
//

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

/*
struct Node
{
NTypeVal i;
EleTypeVal d;
Node *l, *r, *p;	// left, right, parent
};
*/

// #define PTypeVal unsigned long long
// #define EleTypeVal unsigned long long
// #define EleTypeValBig unsigned long long
// #define SizeT unsigned int

#define NTypeVal unsigned int
#define NTypeValBig unsigned long long
#define EleTypeVal unsigned long
#define EleTypeValBig unsigned long long

template <class NType, class EleType, class NTypeBig, class EleTypeBig>
class seg_tree_lazy {
	bool is_lazy;

	NType N, i, j;
	vector<EleType> v1;		// input array, with N elements
	vector<EleType> seg;		// seg array,	with N elements	// all initially 0, it does not matter what values they have as they will be filled from v1
	vector<EleType> lazy;	// lazy seg array,	with N elements	// same as above

public:

	seg_tree_lazy(istream &cin) {

		is_lazy = true;

		cin >> N;

		v1.resize(N);

		for (NType i = 0; i <= N - 1; i++) {
			cin >> v1[i];
		}

		build__segment_tree_for_range_max_query_wrapper();
	}

	void build__segment_tree_for_range_max_query_wrapper() {

		seg.resize(4 * N);
		if (is_lazy) {
			lazy.resize(4 * N);
		}

		// fill(seg.begin(), seg.end(), numeric_limits<EleType>::min());

		build__segment_tree_for_range_max_query(0, N - 1, 0);
	}

	// aaaaaaaaaaaaaaaa
	// aaaaaaaaaaaaaaaa
	// aaaaaaaaaaaaaaaa

	// aleft, aright & amid are indexes of array
	// spos is index of segtree array. NOTE: spos runs as if it is BFS
	void build__segment_tree_for_range_max_query(const NType &aleft, const NType &aright, const NType &spos) {

		// not possible
		if (aleft > aright) {
			return;
		}

		// leaf node
		if (aleft == aright) {
			seg[spos] = v1[aleft];
			return;
		}

		NType amid = aleft + (aright - aleft) / 2;

		// build left and right seg trees
		build__segment_tree_for_range_max_query(aleft, amid, 2 * spos + 1);			// spos * 2 + 1 is left  child (1 initially)
		build__segment_tree_for_range_max_query(amid + 1, aright, 2 * spos + 2);	// spos * 2 + 2 is right child (2 initially)

																					// update parent in seg tree from its children
		seg[spos] = max(seg[2 * spos + 1], seg[2 * spos + 2]);
	}

	void range_update__wrapper(const NType &uleft, const NType &uright, const EleType &ele) {
		range_update(uleft, uright, ele, 0, N - 1, 0);
	}

	void range_update(
		const NType &uleft, const NType &uright, const EleType &ele,
		const NType &sleft, const NType &sright, const NType &spos) {

		// not possible
		if (sleft > sright) {
			return;
		}

		// propogate any pending updates, from previous update
		//		to current, move accumulate from lazy to seg
		//		to children, from lazy, further down
		if (lazy[spos]) {
			seg[spos] += lazy[spos];
			if (sleft != sright) {
				lazy[2 * spos + 1] += lazy[spos];
				lazy[2 * spos + 2] += lazy[spos];
			}
			lazy[spos] = 0;
		}

		// seg has no overlap
		if (sright < uleft ||	// current seg position is outside left of queried range
			uright < sleft		// current seg position is outside right of queried range
			) {
			return;
		}

		// seg has full overlap
		//		current seg position (range in array) is inside queried range, so return that aggregate
		if (uleft <= sleft && sright <= uright) {
			seg[spos] += ele;
			if (sleft != sright) {
				lazy[2 * spos + 1] += ele;
				lazy[2 * spos + 2] += ele;
			}
			return;
		}

		// seg has partial overlap
		NType smid = sleft + (sright - sleft) / 2;
		range_update(uleft, uright, ele, sleft, smid, 2 * spos + 1);
		range_update(uleft, uright, ele, smid + 1, sright, 2 * spos + 2);

		seg[spos] = max(
			seg[2 * spos + 1],
			seg[2 * spos + 2]
		);
	}

	EleType range_max_query(
		const NType &qleft, const NType &qright,	// query		low high
		const NType &sleft, const NType &sright,	// seg array	low high
		const NType &spos							// seg array	position
	) {

		// not possible
		if (sright < sleft) {
			return numeric_limits<EleType>::min();
		}

		if (is_lazy) {		/////////////////// LAZY REQUIRED

							// propogate any pending updates
			if (lazy[spos]) {
				seg[spos] += lazy[spos];
				if (sleft != sright) {
					lazy[2 * spos + 1] += lazy[spos];
					lazy[2 * spos + 2] += lazy[spos];
				}
				lazy[spos] = 0;
			}
		}

		// seg has no overlap
		if (sright < qleft ||	// current seg position is outside left of queried range
			qright < sleft		// current seg position is outside right of queried range
			) {
			return numeric_limits<EleType>::min();
		}

		// seg has full overlap
		//	current seg position (range in array) is inside queried range, so return that aggregate
		if (qleft <= sleft && sright <= qright) {
			return seg[spos];
		}

		// seg has partial overlap, so get max of both
		NType smid = (sleft + sright) / 2;

		return max(
			range_max_query(qleft, qright, sleft, smid, 2 * spos + 1),		// spos * 2 + 1 is left  child (1 initially)
			range_max_query(qleft, qright, smid + 1, sright, 2 * spos + 2)	// spos * 2 + 2 is right child (2 initially)
		);

	}

	void doMain(istream & cin) {

		// range_update__wrapper(1, 2, 3);
		// range_update__wrapper(i, j, 3);

		// range_max_query__all();

		for (NType qleft = 0; qleft <= N - 1; qleft++) {
			for (NType qright = qleft + 1; qright <= N - 1; qright++) {

				EleType max = range_max_query(qleft, qright, 0, N - 1, 0);
				cout << "[" << qleft << "," << qright << "] = " << max << endl;
			}
		}

		cout << seg[0] << endl;
	}
};

// testsss
// testsss
// testsss
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
	/*	{
	{
	"4 3",
	"0 3 3",
	"0 3 1",
	"0 0 2"
	},
	{ 0, 0, 0, 0, 0, 0, 0, 0 } // 4(new) 3 (old)		5*10 = 50
	},
	{
	{
	"8 3",
	"0 3 3",
	"0 3 1",
	"0 0 2"
	},
	{ 0, 0, 0, 0, 0, 0, 0, 0 } // 4(new) 3 (old)		5*10 = 50
	},*/
	{
		{
			"5",
			"1 1 2 4 2"
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

class Cls1 {

	//    HNType n;
	//    MType m;
	// deque <pair<VType, NType > > p1;
	//    XType x;
	//    string S;
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


		seg_tree_lazy <NTypeVal, EleTypeVal, NTypeValBig, EleTypeValBig> o1(cin);
		o1.doMain(cin);


		auto actual_result = 0;
		res.push_back(actual_result);

		return res;
	}

};


int main() {

	if (!DEBUG_MODE) {

		Cls1 o;
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

			Cls1 o;
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
