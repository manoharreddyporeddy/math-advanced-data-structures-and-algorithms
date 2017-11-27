'use strict';

class sol {

    n_factorial(n) {
        // O(N)

        let prod = 1;
        while (n > 0) {
            prod = prod * n;
            n--;

            sol.a++;
        }
        return prod;
    }

    n_factorial_rec(n) {
        // O(N)

        if (n === 0) {  // since, X pow 0
            return 1; //      is 1
        }

        sol.b++;
        return  n * this.n_factorial_rec(n - 1);
    }

    runTests() {
        process.env.CS_TIME_LOGS = '1';
        //        console.time('TIME TAKEN: test: ');
        //        console.timeEnd('TIME TAKEN: test: ');
        //        console.time('TIME TAKEN: test: ');
        //        console.timeEnd('TIME TAKEN: test: ');

        console.time('TIME TAKEN: n_factorial: ');
        console.log("n_factorial(13): " + this.n_factorial(5));
        console.timeEnd('TIME TAKEN: n_factorial: ');
        console.log('a=' + sol.a + '\n');

        console.time('TIME TAKEN: n_factorial_rec: ');
        console.log("n_factorial_rec(13): " + this.n_factorial_rec(5));
        console.timeEnd('TIME TAKEN: n_factorial_rec: ');
        console.log('b=' + sol.b + '\n');

    }

}
sol.a = 0;
sol.b = 0;
sol.c = 0;
sol.d = 0;


module.exports = sol;
