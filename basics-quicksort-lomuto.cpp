#include "iostream"   // cout
#include "iomanip"    // setw
using namespace std;

int DoPartitionGetIndexOfPivotEleLomuto(int array[], int ibegin, int iend) {

  // Goal: Find   ipivot, return it
  //
  //  ibegin      ipivot       iend
  //        lesser      greater
  //
  //  SubGoal I:   all eles before ipivot index should be lesser or equal   than ele at ipivot
  //  SubGoal II:  all eles after  ipivot index should be greater           than ele at ipivot

  // Initially, let the pivot_ele be last element
  int pivot_ele = array[iend];

  // ipivot points to first element
  //    Finally will take the pivot_ele element's index
  int ipivot = ibegin;

  // for all elements expcept last ele
  for (int i = ibegin; i < iend; i++) {

    // if ele at i is less than pivot_ele (last ele)
    // Goal: Place the element before ipivot
    //    swap ipivot(starts from begin) element with i, and move ipivot ahead
    // this way we ensure elements before ipivot are lesser or equal (I: above)
    if (array[i] <= array[iend]) {

      // swap i with ipivot // no effect 1st time
      int temp = array[ipivot];
      array[ipivot] = array[i];
      array[i] = temp;

      ipivot++;
    }
  }

  // Now ipivot is somewhere in the middle
  //    i went till iend-1
  // And, elements before ipivot are lesser or equal
  //    => elements at & after ipivot are greater
  //
  // since i didnot touch last element at iend
  //    we did not compare ipivot to iend
  // => ele at ipivot is greater than pivot_ele at iend
  //  so swap ipivot & iend
  int temp = array[ipivot];
  array[ipivot] = array[iend];
  array[iend] = temp;

  // Now ipivot has pivot_ele value
  //  => ipivot has made required partition, eles before it are <=, eles after it are >
  // so return ipivot (since both SubGoal I && SubGoal II are satisfied)

  return ipivot;
}
void QuickSortLomuto(int array[], int ibegin, int iend) {
  if (ibegin <= iend) { // initially 0 to N-1
    int ipivot = DoPartitionGetIndexOfPivotEleLomuto(array, ibegin, iend); // get pivot position
    QuickSortLomuto(array, ibegin, ipivot - 1);  // call self, for before pivot position subarray
    QuickSortLomuto(array, ipivot + 1, iend);    // call self, for after pivot position subarray
  }
}
void QuickSortLomuto() {
  int array[] = { 9, 7, 5, 11, 12, 2, 14, 3, 10, 4, 0 };
  int N = sizeof(array) / sizeof(array[0]); // count = size of all eles/ size of single ele

  int ibegin = 0;
  int iend = N - 1;

  QuickSortLomuto(array, ibegin, iend);  // send all elements

  // print sorted array
  for (int t = 0; t <= N - 1; t++) {
    cout << setw(2) << array[t] << " ";
  }
  cout << endl;
}

int main() {
  QuickSortLomuto();
  return 0;
}
