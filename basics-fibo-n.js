'use strict';

function Object_values(obj) {
    let vals = [];
    for (const prop in obj) {
        vals.push(obj[prop]);
    }
    return vals;
}

class sol {

    fibonacci_series_upto_n(n) {
        // O(N)

        let res = [];

        let first = 0;
        if (n < first) {   // -1
            return;
        }
        res.push(first);
        sol.a++;

        let second = 1;
        if (n < second) {   // 0
            return;
        }
        res.push(second);
        sol.a++;

        let third;
        while (1) {
            third = first + second;
            if (n < third) {
                break;
            }
            res.push(third);

            first = second;
            second = third;

            sol.a++;
        }

        console.log(res.join(', '));
    }

    fibonacci_series_upto_n_rec(i, n, res) {
        // a bit less than O(2^N)

        sol.b++;

        if (i < 0) {   // -1
            return 0;
        }

        if (i <= 1) {   // 0 and 1
            res[i] = i;
            return i;
        }

        let a = this.fibonacci_series_upto_n_rec(i - 1, n, res);
        let b = this.fibonacci_series_upto_n_rec(i - 2, n, res);
        if (n < a + b) {
            return a + b;
        }

        res[i] = a + b;
        return a + b;
    }

    fibonacci_series_upto_n__with_memoization__rec(i, n, res) {
        // a bit less than O(2^N)
        //    but faster due to memoization

        if (res[i]) {   // memoization
            return res[i];
        }

        sol.c++;

        if (i < 0) {   // -1
            return 0;
        }

        if (i <= 1) {   // 0 and 1
            res[i] = i;
            return i;
        }

        let a = this.fibonacci_series_upto_n__with_memoization__rec(i - 1, n, res);
        let b = this.fibonacci_series_upto_n__with_memoization__rec(i - 2, n, res);
        if (n < a + b) {
            return a + b;
        }

        res[i] = a + b;
        return a + b;
    }

    runTests() {
        process.env.CS_TIME_LOGS = '1';
        //        console.time('TIME TAKEN: test: ');
        //        console.timeEnd('TIME TAKEN: test: ');
        //        console.time('TIME TAKEN: test: ');
        //        console.timeEnd('TIME TAKEN: test: ');

        console.time('TIME TAKEN: fibonacci_series_upto_n: ');
        console.log("fibonacci_series_upto_n(13): ");
        this.fibonacci_series_upto_n(13);
        console.timeEnd('TIME TAKEN: fibonacci_series_upto_n: ');
        console.log('a=' + sol.a + '\n');

        {
            console.time('TIME TAKEN: fibonacci_series_upto_n_rec: ');
            let res = {};
            console.log("fibonacci_series_upto_n_rec(13): ");
            this.fibonacci_series_upto_n_rec(13, 13, res);
            console.log(Object_values(res).join(', ')); // 0, 1, 1, 2, 3, 5, 8, 13
            console.timeEnd('TIME TAKEN: fibonacci_series_upto_n_rec: ');
            console.log('b=' + sol.b + '\n');
        }

        {
            console.time('TIME TAKEN: fibonacci_series_upto_n__with_memoization__rec: ');
            let res = {};
            console.log("fibonacci_series_upto_n__with_memoization__rec(13): ");
            this.fibonacci_series_upto_n__with_memoization__rec(13, 13, res);
            console.log(Object_values(res).join(', ')); // 0, 1, 1, 2, 3, 5, 8, 13
            console.timeEnd('TIME TAKEN: fibonacci_series_upto_n__with_memoization__rec: ');
            console.log('c=' + sol.c + '\n');
        }


    }

}
sol.a = 0;
sol.b = 0;
sol.c = 0;
sol.d = 0;


module.exports = sol;
