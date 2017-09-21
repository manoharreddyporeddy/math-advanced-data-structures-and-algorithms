
void know_bits_and_bytes() {

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
}


/X
hackerrank
	size of char:                 -128 127
	size of unsigned char:         0 255
	size of short:                -32768 32767                     // 3 X 10^4
	size of unsigned short:        0 65535                         // 6 X 10^4
	size of int:                  -2.14748e+09 2.14748e+09         //   2 X 10^9
	size of unsigned int:          0 4.29497e+09                   //   4 X 10^9
	size of long:                 -9.22337e+18 9.22337e+18         //     9 X 10^18
	size of unsigned long:         0 1.84467e+19                   //     1 X 10^19
	size of long long:            -9.22337e+18 9.22337e+18         // 9 X 10^18
	size of unsigned long long:    0 1.84467e+19                   // 1 X 10^19

	// summary:   long  and  long long  are same on hackerrank --- so use (short, int, long) only for integers, signed or unsigned as required

local machine/ laptop
	size of char:                 -128 127
	size of unsigned char:         0 255
	size of short:                -32768 32767                      // 3 X 10^4
	size of unsigned short:        0 65535                          // 6 X 10^4
	size of int:                  -2.14748e+09 2.14748e+09          //   2 X 10^9
	size of unsigned int:          0 4.29497e+09                    //   4 X 10^9
	size of long:                 -2.14748e+09 2.14748e+09          //     2 X 10^9
	size of unsigned long:         0 4.29497e+09                    //     4 X 10^9
	size of long long:            -9.22337e+18 9.22337e+18          // 9 X 10^18
	size of unsigned long long:    0 1.84467e+19                    // 1 X 10^19	
X/
