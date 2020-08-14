/**
 * @param {number[][]} points
 * @return {number}
 */
var largestTriangleArea = function (points) {};

class nCr {
    // ht  tps://www.geek   sforgeeks.org/make-combinations-size-r/

    // Prints all combinations of size r of numbers from 1 to n.
    nCr_wo_repitition(n, r) {
        // console.log(n, r);

        let res = [];
        let tmp = [];

        function dfs(left, r) {
            // Pushing this vector to a vector of vector
            if (r == 0) {
                // res.push(JSON.parse(JSON.stringify(tmp))); // ----------------
                // console.log("save", tmp);
                // console.log(res);
                return;
            }

            // i iterates from left to n. First time left will be 1
            //      i <= n
            //      i + r - 1 <= n
            for (let i = left; i + r - 1 <= n; ++i) {
                tmp.push(i);
                // console.log(tmp, "             ", n, i, r);

                dfs(i + 1, r - 1);

                // Popping out last inserted element from the vector
                tmp.pop();
            }
        }

        dfs(1, r);
        // console.log(res);
        return res;
    }

    // The main function that prints all combinations of size r
    // in arr[] of size n. This function mainly uses nCr_wo_reptn()
    nCr_wo_repitition_2(n, r) {
        /* arr[] ---> Input Array 
		tmp[] ---> Temporary array to store current combination 
		start & end ---> Staring and Ending indexes in arr[] 
		index ---> Current index in tmp[] 
		r ---> Size of a combination to be printed */

        let arr = Array.from({ length: n }, (_, i) => i + 1);
        // console.log(arr, n, r);

        let res = [];
        // A temporary array to store all combination one by one
        let tmp = []; // new int[r]();

        function nCr_wo_reptn(tmp, start, end, index, r) {
            // Current combination is ready to be printed, print it
            if (index == r) {
                // res.push(JSON.parse(JSON.stringify(tmp))); // ----------------
                // for (let j = 0; j < r; j++) System.out.print(tmp[j] + " ");
                // System.out.println("");
                return;
            }

            // replace index with all possible elements. The condition
            // "end-i+1 >= r-index" makes sure that including one element
            // at index will make a combination with remaining elements
            // at remaining positions
            for (let i = start; i <= end && end - i + 1 >= r - index; i++) {
                tmp[index] = arr[i];
                nCr_wo_reptn(tmp, i + 1, end, index + 1, r);
            }
        }

        // Print all combination using temprary array 'tmp[]'
        nCr_wo_reptn(tmp, 0, n - 1, 0, r);

        return res;
    }

    // The main function that prints all combinations of size r
    // in arr[] of size n. This function mainly uses nCr_wo_reptn2()
    nCr_wo_repitition_3(n, r) {
        // ht  tps://www.geeks  forgeeks.org/print-all-possible-combinations-of-r-elements-in-a-given-array-of-size-n/
        // This method is mainly based on Pascal’s Identity, i.e. ncr = n-1cr + n-1cr-1

        let arr = Array.from({ length: n }, (_, i) => i + 1);
        // console.log(arr, n, r);

        /* arr[] ---> Input Array 
		tmp[] ---> Temporary array to store current combination 
		start & end ---> Staring and Ending indexes in arr[] 
		index ---> Current index in tmp[] 
		r ---> Size of a combination to be printed */

        let res = [];
        // A temporary array to store all combination one by one
        let tmp = []; // new int[r]();

        function nCr_wo_reptn2(n, r, index, tmp, i) {
            // Current combination is ready to be printed, print it
            if (index == r) {
                // res.push(JSON.parse(JSON.stringify(tmp))); // ----------------
                // for (let j = 0; j < r; j++) System.out.print(tmp[j] + " ");
                // System.out.println("");
                return;
            }

            // When no more elements are there to put in tmp[]
            if (i >= n) return;

            // current is included, put next at next location
            tmp[index] = arr[i];
            nCr_wo_reptn2(n, r, index + 1, tmp, i + 1);

            // current is excluded, replace it with next (Note that
            // i+1 is passed, but index is not changed)
            nCr_wo_reptn2(n, r, index, tmp, i + 1);
        }

        // Print all combination using temprary array 'tmp[]'
        nCr_wo_reptn2(n, r, 0, tmp, 0);

        return res;
    }

    test() {
        // let n = 5;
        // let r = 3;
        //
        // let exp = [
        //     [1, 2, 3],
        //     [1, 2, 4],
        //     [1, 2, 5],
        //     [1, 3, 4],
        //     [1, 3, 5],
        //     [1, 4, 5],
        //     [2, 3, 4],
        //     [2, 3, 5],
        //     [2, 4, 5],
        //     [3, 4, 5],
        // ];
        //
        // let res = this.nCr_wo_repitition(n, r); // [][]
        // console.log(res);
        // console.log(
        //     JSON.stringify(res) == JSON.stringify(exp) ? "pass" : "fail"
        // );

        let startTime;

        let MAX_N = 50;
        let MAX_R = 3; // MAX_N;

        // 27 - 7/8/9 secs, 28 = time out         <--------------------------- lets take this
        startTime = new Date().getTime();
        for (let n = 1; n <= MAX_N; n++) {
            for (let r = 1; r <= MAX_R; r++) {
                let res = this.nCr_wo_repitition(n, r); // [][]
            }
        }
        console.log(new Date().getTime() - startTime, "ms");

        // 27 - 8/9 secs, 28 = time out
        startTime = new Date().getTime();
        for (let n = 1; n <= MAX_N; n++) {
            for (let r = 1; r <= MAX_R; r++) {
                let res = this.nCr_wo_repitition_2(n, r);
            }
        }
        console.log(new Date().getTime() - startTime, "ms");

        // 24=8-9 secs, 25=time out
        startTime = new Date().getTime();
        for (let n = 1; n <= MAX_N; n++) {
            for (let r = 1; r <= MAX_R; r++) {
                let res = this.nCr_wo_repitition_3(n, r);
            }
        }
        console.log(new Date().getTime() - startTime, "ms");

        return 0;
    }
}

new nCr().test();
