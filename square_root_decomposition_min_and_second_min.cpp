//
// beautiful code
//

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

#define NTypeVal signed long
#define EleTypeVal unsigned long
#define NTypeValBig unsigned long
#define EleTypeValBig unsigned long

template <class NType, class EleType, class NTypeBig, class EleTypeBig>
class square_root_decomposition {

	NType N, i, j, t;	// ai * aj <= min (ai .. aj),	i<j
	NType blocks_or_block_size;
	// EleType ai;

	double td;


	NType qli, qri;
	NType q_start_block, q_end_block;
	pair<EleType, EleType> a, b;
	pair<EleType, EleType> mins, mins_prev;

	vector<EleType> v1;			// input array, with N elements
	vector<pair<EleType, EleType>> vb1;		// sqrt blocks_or_block_size, with N elements
	// vector<vector<pair<EleType, EleType>>> vb1;	// vb1 array,	with N elements	// all initially 0, it does not matter what values they have as they will be filled from v1

	vector<NType> _log2floor_table_;
	// vector<NType> _log2floor_table_squared;
	// vector<NType> _2_squared;

	// unordered_set <EleType> s1;
	// unordered_multimap <NTypeVal, pair<NTypeVal, EleTypeVal>> m1;
	// unordered_map <pair<NTypeVal, NTypeVal >, EleTypeVal> m1;
	// unordered_multimap <NTypeVal, pair<NTypeVal, EleTypeVal>>
	// pair<NTypeVal, EleTypeVal> least_gr_eq;
	// NType   least_gr_eq_ri;
	// EleType least_gr_eq_rmin;

public:

	square_root_decomposition(istream &cin) {
		/*
		cout << left << setw(30) << "size of char: " << "-" << pow(2, 8 * sizeof(char) - 1) << " " << pow(2, 8 * sizeof(char) - 1) - 1 << endl;
		cout << left << setw(30) << "size of unsigned char: " << " " << 0 << " " << pow(2, 8 * sizeof(unsigned char)) - 1 << endl;
		cout << left << setw(30) << "size of short: " << "-" << pow(2, 8 * sizeof(short) - 1) << " " << pow(2, 8 * sizeof(short) - 1) - 1 << endl;
		cout << left << setw(30) << "size of unsigned short: " << " " << 0 << " " << pow(2, 8 * sizeof(unsigned short)) - 1 << endl;
		cout << left << setw(30) << "size of int: " << "-" << pow(2, 8 * sizeof(int) - 1) << " " << pow(2, 8 * sizeof(int) - 1) - 1 << endl;
		cout << left << setw(30) << "size of unsigned int: " << " " << 0 << " " << pow(2, 8 * sizeof(unsigned int)) - 1 << endl;
		cout << left << setw(30) << "size of long: " << "-" << pow(2, 8 * sizeof(long) - 1) << " " << pow(2, 8 * sizeof(long) - 1) - 1 << endl;
		cout << left << setw(30) << "size of unsigned long: " << " " << 0 << " " << pow(2, 8 * sizeof(unsigned long)) - 1 << endl;
		cout << left << setw(30) << "size of long long: " << "-" << pow(2, 8 * sizeof(long long) - 1) << " " << pow(2, 8 * sizeof(long long) - 1) - 1 << endl;
		cout << left << setw(30) << "size of unsigned long long: " << " " << 0 << " " << pow(2, 8 * sizeof(unsigned long long)) - 1 << endl;

		cout << left << setw(30) << "size of char: " << "-" << 1 << (sizeof(char)) << " " << 1 << (sizeof(char)) - 1 << endl;
		cout << left << setw(30) << "size of unsigned char: " << " " << 0 << " " << 1 << (sizeof(unsigned char)) - 1 << endl;
		cout << left << setw(30) << "size of short: " << "-" << 1 << (sizeof(short)) << " " << 1 << (sizeof(short)) - 1 << endl;
		cout << left << setw(30) << "size of unsigned short: " << " " << 0 << " " << 1 << (sizeof(unsigned short)) - 1 << endl;
		cout << left << setw(30) << "size of int: " << "-" << 1 << (sizeof(int)) << " " << 1 << (sizeof(int)) - 1 << endl;
		cout << left << setw(30) << "size of unsigned int: " << " " << 0 << " " << 1 << (sizeof(unsigned int)) - 1 << endl;
		cout << left << setw(30) << "size of long: " << "-" << 1 << (sizeof(long)) << " " << 1 << (sizeof(long)) - 1 << endl;
		cout << left << setw(30) << "size of unsigned long: " << " " << 0 << " " << 1 << (sizeof(unsigned long)) - 1 << endl;
		cout << left << setw(30) << "size of long long: " << "-" << 1 << (sizeof(long long)) << " " << 1 << (sizeof(long long)) - 1 << endl;
		cout << left << setw(30) << "size of unsigned long long: " << " " << 0 << " " << 1 << (sizeof(unsigned long long)) - 1 << endl;
		*/

		// c(

		// cin >> N;
		// v1.resize(N);



		// v1 = { 1,3,5,7,9,11 };
		// v1 = { 5,6,4 ,1,7, 1,3,2 };
		// v1 = { 1,4,2,3 };
		// cout << one_till(N) << endl;
		// cout << v1 << endl;
		// cout << setw(4) << ai << " ";

		build__vsb1_for_range_min_query__wrapper(cin);
		//for (t = 0; t < vb1.size(); t++) {
		//	cout << vb1[t] << endl;
		//}
	}

	void build__vsb1_for_range_min_query__wrapper(istream &cin) {
		build__vsb1_for_range_min_query(cin);
	}

	// alefti, arighti & a_mid are indexes of array
	// sposi is index of _vsb1tree array
	// NOTE: sposi runs as if it is BFS
	void build__vsb1_for_range_min_query(istream &cin) {

		// b(


		//// create log table - begin
		//// See: http://www.rapidtables.com/math/algebra/logarithm/Logarithm_Table.htm
		//_log2floor_table_.resize(N + 1, 0);
		//_log2floor_table_squared.resize(N + 1, 0);
		//_2_squared.resize(N + 1, 0);

		//_log2floor_table_squared[0] = 1 << _log2floor_table_[0];
		//_log2floor_table_squared[1] = 1 << _log2floor_table_[1];

		//_2_squared[0] = 1 << 0;
		//_2_squared[1] = 1 << 1;

		//for (NType i = 2; i < N + 1; i++) {
		//	_log2floor_table_[i] = _log2floor_table_[i / 2] + 1;
		//	_log2floor_table_squared[i] = 1 << _log2floor_table_[i];

		//	_2_squared[i] = 1 << i;
		//}




		// create log table - end


		mins = { numeric_limits<EleType>::max() , numeric_limits<EleType>::max() };
		mins_prev = { numeric_limits<EleType>::max() , numeric_limits<EleType>::max() };


		cin >> N;
		v1.resize(N);

		auto sqrtN = sqrt(N);
		blocks_or_block_size = int(sqrtN) + 1;

		vb1.resize(blocks_or_block_size);
		// vb1.resize(blocks_or_block_size, vector<pair<EleType, EleType>>(blocks_or_block_size));	// vb1.resize(4 * N);	// vb1.resize(blocks_or_block_size);	// vb1[0].resize(N);

		for (t = 0; t < N; t++) {
			cin >> v1[t];
			// vb1[0][t] = { e , numeric_limits<EleType>::max() };
		}



		// O(blocks_or_block_size)              = O(blocks_or_block_size) space
		// O(blocks_or_block_size  * blocks_or_block_size) = O(N) time

		NType block_index = 0, block_start_index = 0;
		for (
			block_index = 0, block_start_index = 0;
			// block_index < blocks_or_block_size &&
			block_start_index < N;
			block_index++, block_start_index += blocks_or_block_size) {

			mins = { numeric_limits<EleType>::max() , numeric_limits<EleType>::max() };

			for (NType j = block_start_index; (j < block_start_index + blocks_or_block_size) && (j < N); j++) {
				if (v1[j] <= mins.first) {
					mins.second = mins.first;
					mins.first = v1[j];
				}
				else {
					if (v1[j] <= mins.second) {
						mins.second = v1[j];
					}
				}
			}

			vb1[block_index] = mins;
		}

		if (block_index < blocks_or_block_size) {

			mins = { numeric_limits<EleType>::max() , numeric_limits<EleType>::max() };
			vb1[block_index] = mins;
		}

		// vb1[i].first & vb1[i].second can be  numeric_limits<EleType>::max()   for last block, check i< N
		// vb1[i].first & vb1[i].second can be  numeric_limits<EleType>::max()   for last block, check i< N
		// vb1[i].first & vb1[i].second can be  numeric_limits<EleType>::max()   for last block, check i< N
		// vb1[i].first & vb1[i].second can be  numeric_limits<EleType>::max()   for last block, check i< N
		// vb1[i].first & vb1[i].second can be  numeric_limits<EleType>::max()   for last block, check i< N

	}

	void range_min_query__all() {
	}

	void range_min_min2_query(NType qli, NType qri) {

		// q(

		// O(sqrt N)


		// GET q_start_block & q_end_block 

		q_start_block = q_end_block = 0;

		td = (double)qli / blocks_or_block_size;
		q_start_block = int(td) + 1;

		td = (double)(qri + 1) / blocks_or_block_size;
		q_end_block = int(td) - 1;



		// mid part

		if (!N) {
			mins = { numeric_limits<EleType>::max() , numeric_limits<EleType>::max() };
			return;
		}

		// mins = { v1[qli] , v1[qli] };
		mins = { numeric_limits<EleType>::max() , numeric_limits<EleType>::max() };

		for (NType block_index = q_start_block; block_index <= q_end_block; block_index++) {

			a = vb1[block_index];

			if (mins.first < a.first) {
				mins = { mins.first, min(mins.second, a.first) };
			}
			else if (mins.first > a.first) {
				mins = { a.first, min(a.second, mins.first) };
			}
			else {
				mins = { mins.first, min(mins.second, a.second) };
			}

		}

		if (q_start_block > q_end_block) {

			// only start part

			for (NType i = qli; i <= qri; i++) {
				if (v1[i] < mins.first) {
					mins = { v1[i], mins.first };
				}
				else if (v1[i] < mins.second) {
					mins = { mins.first , v1[i] };
				}

			}
		}
		else {

			// start part

			for (NType i = qli; i < (q_start_block)*blocks_or_block_size - 1; i++) {
				if (v1[i] < mins.first) {
					mins = { v1[i], mins.first };
				}
				else if (v1[i] < mins.second) {
					mins = { mins.first , v1[i] };
				}

			}

			// end part

			for (NType i = (q_end_block + 1)*blocks_or_block_size; i <= qri; i++) {
				if (v1[i] < mins.first) {
					mins = { v1[i], mins.first };
				}
				else if (v1[i] < mins.second) {
					mins = { mins.first , v1[i] };
				}

			}

		}

	}

	void doMain(istream & cin) {

		// m(

		for (qli = 0; qli <= N - 1; qli++) {
			for (qri = qli ; qri <= N - 1; qri++) {

				range_min_min2_query(qli, qri);
				cout << "[" << qli << "," << qri << "]=" << mins.first << "," << mins.second << "  ";
			}

			cout << endl;
		}

	}
};

// testsss
#define ReturnCountTypeValue char
vector < pair < vector<string>, vector<ReturnCountTypeValue >>> tests = {


	{
		{
			"17",
			"1601 1502 1403 1304 1205 1106 1007 908 809 710 611 512 413 314 215 116 0"
		},
		{ 0, 0, 0, 0, 0, 0, 0, 0 } // 4(new) 3 (old)		5*10 = 50
	},


	{
		{
			"16",
			"1502 1403 1304 1205 1106 1007 908 809 710 611 512 413 314 215 116 0"
		},
		{ 0, 0, 0, 0, 0, 0, 0, 0 } // 4(new) 3 (old)		5*10 = 50
	},

	/*

	{
	{
	"5",
	"9 6 3 5 2"
	},
	{ 0, 0, 0, 0, 0, 0, 0, 0 } // 4(new) 3 (old)
	},


	{
		{
			"1",
			"9"
		},
		{ 0, 0, 0, 0, 0, 0, 0, 0 } // 4(new) 3 (old)
	},


	{
		{
			"2",
			"9 6"
		},
		{ 0, 0, 0, 0, 0, 0, 0, 0 } // 4(new) 3 (old)
	},

	{
		{
			"3",
			"9 6 3"
		},
		{ 0, 0, 0, 0, 0, 0, 0, 0 } // 4(new) 3 (old)
	},

	*/

	/*
	{
		{
			"4",
			"9 6 3 5"
		},
		{ 0, 0, 0, 0, 0, 0, 0, 0 } // 4(new) 3 (old)
	},
	*/
	/*
	{
		{
			"5",
			"9 6 3 5 2"
		},
		{ 0, 0, 0, 0, 0, 0, 0, 0 } // 4(new) 3 (old)
	},
	*/
	/*
	2powlen 1 ->  9  6  3  5  2
	2powlen 2 -> *6  3 *3  2
	2powlen 4 -> *3+ 2
	2powlen 8 ->  1+


	2powlen 1 ->  5  2  4 7 6 3 1 2
	2powlen 2 -> *2  2 *4 6 3 1 1
	2powlen 4 -> *2+ 2  3 1 1+
	2powlen 8 ->  1+
	*/



	/*
	odd
	5 2  4 6 3  1 2

	2powlen 1 ->  5 2  4 6 3 1 2
	2powlen 2 -> *2 2 *4 3 1 1
	2powlen 4 -> *2 2  1 1
	2powlen 8 ->
	*/
	/*
	{
		{
			"7",
			"5 2  4 6 3  1 2"
		},
		{ 0, 0, 0, 0, 0, 0, 0, 0 } // 4(new) 3 (old)		5*10 = 50
	},
	*/

	/*
		even
		5  2  4 7 6 3 1 2

		2powlen 1 ->  5  2  4 7 6 3 1 2
		2powlen 2 -> *2  2 *4 6 3 1 1
		2powlen 4 -> *2+ 2  3 1 1+
		2powlen 8 ->  1+
	*/
	/*
{
	{
		"8",
		"5 2  4 7  6 3  1 2"
	},
	{ 0, 0, 0, 0, 0, 0, 0, 0 } // 4(new) 3 (old)		5*10 = 50
},
{
	{
		"9",
		"5 2  4 7  6 3  1 2 0"
	},
	{ 0, 0, 0, 0, 0, 0, 0, 0 } // 4(new) 3 (old)		5*10 = 50
},*/





/*

{
	{
		"8",
		"5 2  4 7  6 3  1 2"
	},
	{ 0, 0, 0, 0, 0, 0, 0, 0 } // 4(new) 3 (old)		5*10 = 50
},

*/

/*

*/


/*
{
{
"5",
"1 1 2 4 2"
},
{ 0, 0, 0, 0, 0, 0, 0, 0 } // 4(new) 3 (old)		5*10 = 50
},
*/





/*
*/
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



		square_root_decomposition <NTypeVal, EleTypeVal, NTypeValBig, EleTypeValBig> o1(cin);
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
