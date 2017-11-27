#include "iostream"
using namespace std;

int GcdEuclideanAlgorithm(int x, int y) {
  int remainder;

  // while the denominator is not 0
  while (y != 0) {
    // calc remainder        (generally is smaller than denominator)
    // copy the denominator  (generally is smaller than numerator)     into numerator
    // copy the remainder    (generally is smaller than denominator)   into denominator
    remainder = x % y;
    x = y;
    y = remainder;
  }

  // what if (numerator is smaller than denominator)?, they get swapped, since remainder becomes numerator
  
  return x;
}

void CalcGcd() {
  cout << GcdEuclideanAlgorithm(12, 18) << endl;      // Output: 6
  cout << GcdEuclideanAlgorithm(18, 12) << endl;      // Output: 6
  cout << GcdEuclideanAlgorithm(14, -4) << endl;      // Output: 2
  cout << GcdEuclideanAlgorithm(-4, 14) << endl;      // Output: 2
}

int main () {
    CalcGcd();
    return 0;
}
