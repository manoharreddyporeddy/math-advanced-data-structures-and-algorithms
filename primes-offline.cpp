#define NTypeVal unsigned long

template <class NType>
class primes_list {
	vector <NType> primes;	// dummy, 1st prime, 2nd prime, so on
	vector <bool> is_primes;

public:
	primes_list(NType N) {		// ** NOTE:  N > 1  **

		is_primes.resize(N + 1);	// 2 to N
		std::fill(is_primes.begin(), is_primes.end(), true);

		auto sqrtN = sqrt(N);
		for (NType i = 2; i <= sqrtN; i++) {
			if (is_primes[i] == true) {

				NType isq = i*i;
				for (NType j = isq; j <= N; j += i) {
					is_primes[j] = false;
				}
			}
		}

		primes.push_back(0); // dummy value
		for (NType i = 2; i <= N; i++) {
			if (is_primes[i] == true) {
				primes.push_back(i);
			}
		}

	}
};
