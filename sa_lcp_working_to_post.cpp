#include <iostream>
#include <sstream> // stringstream
#include <limits> // numeric_limits
#include <vector> // vector
#include <tuple> // tuple
#include <iomanip> // setw, setfill
#include <cassert> // assert
#include <set> // set
#include <map> // map
#include <algorithm> // min
#include <fstream> // ifstream

/**/
// #include <cmath>
// #include <cstdio>
// #include <cstdint> // uint8_t

using namespace std;

// ------------- utility functions - begin ------------------

template <class T>
void ScanString(istream &cin1, T &str1) {
  cin1 >> str1;
  // string s2;
  // assert((min1 <= number) && (number <= max1));
}

template <class T>
void ScanNumber(istream &cin1, T & number,
  const T &min1 = numeric_limits<T>::min(), const T &max1 = numeric_limits<T>::max(),
  const string &message1 = ""
)
{
  while (true) {
    if (message1.size()) {
      cout << message1.c_str() << endl;
    }
    if (cin1 >> number) {
      assert((min1 <= number) && (number <= max1));
      break;
    }
    cin1.clear();
    cin1.ignore(numeric_limits<int>::max(), '\n');
  }
}

template <class T>
void ScanNumberArray(
  istream &cin1, vector<T> &number_array, const int number_of_eles,
  const T &min1 = numeric_limits<T>::min(), const T &max1 = numeric_limits<T>::max(),
  bool reverse = false,
  const string &message1 = ""
)
{
  number_array.resize(number_of_eles);

  int reverse_start_index = 0;
  if (reverse) {
    reverse_start_index = number_of_eles - 1;
  }

  for (int i = 0; i < number_of_eles; i++) {
    T ele;
    ScanNumber(cin1, ele, min1, max1, message1);

    number_array[reverse_start_index - i] = (ele);
  }
}

template <class T>
void ScanTriplet(istream &cin1, tuple<T, T, T> &triplet1,
  const T &min1 = numeric_limits<T>::min(), const T &max1 = numeric_limits<T>::max(),
  const string &message1 = "") {
  T ele;
  ScanNumber(cin1, ele, min1, max1);   get<0>(triplet1) = ele;
  ScanNumber(cin1, ele, min1, max1);   get<1>(triplet1) = ele;
  ScanNumber(cin1, ele, min1, max1);   get<2>(triplet1) = ele;
  // cin1 >> get<0>(triplet1) >> get<1>(triplet1) >> get<2>(triplet1);
}

template <class T>
void ScanMatrix(istream &cin1, vector<vector<T>> &input_matrix, const int &number_of_rows, const int &number_of_cols,
  const T &min1 = numeric_limits<T>::min(), const T &max1 = numeric_limits<T>::max(),
  const string &message1 = "")
{
  for (int i = 0; i < number_of_rows; i++) {
    for (int j = 0; j < number_of_rows; j++) {
      ScanNumber<T>(cin1, input_matrix[i][j], min1, max1);
    }
  }
}

template <class T>
void ConvertArrayToCummulativeArray(
  vector<T> &number_array, const int number_of_eles
)
{
  if (number_of_eles > 0) {
    int cummulative_sum = number_array[0];
    for (int i = 1; i < number_of_eles; i++) {
      cummulative_sum += number_array[i];
      number_array[i] = cummulative_sum;
    }
  }
}

// ------------- utility functions - end ------------------




// THE START
namespace ns_lps_chars {
  class LPS {
    string s;

    vector<size_t> suffix_array;	// suffix_array, suffix Solve indexes in sorted order
    vector<size_t> lcp_array;		// LCP_array, longest_common_prefix_lengths of suffix_array ele diffs

  public:
    LPS(string &s1) {
      s = s1;
    }

    auto TwoBinarySearch(string P) {
      size_t N = suffix_array.size();

      size_t lsave, l = 0, mid, r = N;

      while (l < r) {
        mid = (l + r) / 2;
        if (s.substr(suffix_array[mid]) < P) { // v_sorted_suffixes_and_startingindexes[mid].first
          l = mid + 1;
        }
        else {
          r = mid;
        }
      }
      lsave = l; // will be equal, if matches

      r = N;
      while (l < r) {
        mid = (l + r) / 2;
        if (s.substr(suffix_array[mid]) > P) { // v_sorted_suffixes_and_startingindexes[mid].first
          r = mid;
        }
        else {
          l = mid + 1;
        }
      }
      // r; // will be equal+1, if matches

      return make_pair(lsave, r);
    }

    auto CommonPrefixCount_(const string &s1, const string &s2) {
      size_t c = 0;
      for (auto i = s1.begin(), j = s2.begin(); i != s1.end(); i++, j++) {
        if (*i == *j) {
          c++;
        }
        else {
          break;
        }
      }
      return c;
    }

    auto CommonPrefixCount2(const string &s1, const string &s2) {
      size_t c;
      // send 1st arg as small/eq
      if (s1.size() < s2.size()) { c = CommonPrefixCount_(s1, s2); }
      else { c = CommonPrefixCount_(s2, s1); }
      return c;
    }

    auto CommonPrefixCount(const string &s1, const string &s2) {
      size_t min_size = min(s1.size(), s2.size());

      size_t common_count = 0;
      for (size_t i = 0; i < min_size; i++) {
        if (s1[i] != s2[i]) {
          break;
        }
        common_count++;
      }
      return common_count;
    }

    void PrintSuffixesOfString() {
      cout << "suffixes of string: " << s << endl << endl;
      cout << setw(20) << "starting index" << setw(20) << "suffix" << endl;
      for (size_t i = 0; i < s.size(); i++) {
        cout << setw(20) << i << setw(20) << s.substr(i) << endl;
      }
      cout << endl;
    }
    void PrintSuffixArray() {
      cout << "suffix array (sa) of: " << s << endl << endl;
      cout << std::left << "  "
        << setw(9) << "sa index"
        << setw(35) << "sa value (original string index)"
        << setw(25) << "original string suffix"
        << endl;
      for (size_t i = 0; i < suffix_array.size(); i++) {
        cout << std::left << "  "
          << setw(9) << i
          << setw(35) << suffix_array[i]
          << setw(25) << s.substr(suffix_array[i])
          << endl;
      }
      cout << endl;
    }

    void PrintLcpArray() {
      cout << "lcp array (la) (longest common prefix lengths array)" << endl << endl;
      cout << std::left << "  "
        << setw(10) << "(sa index)"
        << setw(20) << "(sa previous)"
        << setw(20) << "(sa current)"
        << setw(10) << "la index"
        << setw(10) << "la value"
        << endl;
      cout << std::left << "  "
        << setw(10) << 0
        << setw(20) << ""
        << setw(20) << s.substr(suffix_array[0]).c_str()
        << setw(10) << 0
        << setw(10) << -1 << endl;
      for (size_t i = 1; i < suffix_array.size(); i++) {
        cout << std::left << "  "
          << setw(10) << i
          << setw(20) << s.substr(suffix_array[i - 1]).c_str()
          << setw(20) << s.substr(suffix_array[i]).c_str()
          << setw(10) << i
          << setw(10) << lcp_array[i] << endl;
      }
      cout << endl;
    }

    void GetSuffixArrayNaive() {
      suffix_array.clear();

      // print
      PrintSuffixesOfString();

      vector<pair<string, size_t>> v_sorted_suffixes_and_startingindexes;
      for (size_t i = 0; i < s.size(); i++) {
        v_sorted_suffixes_and_startingindexes.push_back({ s.substr(i), i });
      }

      sort(v_sorted_suffixes_and_startingindexes.begin(), v_sorted_suffixes_and_startingindexes.end());

      // suffix_array = array of startingpos_of_sorted_suffixes__vector
      //    has starting positions of these sorted suffixes
      //		A[3] contains the value 4, refers to the suffix starting at position 4 within S, which is the suffix ana$
      for (auto key_val : v_sorted_suffixes_and_startingindexes) {
        suffix_array.push_back(key_val.second);
      }

      // print
      PrintSuffixArray();
    }

    // SuffixInfo for each suffix, at any step
    typedef struct temp {
      int p_original_index; // original index of suffix
      int suffix_prev_step_rank;  // rank for first half of suffix
      int suffix_current_step_rank;  // rank for second half of suffix
    } SuffixInfo;

    // Compare of (prefix parts of) suffix infos in constant time
    static bool SuffixInfoComparisonFunction(SuffixInfo i, SuffixInfo j) {
      // true if lessthan, preivous step or current step
      if (i.suffix_prev_step_rank == j.suffix_prev_step_rank) {
        return i.suffix_current_step_rank < j.suffix_current_step_rank;
      }
      else {
        return i.suffix_prev_step_rank < j.suffix_prev_step_rank;
      }
    }

    void GetSuffixArrayNLogN(const char kStartAlphabet = 'a') { // Solve alphabet can be 'a', or 'A' depending on your problem, pass param if required
      suffix_array.clear();

      // print
      // PrintSuffixesOfString();

      size_t suffix_count = s.size();

      // no. of compare_steps to calculate suffix array
      int compare_steps = (int)ceil(log(suffix_count) / log(2));

      vector<vector<int>> P_suffix_rank_array_at_a_step(compare_steps + 1, vector<int>(suffix_count));
      //        has the rank of each suffix on each compare_step
      // [i][j] denotes rank of jth suffix at ith compare_step

      // at compare_step, we get ranks, by logically (not in real) compare 2 power compare_step chars of all suffixes
      //  logically because if calculated once, can be reused in next compare_step, due to the nature of suffixes of same string (we use jump below)
      //  so only once we compare (INITIALIZATION STEP), then do logical comparisions (NEXT REMAINING (LOGICAL) STEPS)


      // INITIALIZATION STEP
      //
      // compare_step = 1
      // get ranks of all suffixes, by comparing 1st char (2 power 0 chars) of all suffixes
      //    for single character, ranks will be 'a' = 0, 'b' = 1, 'c' = 2 ... 'z' = 25, so (char - 'a') will give rank
      for (size_t i = 0; i < suffix_count; i++) {
        P_suffix_rank_array_at_a_step[0][i] = s[i] - kStartAlphabet; // 'a'
      }


      // NEXT REMAINING (LOGICAL) STEPS
      //  these will be log N steps, since we double compare char count each time (using jump)
      //
      // stores details of all suffixes of current step
      vector<SuffixInfo> L_suffix_info_array_at_current_step(suffix_count);

      // iterate log(n) times till all suffixes are sorted
      //    'c_stp' keeps the track of number of compare_step, (2 power c_stp) chars to be compared logically in all suffixes
      //    'jump' store length of suffix which is going to be compared

      //compare_steps to calculate suffix array
      for (int c_stp = 1, jump = 1; c_stp <= compare_steps; c_stp++, jump <<= 1) {  // jump <<= 1  means jump multiplied by 2
        // LOGICAL STEP: PART 1
        // logical step: at each compare_step (c_stp) we initialize suffix info for each suffix with values computed from previous compare_step (c_stp-1)
        // details:
        //    for each suffix
        //      calculate 2 part rank, 1st (2powStep/2 suffix substring) part is from previous rank and second (2powStep/2 suffix substring) part is calculated from previous caliculated values (after jumping 2powStep/2 down each time)
        //      save the original index, otherwise would be lost after sorting (PART 2 below)
        for (size_t i = 0; i < suffix_count; i++) {
          L_suffix_info_array_at_current_step[i].suffix_prev_step_rank = P_suffix_rank_array_at_a_step[c_stp - 1][i];

          if (i + jump < suffix_count) { L_suffix_info_array_at_current_step[i].suffix_current_step_rank = P_suffix_rank_array_at_a_step[c_stp - 1][i + jump]; }
          else { L_suffix_info_array_at_current_step[i].suffix_current_step_rank = -1; }

          L_suffix_info_array_at_current_step[i].p_original_index = i;
        }


        // LOGICAL STEP: PART 2
        // sort step, based on 2 parts
        sort(L_suffix_info_array_at_current_step.begin(), L_suffix_info_array_at_current_step.begin() + suffix_count, SuffixInfoComparisonFunction);


        // LOGICAL STEP: PART 3
        // give ranks to already sorted suffixes, for this step

        // LOGICAL STEP: PART 31
        // for 1st suffix, give rank 0
        int rank = 0;
        // Initialize rank for rank 0 suffix after sorting to its original index in P_suffix_rank_array_at_a_step array
        P_suffix_rank_array_at_a_step[c_stp][L_suffix_info_array_at_current_step[0].p_original_index] = rank;

        // LOGICAL STEP: PART 32
        // for rest of suffixes, give rank as below
        //  if current and previous is same, no rank change
        //  else increment rank
        for (size_t i = 1; i < suffix_count; i++) {
          if (
            L_suffix_info_array_at_current_step[i].suffix_prev_step_rank == L_suffix_info_array_at_current_step[i - 1].suffix_prev_step_rank &&
            L_suffix_info_array_at_current_step[i].suffix_current_step_rank == L_suffix_info_array_at_current_step[i - 1].suffix_current_step_rank) {

            //  if current and previous is same, no rank change
            P_suffix_rank_array_at_a_step[c_stp][L_suffix_info_array_at_current_step[i].p_original_index] = rank;
          }
          else {
            //  if current and previous is diff, increment rank
            P_suffix_rank_array_at_a_step[c_stp][L_suffix_info_array_at_current_step[i].p_original_index] = ++rank;
          }
        }
      }

      // Print suffix array
      //  original indexes from L_suffix_info_array_at_current_step will give us this
      suffix_array.resize(suffix_count);
      for (size_t i = 0; i < suffix_count; i++) {
        suffix_array[i] = L_suffix_info_array_at_current_step[i].p_original_index;
      }

      // print
      // PrintSuffixArray();

      // sources
      //  https://en.wikipedia.org/wiki/Suffix_array (basics, and what all are there)
      //  http://e-maxx.ru/algo/suffix_array (took some help in understanding from here)
      //  http://algorithmsandme.in/2015/01/suffix-array/ (above is more like this)
      //    https://www.hackerrank.com/challenges/ashton-and-string/topics  (nearly same as above)
      //  https://youtu.be/HKPrVm5FWvg?t=709 (took some help in understanding from here, especially how logical step works, understood full only after writing above)
    }

    void SearchSuffixUsingSuffixArray(const string &p) {
      cout << "two binary search for suffix: " << p << endl;

      if (suffix_array.size() == 0) {
        cout << "Create suffix array first" << endl;
        return;
      }

      auto range = TwoBinarySearch(p);
      for (auto i = range.first; i < range.second; i++) {
        cout << "\tfound "
          << setw(10) << s.substr(suffix_array[i])
          << setw(10) << " at index " << suffix_array[i]
          << endl;
      }
      cout << endl;
    }

    // LCP array = longest common prefix lengths array
    //  LCP array H is  array of  longest common prefix lengths   shared by   lexicographically consecutive suffixes //  constructed by comparing lexicographically consecutive suffixes to determine their longest common prefix < starting length is undefined = -1 >
    void CreateLcpArrayNaive() {
      lcp_array.clear();

      // initial one is -1
      lcp_array.push_back(-1);

      for (size_t i = 1; i < suffix_array.size(); i++) {

        const string &s1 = s.substr(suffix_array[i]);
        const string &s2 = s.substr(suffix_array[i - 1]);

        // get common prefix
        size_t c = CommonPrefixCount(s1, s2);
        lcp_array.push_back(c);
      }

      // print
      PrintLcpArray();
    }

    void CreateLcpArrayKasai() {
      lcp_array.clear();

      int n = s.size(), k = 0;
      lcp_array.resize(n, 0);

      vector<size_t> rank_array(n, 0);

      for (int i = 0; i < n; i++) {
        rank_array[suffix_array[i]] = i;
      }

      /*
      // print
      for (size_t i = 0; i < rank_array.size(); i++) {
        cout << setw(20) << i
          << setw(20) << rank_array[i]
          << setw(20) << s.substr(rank_array[i])
          << endl;
      }
      cout << endl;*/

      for (int i = 0; i < n; i++, k ? k-- : 0) {
        if (rank_array[i] == n - 1) {
          k = 0;
          continue;
        }
        int j = suffix_array[rank_array[i] + 1];
        while (
          (i + k < n) &&
          (j + k < n) &&
          (s[i + k] == s[j + k])
          ) {
          k++;
        }

        lcp_array[rank_array[i] + 1] = k;	// WATCH OUT: inserted +1
      }

      lcp_array[0] = -1;	// WATCH OUT: inserted -1 at 0 pos

      // print
      // PrintLcpArray();
    }

    void CreateLcpArrayNaive__ToString() {
      GetSuffixArrayNLogN(); // pass 'A' param if for string in CAPS
      CreateLcpArrayKasai();

      // print
      // PrintSuffixArray(); PrintLcpArray();

      auto range = TwoBinarySearch(s);
      auto saIndex = range.first; // ASSUME FOUND // CHECK
      // cout << suffix_array[saIndex] << endl;

      string s1(1, char(s[0]));
      auto range1 = TwoBinarySearch(s1);
      auto saIndex1 = range1.first; // CHECK

      string s2(1, char(s[0] + 1));
      auto range2 = TwoBinarySearch(s2);
      auto saIndex2 = range2.first; // CHECK

      size_t prev_common_len = s.length();
      unsigned long long sum = prev_common_len;
      for (long long i = saIndex; i > saIndex1; i--) {
        // cout << lcp_array[i];
        prev_common_len = min(lcp_array[(size_t)i], prev_common_len);
        sum += prev_common_len;
        // sum += lcp_array[i];
        // cout << "\t sum: " << sum << endl;
      }
      if (saIndex + 1 < saIndex2) {
        prev_common_len = lcp_array[saIndex + 1];
        sum += prev_common_len;
      }
      for (size_t i = saIndex + 2; i < saIndex2; i++) {
        prev_common_len = min(lcp_array[i], prev_common_len);
        sum += prev_common_len;
      }
      cout << sum;


      return;
      /*
            for (size_t i = 1; i < suffix_array.size(); i++) {

              const string &s1 = s.substr(suffix_array[i]);
              const string &s2 = s.substr(suffix_array[i - 1]);

              // get common prefix
              size_t c = CommonPrefixCount(s1, s2);
              lcp_array.push_back(c);
            }

            // print
            PrintLcpArray();
            */
    }


  };

  void Solve(istream &cin_) {
    string s;
    cin_ >> s;

    LPS o1(s);

    o1.CreateLcpArrayNaive__ToString();

    // o1.GetSuffixArrayNaive();
    // o1.GetSuffixArrayNLogN(); // pass 'A' param if for string in CAPS

    // o1.SearchSuffixUsingSuffixArray("gger");
    // o1.SearchSuffixUsingSuffixArray("gge");

    // o1.CreateLcpArrayNaive();
    // o1.CreateLcpArrayKasai();

    cout << endl;
  }

  void Start() {
    // CONSOLE
#if 1
    stringstream ss;
    // ss << "banana$" << endl;
    // ss << "abaab" << endl;    // suffix array is 2,3,0,4,1
    // ss << "blogger" << endl;  // suffix array is 0,5,4,3,1,2,6
    // ss << "banana" << endl;   // suffix array is 5,3,1,0,4,2
    // ss << "4" << endl;

    ss << "4" << endl;
    ss << "ababacaa" << endl;  // suffix array is 0,5,4,3,1,2,6
    ss << "bbeeabcadeecbcadae" << endl;
    ss << "ababaa" << endl;  // suffix array is 0,5,4,3,1,2,6
    ss << "aa" << endl;  // suffix array is 0,5,4,3,1,2,6
    istream &cin_ = ss;

    // ifstream ifs1("string_similarity_input01.txt");
    // istream &cin_ = ifs1;

#else
    istream &cin_ = cin;
#endif
    // cin_.ignore(numeric_limits<streamsize>::max(), '\n'); // skip bad input till new line

    short T;
    cin_ >> T;
    while (T--) {
      Solve(cin_);
    }
  }
}

int main(int argc, char** argv) {
  ns_lps_chars::Start();
  return 0;
}
// THE END




// create input constraints
//    assert them
// write optimal solution
// iterate all input, test all test cases
// do automated testing
// after 1 operation what is x?   after n operations what is x?
// cout << sizeof(int) << "  " << sizeof(long); // 4
// (int)1e2 = 100
// use long long, when not specified (dont use unsigned long long)
// set will remove duplicates, use multiset if required
// distinct substrings lexicographical order => set
//    set size wont increase if duplicates
// size() is constant complexity
//    use it as to check if duplciates whie insertion isntead of find
//    old size != new size (after insertion), is better than find(to_insert) then insert
//




/*
suffixes of string: blogger

starting index              suffix
0             blogger
1              logger
2               ogger
3                gger
4                 ger
5                  er
6                   r

suffix array (sa)

sa index sa value (original string index)   original string suffix
0        0                                  blogger
1        5                                  er
2        4                                  ger
3        3                                  gger
4        1                                  logger
5        2                                  ogger
6        6                                  r

lcp array (la) (longest common prefix lengths array)

(sa index)(sa previous)  (sa current)   la index la value
0                        blogger        0         -1
1         blogger        er             1         0
2         er             ger            2         0
3         ger            gger           3         1
4         gger           logger         4         0
5         logger         ogger          5         0
6         ogger          r              6         0

*/






extern string morgan_and_a_string__outputs[];

void morgan_and_a_string(string &s1, string &s2, long long &t) {
  auto i = s1.begin(), j = s2.begin();
  for (; i != s1.end() && j != s2.end();) {
    if (*i == *j) {
      cout << (*i);

      int temp = 1;
      while (
        ((i + temp) != s1.end() && (j + temp) != s2.end()) &&
        (*(i + temp) == *(j + temp))
        ) {
        temp++;
      }

      if ((i + temp) == s1.end() && (j + temp) == s2.end()) {

      }
      else if ((i + temp) == s1.end()) {
        j++;
      }
      else if ((j + temp) == s2.end()) {
        i++;
      }
      else {
        if (*(i + temp) < *(j + temp)) {
          i++;
        }
        else {
          j++;
        }
      }
    }
    else if (*i < *j) {
      cout << (*i);
      i++;
    }
    else {
      cout << (*j);
      j++;
    }
  }

  while (i != s1.end()) {
    cout << (*i);
    i++;
  }

  while (j != s2.end()) {
    cout << (*j);
    j++;
  }

  cout << endl;
}

string morgan_and_a_string__outputs[] = {
  // 4 set below
  "BABD",
  "BABD",
  "DAJACKNIEL",
  "AABABACABACABA",

  // 4 set below
  "BBBB",

  // 6 set below
  "BBBBB",
  "BBBBB",
  "BBABB",
  "BBABB",
  "BBBBD",
  "BBBBD",

  // 6 set below
  "BBABBB",
  "BBABBB",
  "BBBBBD",
  "BBBBBD",
  "BBABBD",
  "BBABBD",

};

int main11(int argc, char** argv) {
  // CONSOLE

#if 1
  // TEST
  stringstream ss;
  ss << "1" << endl;
  ss << "nvzjkcahjwlhmdiuobjdwbanmvrtadopapbktdtezellktgywrdstdhhayaadqrdhspavjgxprk" << endl;
  ss << "2071" << endl;

  ss << "17" << endl;

  // 4 set below
  ss << "BD" << endl;
  ss << "BA" << endl;
  ss << "BA" << endl;
  ss << "BD" << endl;
  ss << "JACK" << endl;
  ss << "DANIEL" << endl;
  ss << "ABACABA" << endl;
  ss << "ABACABA" << endl;

  // 1 set below
  ss << "BB" << endl;
  ss << "BB" << endl;

  // 6 set below
  ss << "BBB" << endl;
  ss << "BB" << endl;
  ss << "BB" << endl;
  ss << "BBB" << endl;
  //
  ss << "BBA" << endl;
  ss << "BB" << endl;
  ss << "BB" << endl;
  ss << "BBA" << endl;
  //
  ss << "BBD" << endl;
  ss << "BB" << endl;
  ss << "BB" << endl;
  ss << "BBD" << endl;

  // 6 set below
  ss << "BBA" << endl;
  ss << "BBB" << endl;
  ss << "BBB" << endl;
  ss << "BBA" << endl;
  //
  ss << "BBD" << endl;
  ss << "BBB" << endl;
  ss << "BBB" << endl;
  ss << "BBD" << endl;
  //
  ss << "BBA" << endl;
  ss << "BBD" << endl;
  ss << "BBD" << endl;
  ss << "BBA" << endl;


  ifstream ifs1("ashton_input10.txt");

  // istream &cin_ = ss;
  istream &cin_ = ifs1;
#else
  istream &cin_ = cin;
#endif



  // cin_.ignore(numeric_limits<streamsize>::max(), '\n'); // skip bad input

  long long T;
  cin_ >> T;
  long long t = 0;
  for (; t < T; t++)
  {
    string s1;
    string s2;

    cin_ >> s1;
    cin_ >> s2;

    morgan_and_a_string(s1, s2, t);
  }

  return 0; // main
}

// THE END

