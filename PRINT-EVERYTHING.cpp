

	template <class T>
	static void printA(T *A, size_t N, bool bNewLine = true) {	// print A[]
		for (size_t i = 0; i < N; i++) {
			cout << A[i] << " ";
		}
		if (bNewLine) {
			cout << "\n";
		}
	}
