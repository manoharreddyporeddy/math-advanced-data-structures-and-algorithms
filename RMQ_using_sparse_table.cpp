//
// beautiful code
//

// #include "stdafx.h"

#include <algorithm>  // min, min
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
ostream & operator<<(ostream &o1, const vector<T> &c) {
	for (auto it = c.begin(); it != c.end(); it++) {
		o1 << setw(4) << *it << " ";
	}
	return o1;
}

template <typename T>
ostream & operator<<(ostream &o1, const deque<T> &c) {
	for (auto it = c.begin(); it != c.end(); it++) {
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
Node *l, *r, *p;	// lefti, righti, parent
};
*/

// #define PTypeVal unsigned long long
// #define EleTypeVal unsigned long long
// #define EleTypeVeryLargVal unsigned long long
// #define SizeT unsigned int

#define NTypeVal unsigned int
#define EleTypeVal unsigned long
#define NTypeValBig unsigned long
#define EleTypeValBig unsigned long

template <class NType, class EleType, class NTypeBig, class EleTypeBig>
class sparse_table {

	NType N, i, j;	// ai * aj <= min (ai .. aj),	i<j
	EleType ai;

	deque<EleType> v1;			// input array, with N elements
	deque<deque<EleType>> sparse_table_arr;	// sparse_table_arr array,	with N elements	// all initially 0, it does not matter what values they have as they will be filled from v1

	// unordered_set <EleType> s1;
	// unordered_multimap <NTypeVal, pair<NTypeVal, EleTypeVal>> m1;
	// unordered_map <pair<NTypeVal, NTypeVal >, EleTypeVal> m1;
	// unordered_multimap <NTypeVal, pair<NTypeVal, EleTypeVal>>
	// pair<NTypeVal, EleTypeVal> least_gr_eq;
	// NType   least_gr_eq_ri;
	// EleType least_gr_eq_rmin;

public:

	sparse_table(istream &cin) {

		//cout << lefti << setw(30) << "size of char: " << "-" << pow(2, 8 * sizeof(char) - 1) << " " << pow(2, 8 * sizeof(char) - 1) - 1 << endl;
		//cout << lefti << setw(30) << "size of unsigned char: " << " " << 0 << " " << pow(2, 8 * sizeof(unsigned char)) - 1 << endl;
		//cout << lefti << setw(30) << "size of short: " << "-" << pow(2, 8 * sizeof(short) - 1) << " " << pow(2, 8 * sizeof(short) - 1) - 1 << endl;
		//cout << lefti << setw(30) << "size of unsigned short: " << " " << 0 << " " << pow(2, 8 * sizeof(unsigned short)) - 1 << endl;
		//cout << lefti << setw(30) << "size of int: " << "-" << pow(2, 8 * sizeof(int) - 1) << " " << pow(2, 8 * sizeof(int) - 1) - 1 << endl;
		//cout << lefti << setw(30) << "size of unsigned int: " << " " << 0 << " " << pow(2, 8 * sizeof(unsigned int)) - 1 << endl;
		//cout << lefti << setw(30) << "size of long: " << "-" << pow(2, 8 * sizeof(long) - 1) << " " << pow(2, 8 * sizeof(long) - 1) - 1 << endl;
		//cout << lefti << setw(30) << "size of unsigned long: " << " " << 0 << " " << pow(2, 8 * sizeof(unsigned long)) - 1 << endl;
		//cout << lefti << setw(30) << "size of long long: " << "-" << pow(2, 8 * sizeof(long long) - 1) << " " << pow(2, 8 * sizeof(long long) - 1) - 1 << endl;
		//cout << lefti << setw(30) << "size of unsigned long long: " << " " << 0 << " " << pow(2, 8 * sizeof(unsigned long long)) - 1 << endl;

		// c(

		cin >> N;

		v1.resize(N);
		// sparse_table_arr.resize(4 * N);

		// get arr
		for (NType i = 0; i <= N - 1; i++) {
			cin >> ai;
			v1[i] = ai;
		}

		// v1 = { 1,3,5,7,9,11 };
		// v1 = { 5,6,4 ,1,7, 1,3,2 };
		// v1 = { 1,4,2,3 };
		// cout << one_till(N) << endl;
		// cout << v1 << endl;
		// cout << setw(4) << ai << " ";

		build__sparse_table_arrment_tree__for_Range_Query_Max__wrapper();
		//for (NType i = 0; i < sparse_table_arr.size(); i++) {
		//	cout << sparse_table_arr[i] << endl;
		//}
	}

	void build__sparse_table_arrment_tree__for_Range_Query_Max__wrapper() {
		build__sparse_table__for_Range_Max_Query(0, N - 1, 0);
	}

	///////// TODO
	//////////// vector or deque??
	///////// TODO



	// alefti, arighti & a_mid are indexes of array
	// sposi is index of sparse_table_arrtree array
	// NOTE: sposi runs as if it is BFS
	void build__sparse_table__for_Range_Max_Query(const NType &alefti, const NType &arighti, const NType &sposi) {

		// b(

		NType log2N = (NType)log2(N);
		log2N = (NType)pow(2, log2N);

		sparse_table_arr.push_back(move(v1));
		for (NType pw2len = 1; pw2len < log2N; pw2len = 2 * pw2len) {	// 1, 2, 4, 8, 16

			auto i_st_prev_row = sparse_table_arr.size() - 1;
			auto st_prev_row_arr_size = sparse_table_arr[i_st_prev_row].size();

			deque <EleType> v;
			v.resize(st_prev_row_arr_size - pw2len);
			for (NType i = 0; i < st_prev_row_arr_size - pw2len; i++) {
				// v.push_back(min(sparse_table_arr[i_st_prev_row][i], sparse_table_arr[i_st_prev_row][i + pw2len]));
				v[i] = min(
					sparse_table_arr[i_st_prev_row][i],
					sparse_table_arr[i_st_prev_row][i + pw2len]
				);
			}

			sparse_table_arr.push_back(v);
		}
	}


	void range_min_query__all() {

		/*
		for (NType qlefti = 0; qlefti <= N - 1; qlefti++) {
			range_min_query(qlefti, qlefti, 0, N - 1, 0);
		}
		return;
		*/

		/*
			for (NType qlefti = 0; qlefti <= N - 1; qlefti++) {
				for (NType qrighti = qlefti; qrighti <= N - 1; qrighti++) {

					EleType min = range_min_query(qlefti, qrighti, 0, N - 1, 0);
					cout << "[" << qlefti << "," << qrighti << "] = " << min << endl;
				}
			}
			*/
	}

	EleType range_min_query(
		const NType &qlefti, const NType &qrighti,	// query		low high
		const NType &slefti, const NType &srighti,	// sparse_table_arr array	low high
		const NType &sposi							// sparse_table_arr array	posiition
	) {

		// q(

		// qlefti
		// qrighti
		// sparse_table_arr
		NType len_of_query = qrighti - qlefti;
		NType log2N = (NType)log2(len_of_query);
		NType a = (NType)pow(2, log2N);

		NType prefix_left = qlefti;
		NType prefix_right = qlefti + a - 1;
		NType suffix_left = qrighti - a + 1;
		NType suffix_right = qrighti;

		EleType a1 = sparse_table_arr[log2N][prefix_left];
		EleType a2 = sparse_table_arr[log2N][suffix_left];
		EleType min1 = min(a1, a2);

		return min1;
	}

	void doMain(istream & cin) {

		// range_min_query__all();
		EleType min = range_min_query(0, 6, 0, N - 1, 0);

		for (NType i = 0; i <= N - 1; i++) {
			for (NType j = i; j <= N - 1; j++) {

				EleType min = range_min_query(i, j, 0, N - 1, 0);
				cout << "[" << i << "," << j << "] = " << min << endl;

				// build__sparse_table_arrment_tree__for_Range_Query_Max__wrapper();
				// range_update__wrapper(i, j, ai);
				// range_min_query__all();
			}
		}
		cout << endl;

		// range_min_query__all();
		// cout << sparse_table_arr[0][0] << endl;
	}
};

// testsss
#define ReturnCountTypeValue char
vector < pair < vector<string>, vector<ReturnCountTypeValue >>> tests = {

	/*
	even
	5  2  4 7 6 3 1 2

	2powlen 1 ->  5  2  4 7 6 3 1 2
	2powlen 2 -> * 2  2 * 4 6 3 1 1
	2powlen 4 -> * 2 + 2  3 1 1 +
	2powlen 8 ->  1 +
	*/

		{
			{
				"8",
				"5 2  4 7  6 3  1 2"
			},
			{ 0, 0, 0, 0, 0, 0, 0, 0 } // 4(new) 3 (old)		5*10 = 50
		},
	/*
	odd

	5 2  4 6 3 1 2

	2powlen 1 ->  5 2  4 6 3 1 2
	2powlen 2 -> * 2 2 * 4 3 1 1
	2powlen 4 -> * 2 2  1 1
	2powlen 8 ->

	*/
		{
			{
				"7",
					"5 2  4 6 3  1 2"
			},
			{ 0, 0, 0, 0, 0, 0, 0, 0 } // 4(new) 3 (old)		5*10 = 50
		},
	/*
		{
			{
				"5",
				"1 1 2 4 2"
			},
			{ 0, 0, 0, 0, 0, 0, 0, 0 } // 4(new) 3 (old)		5*10 = 50
		},
			{
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
	//    LenType ai;
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


		// m(

		sparse_table <NTypeVal, EleTypeVal, NTypeValBig, EleTypeValBig> o1(cin);
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

			//            for (PTypeVal ai = 0; ai < q; ai++) {
			//            Cls1<NTypeVal, LTypeVal, TTypeVal> o;
			//                // // debug("\tactual_result ", actual_result, " ", "expected_output ", expected_output[ai], "\n");
			//
			//                // assert(actual_result == expected_output[ai]);
			//            }

			// break;

		} // for tests.size()

		return 0;
	}

	return 0;
}
