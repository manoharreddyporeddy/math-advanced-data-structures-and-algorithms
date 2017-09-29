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

template <typename NType>
void get_log_table(NType N) {
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
struct node
{
NTypeVal i;
EleTypeVal d;
node *l, *r, *p;	// lefti, righti, parent
};
*/

// #define PTypeVal unsigned long long
// #define EleTypeVal unsigned long long
// #define EleTypeVeryLargVal unsigned long long
// #define SizeT unsigned int



#define QTypeVal unsigned long
#define NTypeVal unsigned long
#define EleTypeVal unsigned long
#define NTypeValBig unsigned long
#define EleTypeValBig unsigned long


typedef struct node {
public:
	int val;
	struct node*left;
	struct node*right;
	int ht;
} node;

template <class NType, class EleType, class NTypeBig, class EleTypeBig>
class avl__self_balancing_tree {

private:
	NType i, j;
	NType NNew;
	NType startX, startY, goalX, goalY;
	NTypeBig count_when_0 = numeric_limits<NType>::max();

	unordered_map<NType, NTypeBig> m1;
	stack<pair<NType, NTypeBig>> s1;

	// vector <string> v1;
	// set<pair<NType, NType>> s1; // visited;
	// unordered_set<pair<NType, NType>> s1; // visited;
	// queue<pair<NType, NType>> q1; // adjacents;
	// multimap<pair<NType, NType>, pair<NType, NType>> m1; // current to parent;
	// unordered_set <EleType> s1;
	// unordered_multimultimap <NTypeVal, pair<NTypeVal, EleTypeVal>> m1;
	// unordered_multimap <pair<NTypeVal, NTypeVal >, EleTypeVal> m1;
	// unordered_multimultimap <NTypeVal, pair<NTypeVal, EleTypeVal>>
	// pair<NTypeVal, EleTypeVal> least_gr_eq;
	// NType   least_gr_eq_ri;
	// EleType least_gr_eq_rmax;
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
	avl__self_balancing_tree(istream &cin) {

		// c(

		return;

		// v1.resize(N);
		// v1 = { 1,3,5,7,9,11 };
		// v1 = { 5,6,4 ,1,7, 1,3,2 };
		// v1 = { 1,4,2,3 };
		// cou t << one_till(N) << endl;
		// cou t << v1 << endl;
		// cou t << setw(4) << ai << " ";
		// build__v1ment_tree__for_Range_Query_Max__wrapper(cin);

		/*
		v1.resize(N);
		for (size_t i = 0; i < v1.size(); i++) {
		cin >> v1[i];
		}
		*/
	}

	void dfs(node* root) {
		if (root == NULL) {
			return;
		}

		dfs(root->left);
		update_height_due_to_change_at(root->left);

		dfs(root->right);
		update_height_due_to_change_at(root->left);

		update_height_due_to_change_at(root);
	}

	void bfs_print(node* root) {
		// dfs(root);


		int ht = root->ht;
		int spaces = 2 * ht;

		queue<node*> q1;

		q1.push(root);
		q1.push(NULL);


		string str1;
		cout << setw(spaces) << " ";
		spaces -= 2;

		while (!q1.empty()) {
			node* temp = q1.front();

			if (temp == NULL) {
				cout << endl;
				cout << setw(spaces) << " ";
				spaces -= 2;

				while ((temp == NULL)) {
					q1.pop();

					if (q1.empty()) {
						break;
					}

					temp = q1.front();
				}
			}

			if (q1.empty()) {
				break;
			}

			cout << setw(2) << temp->val << "(" << temp->ht << ")";
			q1.pop();

			q1.push(temp->left);
			q1.push(temp->right);
			q1.push(NULL);
		}

		cout << endl << endl;
	}


	node* get_new_node(int val1, int ht1 = 0) {		// 0, because, in BST, a new key is always inserted at leaf

		node* new1 = new node();

		new1->val = val1;
		new1->left = NULL;
		new1->right = NULL;
		new1->ht = ht1;

		return new1;
	}

	int height(node* root) {
		if (root == NULL) {
			return -1;
		}

		return max(height(root->left), height(root->right)) + 1;
	}

	/*

	  3
	 /  \
	2    4
		  \
		   5

	*/

	void update_height_due_to_change_at(node* root) {

		if (root == NULL) {
			return;
		}

		int new_height = height(root);
		if (new_height == root->ht) {
			return;
		}

		root->ht = new_height;

		// update_height_due_to_change_at(root->parent);
	}

	// --------------------------------------------
	//
	//	balance factor (balFac)	=	right child height - left child height
	//
	// --------------------------------------------
	node* single__left_rotation(node* root, bool should_update_height = true) {

		// y	+2
		//  x	+1
		//   z

		// tree hight reduces

		// root				balFac	+n			ex: +2
		// root->right		balFac	+(n-1)		ex: +1
		// then
		// 		1. single left rotation on root

		auto new_root = root->right;

		auto save = root->right->left;
		root->right->left = root;
		root->right = save;

		root = new_root;

		if (should_update_height) {
			update_height_due_to_change_at(root->left);
			update_height_due_to_change_at(root);
		}

		//  x	+1
		// y z

		return root;
	}

	node* single__right_rotation(node* root, bool should_update_height = true) {

		//   z	-2
		//  x	-1
		// y

		// tree hight reduces

		// root				balFac	-n			ex: -2
		// root->left		balFac	-(n-1)		ex: -1
		// then
		// 		1. single right rotation on root

		auto new_root = root->left;

		auto save = root->left->right;
		root->left->right = root;
		root->left = save;

		root = new_root;

		if (should_update_height) {
			update_height_due_to_change_at(root->right);
			update_height_due_to_change_at(root);
		}

		//  x	-1
		// y z

		return root;
	}

	// --------------------------------------------
	node* double__left_right_rotation(node* root) {

		//    z		-2
		// y		+1
		//   x

		// tree hight reduces

		// root				balFac	-n			ex: -2
		// root->left		balFac	+(n-1)		ex: +1
		// then
		// 		1. single left rotation on left
		// 		2. single right on root

		root->left = single__left_rotation(root->left, true);

		//   z	-2
		//  x	-1
		// y

		root = single__right_rotation(root, true);

		//  x	-1
		// y z

		return root;
	}

	node* double__right_left_rotation(node* root) {

		// y		+2
		//    z		-1
		//  x

		// tree hight reduces

		// root				balFac	+n			ex: +2
		// root->left		balFac	-(n-1)		ex: -1
		// 	then
		// 		1. single right rotation on right
		// 		2. single left on root

		root->right = single__right_rotation(root->right, true);

		// y	+2
		//  x	+1
		//   z

		root = single__left_rotation(root, true);

		//  x	+1
		// y z

		return root;
	}
	// --------------------------------------------

	node* rebalance(node* root, int &balance_factor, int &left_ht, int &right_ht) {

		// heights of the two child subtrees of any node can differ by at most one
		// balance factor = height(right subtree) - height(left subtree)
		//		that is, allowed range [-1,+1], else unbalanced so rotation is needed

		// rorate if required
		if (balance_factor >= 2) {

			int right__left_ht = (root->right->left) ? root->right->left->ht : -1;
			int right__right_ht = (root->right->right) ? root->right->right->ht : -1;

			int balance_factor_of_right = right__right_ht - right__left_ht;
			if (balance_factor_of_right > 0) {
				// if (root->right->right) {
				return single__left_rotation(root);
			}
			else {
				return double__right_left_rotation(root);
			}

		}
		else {

			int left__left_ht = (root->left->left) ? root->left->left->ht : -1;
			int left__right_ht = (root->left->right) ? root->left->right->ht : -1;

			int balance_factor_of_left = left__right_ht - left__left_ht;
			if (balance_factor_of_left < 0) {
				return single__right_rotation(root);
			}
			else {
				return double__left_right_rotation(root);
			}

		}
	}

	node* insert(node* root, int val) {

		if (root == NULL) {
			return get_new_node(val);
		}
		else {

			if (val <= root->val) {
				root->left = insert(root->left, val);

				// update height
				update_height_due_to_change_at(root->left);
			}
			else {
				root->right = insert(root->right, val);;

				// update height
				update_height_due_to_change_at(root->right);
			}

			// update height
			update_height_due_to_change_at(root);


			int left_ht = (root->left) ? root->left->ht : -1;
			int right_ht = (root->right) ? root->right->ht : -1;

			// calculate balance factor
			int balance_factor = right_ht - left_ht;
			if ((balance_factor <= -2) || (balance_factor >= 2)) {
				// rotation necessary
				root = rebalance(root, balance_factor, left_ht, right_ht);
			}

			return root;
		}
	}

};

// testsss
#define ReturnCountTypeValue char
vector < pair < vector<string>, vector<ReturnCountTypeValue >>> tests = {
	// good cases
	// bad cases
	//	see input condition	- starts with 0? or 1?
	//	global variables are a issue - create a dummpy class put your function in it, create more dummy classes if you need


	{
		{
			"5",
			"7 4 8 3 5",			// add 6
		},
		{ 0, 0, 0, 0, 0, 0, 0, 0 }
	},

	/*
	{
		{
			"5",
			"9 8 10 7 11",			// add 6
		},
		{ 0, 0, 0, 0, 0, 0, 0, 0 }
	},
	*/

	/*
	{
		{
			"3",
			"1 2",			// add 6
		},
		{ 0, 0, 0, 0, 0, 0, 0, 0 }
	},

	{
		{
			"2",
			"1 2",			// add 6
		},
		{ 0, 0, 0, 0, 0, 0, 0, 0 }
	},
	*/

	/*
	{
		{
			"1",
			"1",			// add 6
		},
		{ 0, 0, 0, 0, 0, 0, 0, 0 }
	},
	{
		{
			"1",
			"7",			// add 6
		},
		{ 0, 0, 0, 0, 0, 0, 0, 0 }
	},
	*/


	/*
		{
			{
				"4",
				"10 9 8 7",			// add 6
			},
			{ 0, 0, 0, 0, 0, 0, 0, 0 }
		},
		{
			{
				"4",
				"7 8 9 10",			// add 6
			},
			{ 0, 0, 0, 0, 0, 0, 0, 0 }
		},

		{
			{
				"5",
				"9 8 10 7 11",			// add 6
			},
			{ 0, 0, 0, 0, 0, 0, 0, 0 }
		},
		*/

		/*
		{
			{
				"4",
				"4 3 2 1",			// add 6
			},
			{ 0, 0, 0, 0, 0, 0, 0, 0 }
		},
		{
			{
				"4",
				"1 2 3 4",			// add 6
			},
			{ 0, 0, 0, 0, 0, 0, 0, 0 }
		},
		*/

		/*
		{
			{
				"4",
				"3 2 4 5",			// add 6
			},
			{ 0, 0, 0, 0, 0, 0, 0, 0 }
		},*/

		/*
		{
			{
				"7",
				"3  2 1 5  4 6 7",	// a 12		e 10
					// "180",	// 6
				},
			{ 0, 0, 0, 0, 0, 0, 0, 0 }		// 2
		},
		*/
};

// LOGS = 0;
// debug("testFunction - begin\n\n");

template <class NType, class EleType, class NTypeBig, class EleTypeBig>
class Cls1 {
	QTypeVal Q;
	NType N;
public:
	Cls1() {
	}

	vector <ReturnCountTypeValue> testFunction(istream & cin) {

		// m(

		// cin >> Q;

		// for (size_t q = 0; q < Q; q++) {


		cin >> N;

		avl__self_balancing_tree <NTypeVal, EleTypeVal, NTypeValBig, EleTypeValBig> tree1(cin);

		int val;
		node* root = NULL;
		for (size_t i = 0; i < N; i++) {
			cin >> val;
			root = tree1.insert(root, val);
		}

		tree1.bfs_print(root);

		root = tree1.insert(root, 6);
		tree1.bfs_print(root);

		// int height = tree1.height(root);
		// cout << height << endl;


		// }




		vector <ReturnCountTypeValue> res;
		auto actual_result = 0;
		res.push_back(actual_result);

		return res;
	}

};


int main() {

	if (!DEBUG_MODE) {

		Cls1 <NTypeVal, EleTypeVal, NTypeValBig, EleTypeValBig> o1;
		o1.testFunction(cin);

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

			Cls1 <NTypeVal, EleTypeVal, NTypeValBig, EleTypeValBig> o1;
			// auto actual_result = o.testFunction(cin, q)[0];
			auto actual_result = o1.testFunction(cin)[0];

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
