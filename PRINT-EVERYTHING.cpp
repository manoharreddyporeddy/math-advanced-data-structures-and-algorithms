

void use() {
     printf("%c", 'c') ;	
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
