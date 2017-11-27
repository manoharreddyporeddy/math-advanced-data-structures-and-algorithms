'use strict';

class sol {

    x_pow_n(X, n) {
        // O(N)

        let prod = 1;
        while (n > 0) {
            prod *= X;
            n--;
            sol.a++;
        }
        return prod;
    }

    x_pow_n_rec(X, n) {
        // O(N)

        if (n === 0) {  // since, X pow 0
            return 1; //      is 1
        }

        sol.b++;
        return  X * this.x_pow_n_rec(X, n - 1);
    }

    x_pow_n_rec_faster(X, n) {
        // O(logN)

        if (n === 0) {  // since, X pow 0
            return 1; //      is 1
        } else if (n % 2 === 0) {
            sol.c++;// even power
            let single = this.x_pow_n_rec_faster(X, n / 2); //      get the power half
            return single * single; //      square it
        } else {
            sol.c++;// odd power
            return X * this.x_pow_n_rec_faster(X, n - 1); //      make it even power
        }
    }

    modular_exponentiation__x_pow_n_modulo_m(X, n, M) {
        // O(logN)

        // (a * b) % M = (a%M * b%M) % M
        // (X pow n) = (X pow n/2) * (X pow n/2), if n is even          2 pow 4 is  2pow2 * 2pow2
        // (X pow n) = (X) * (X pow n-1), if n is odd                   2 pow 5 is  2 * 2pow4
        // so,
        // (X pow n) % M =
        //      if n is 0, is 1
        //      if n is even, ( (x pow N/2) % M  *  (x pow N/2) % M )  % M
        //      if n is odd,  ( (x) % M  *  (x pow N-1) % M )  % M


        if (n === 0) {  // since, X pow 0
            return 1; //      is 1
        } else if (n % 2 === 0) {
            sol.d++;// even power
            let single = this.modular_exponentiation__x_pow_n_modulo_m(X, n / 2, M); //      get the power half
            return (single * single) % M; //      square it
        } else {
            sol.d++;// odd power
            return (X % M * this.modular_exponentiation__x_pow_n_modulo_m(X, n - 1, M)) % M; //    make it even power
        }
    }

    runTests() {
        process.env.CS_TIME_LOGS = '1';
        //        console.time('TIME TAKEN: test: ');
        //        console.timeEnd('TIME TAKEN: test: ');
        //        console.time('TIME TAKEN: test: ');
        //        console.timeEnd('TIME TAKEN: test: ');

        console.time('TIME TAKEN: x_pow_n: ');
        console.log("x_pow_n(13, 131): " + this.x_pow_n(13, 131));
        console.timeEnd('TIME TAKEN: x_pow_n: ');
        console.log('a=' + sol.a);
        console.log('\n');

        console.time('TIME TAKEN: x_pow_n_rec: ');
        console.log("x_pow_n_rec(13, 131): " + this.x_pow_n_rec(13, 131));
        console.timeEnd('TIME TAKEN: x_pow_n_rec: ');
        console.log('b=' + sol.b);
        console.log('\n');

        console.time('TIME TAKEN: x_pow_n_rec: ');
        console.log("x_pow_n_rec_faster(13, 131): " + this.x_pow_n_rec_faster(13, 131));
        console.timeEnd('TIME TAKEN: x_pow_n_rec: ');
        console.log('c=' + sol.c);
        console.log('\n');


        console.time('TIME TAKEN: x_pow_n_rec: ');
        // console.log("modular_exponentiation__x_pow_n_modulo_m(5, 2, 7): " + this.modular_exponentiation__x_pow_n_modulo_m(5, 2, 7));  // 4
        // console.log("modular_exponentiation__x_pow_n_modulo_m(5, 3, 7): " + this.modular_exponentiation__x_pow_n_modulo_m(5, 3, 7));  // 6
        console.log("modular_exponentiation__x_pow_n_modulo_m(5, 3, 7): " + this.modular_exponentiation__x_pow_n_modulo_m(13, 131, 7));  // 6
        console.timeEnd('TIME TAKEN: x_pow_n_rec: ');
        console.log('d=' + sol.d);
        console.log('\n');
    }

}
sol.a = 0;
sol.b = 0;
sol.c = 0;
sol.d = 0;


module.exports = sol;
