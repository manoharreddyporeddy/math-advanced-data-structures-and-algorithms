//
// beautiful code
//

#include <algorithm>  // max, max
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

template <typename T>
void get_log_table(T NType) {
	vector<NType> _log2floor_table_;
	// See: http://www.rapidtables.com/math/algebra/logarithm/Logarithm_Table.htm
	_log2floor_table_.resize(N + 1, 0);
	for (NType i = 2; i < _log2floor_table_.size(); i++) {
		_log2floor_table_[i] = _log2floor_table_[i / 2] + 1;
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
class trie {

	NType i, j;
	NType N;

	class TrieNode {
	public:
		map<char, class TrieNode *> children;			// input array, with N elements
		bool isLeaf;
		TrieNode(bool &isLeaf1) {
			isLeaf = isLeaf1;
		}
		TrieNode(char ch1, bool isLeaf1) {
			children[ch1] = NULL;
			isLeaf = isLeaf1;
		}
	};

	class TrieNode *start;

	/*
	//////////// when vector or deque?

	// vector<vector<EleType>> vv1;
	vv1.resize(_log2floor_table_[N] + 1, vector<EleType>(N));
	for (NType i = 0; i <= N - 1; i++) {
		cin >> vv1[0][i];
	}*/

	// unordered_set <EleType> s1;
	// unordered_multimap <NTypeVal, pair<NTypeVal, EleTypeVal>> m1;
	// unordered_map <pair<NTypeVal, NTypeVal >, EleTypeVal> m1;
	// unordered_multimap <NTypeVal, pair<NTypeVal, EleTypeVal>>
	// pair<NTypeVal, EleTypeVal> least_gr_eq;
	// NType   least_gr_eq_ri;
	// EleType least_gr_eq_rmax;

public:

	trie(istream &cin) {

		// c(

		cin >> N;
		start = getEmptyNode(false);

		// v1.resize(N);

		// v1 = { 1,3,5,7,9,11 };
		// v1 = { 5,6,4 ,1,7, 1,3,2 };
		// v1 = { 1,4,2,3 };
		// cout << one_till(N) << endl;
		// cout << v1 << endl;
		// cout << setw(4) << ai << " ";

		// build___trie_ment_tree__for_Range_Query_Max__wrapper(cin);
		//for (NType i = 0; i < _trie_.size(); i++) {
		//	cout << _trie_[i] << endl;
		//}
	}

	class TrieNode *getEmptyNode(bool isLeaf) {
		return new class TrieNode(isLeaf);
	}

	void add_to_trie(istream &cin) {
		// a(

		string name;		// [1,21] char len
		cin >> name;
		cout << "ADDING..." << name << " ";

		auto temp = start;

		size_t i = 0;

		for (; i < name.size() - 1; i++) {
			if (temp->children.find(name[i]) != temp->children.end()) {
				// found
				temp = temp->children[name[i]];
			}
			else {
				// not found
				temp->children[name[i]] = getEmptyNode(false);
				cout << setw(4) << "I: " << name[i];
				temp = temp->children[name[i]];
			}
		}

		if (i == name.size() - 1) {
			temp->children[name[i]] = getEmptyNode(true);
			cout << setw(4) << "I: " << name[i];
			temp = temp->children[name[i]];
		}

		cout << endl;
	}

	void find_prefix_in_trie(istream &cin) {
		// f(

		string prefix;		// [1,21] char len
		cin >> prefix;
		cout << "FINDING..." << prefix;

		auto temp = start;

		size_t i = 0;

		for (; i < prefix.size(); i++) {
			if (temp->children.find(prefix[i]) != temp->children.end()) {
				// found
				temp = temp->children[prefix[i]];
			}
			else {
				break;
			}
		}

		if (i == prefix.size()) {
			// full prefix found
			cout << " FOUND.";
		}
		else {
			cout << " NOT FOUND.";
		}

		cout << endl;
	}

	void doMain(istream & cin) {

		string option;
		string name, prefix;		// [1,21] char len

		while (N > 0) {
			cin >> option;

			if (option == "add") {	// no duplicates
				add_to_trie(cin);
			}
			else { // 'find':
				find_prefix_in_trie(cin);
			}

			N--;
		}

		cout << endl;
	}
};

// testsss
#define ReturnCountTypeValue char
vector < pair < vector<string>, vector<ReturnCountTypeValue >>> tests = {

	{
		{
			"7",
			"add abc",
			"add abgl",
			"add cdf",
			"add abcd",
			"add lmn",
			"find ab",
			"find lo"
		},
		{ 0, 0, 0, 0, 0, 0, 0, 0 } // 4(new) 3 (old)		5*10 = 50
	},

	{
		{
			"4",
			"add hack",
			"add hackerrank",
			"find hac",
			"find hak"
		},
			{ 0, 0, 0, 0, 0, 0, 0, 0 } // 4(new) 3 (old)		5*10 = 50
	},

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



		trie <NTypeVal, EleTypeVal, NTypeValBig, EleTypeValBig> o1(cin);
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
