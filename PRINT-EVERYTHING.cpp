

	void print() {

		printf("%c", 'c');

		cout << endl;	// ok
		cout << "\n";  // better sometimes for performance

		cout << 'a' << "\n";
		cout << "abc" << "\n";
		cout << 1 << "\n";

		cout << "[" << 100 << "," << 200 << "]" << "\n";

		cout << setw(10) << 100 << "\n";
		cout << setw(10) << setfill('-') << 100 << "\n";


		string s1 = "hello";
		cout << s1 << "\n";

		stringstream output1;
		output1 << "hello" << "\n";
		output1 << "world" << "\n";
		cout << output1.str();
	}


	template <class T>
	void printA(T *A, size_t N, bool bNewLine = true) {	// print A[]
		for (size_t i = 0; i < N; i++) {
			cout << A[i] << " ";
		}
		if (bNewLine) {
			cout << "\n";
		}
	}

	template <class T>
	void printVD(T c1, bool bNewLine = true) { // print vector<T>, deque<T>
		for (size_t i = 0; i < c1.size(); i++) {
			cout << c1[i] << " ";
		}
		if (bNewLine) {
			cout << "\n";
		}
	}

	template <class T>
	static void printVVDD(T vv1, bool bNewLine = true) { // print vector<vector<T>>, deque<deque<T>>
		for (size_t i = 0; i < vv1.size(); i++) {
			printVD(vv1[i], bNewLine);
		}
		if (bNewLine) {
			cout << "\n";
		}
	}

	template <class T>
	static void printM(const T &m1, bool bNewLine = true) {	// print map<T>
		for (auto kv1 : m1) {
			cout << kv1.first << " " << kv1.second << endl;
		}
		if (bNewLine) {
			cout << "\n";
		}
	}


