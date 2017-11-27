#include "iostream"   // cout
#include "iomanip"    // setw
using namespace std;

void CopyTargetToSource(int source_array[], int ibegin, int iend, int target_array[]) {
  for (int i = ibegin; i <= iend; i++) {
    source_array[i] = target_array[i];
  }
}
void MergeSortMerge(int source_array[], int ibegin, int imid, int iend, int target_array[]) {

  // start from the ibegin, not 0
  int k = ibegin;

  // copy whichever is smaller into target, and move in source sub-arrays
  int i = ibegin, j = imid;
  while (i < imid && j <= iend) {
    if (source_array[i] <= source_array[j]) {
      target_array[k++] = source_array[i++];
    }
    else {
      target_array[k++] = source_array[j++];
    }
  }

  // copy any remaining in source sub-array1 to target
  while (i < imid) {
    target_array[k++] = source_array[i++];
  }

  // copy any remaining in source sub-array2 to target
  while (j <= iend) {
    target_array[k++] = source_array[j++];
  }
}
void MergeSortTopDownSplit(int source_array[], int ibegin, int iend, int target_array[]) {
  // ibegin & iend are both valid indexs in array

  // run size >=2 is good to sort, else it is 1 element array  so it is sorted
  if (ibegin + 1 <= iend) { // atleast 2 elements

    // int imid = (ibegin + iend) / 2;
    int imid = ibegin + (iend - ibegin) / 2;

    // split - recursive
    MergeSortTopDownSplit(source_array, ibegin, imid, target_array);
    MergeSortTopDownSplit(source_array, imid + 1, iend, target_array);

    // merge into target
    MergeSortMerge(source_array, ibegin, imid + 1, iend, target_array);

    // copy target to source
    CopyTargetToSource(source_array, ibegin, iend, target_array);
  }
}

void MergeSortTopDownRecursive() {
  const int N = 11; int source_array[N] = { 9, 7, 5, 11, 12, 2, 14, 3, 10, 4, 0 }; int target_array[N];
  //
  // const int N = 4; int source_array[N] = { 5,7,9,11 }, target_array[N];
  // const int N = 4; int source_array[N] = { 11,9,7,5 }, target_array[N];
  // const int N = 4; int source_array[N] = { 5,5,5,5 }, target_array[N];
  //
  // const int N = 3; int source_array[N] = { 5,6,7}, target_array[N];
  // const int N = 3; int source_array[N] = { 7,6,5 }, target_array[N];
  // const int N = 3; int source_array[N] = { 5,5,5 }, target_array[N];
  //
  // const int N = 2; int source_array[N] = { 5,6 }, target_array[N];
  // const int N = 2; int source_array[N] = { 6,5 }, target_array[N];
  // const int N = 2; int source_array[N] = { 5,5 }, target_array[N];

  // const int N = 1; int source_array[N] = { 5 }, target_array[N];
  // const int N = 1; int source_array[N] = { -1 }, target_array[N];
  // const int N = 1; int source_array[N] = { 0 }, target_array[N];

  if (N == 1) {
    target_array[0] = source_array[0];
  }
  else {
    /*
    first split into small sizes
    then, merge*/
    MergeSortTopDownSplit(source_array, 0, N - 1, target_array);
  }

  // print sorted array
  for (int t = 0; t <= N - 1; t++) {
    cout << setw(2) << target_array[t] << " ";
  }
  cout << endl;
}

int main() {
  MergeSortTopDownRecursive();
  return 0;
}
