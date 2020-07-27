class Permutation {
    constructor(a) {
        if (!a) return;

        this.a = a;

        // NOTE
        // --------- sort to get all permutations ---------
        a = a.sort((a, b) => a.charCodeAt(0) - b.charCodeAt(0));
        // a = a.sort((a, b) => a - b);

        // console.log(a);
        this.first = true;
    }

    // find next greater number. modifies original array to store result
    next() {
        if (this.first) {
            this.first = !this.first;
            return this.a;
        }

        let a = this.a;

        let n = a.length;

        if (!n) return [];

        let i;

        // I) Start from the right most digit and find the first digit that is smaller than the digit next to it.
        for (i = n - 1; i > 0; i--) {
            if (a[i] > a[i - 1]) {
                break;
            }
        }

        // If no such digit is found, then all digits are in descending order means there cannot be a greater number with same set of digits
        if (i == 0) {
            // console.log("All done.");
            return [];
        }
        let x = a[i - 1],
            min = i;

        // II) Find the smallest digit on right side of (i-1)'th digit that is greater than number[i-1]
        for (let j = i + 1; j < n; j++) {
            if (a[j] > x && a[j] < a[min]) {
                min = j;
            }
        }

        // III) Swap the above found smallest digit with number[i-1]
        // console.log(a);
        [a[min], a[i - 1]] = [a[i - 1], a[min]];
        // console.log(a);

        // IV) Sort the digits after (i-1) in ascending order
        a = a
            .slice(0, i)
            .concat(
                a.slice(i).sort((a, b) => a.charCodeAt(0) - b.charCodeAt(0))
            );
        // Arrays.sort(a, i, n);
        // console.log("Next number with same" + " set of digits is ");
        // console.log(a);

        this.a = a;
        return this.a;
    }

    test() {
        {
            let a = ["1", "2", "3"];
            let o1 = new Permutation(a);
            console.log(o1.next(a));
        }

        {
            let a = ["1", "2", "3"];
            let o1 = new Permutation(a);

            let aa = [];
            let cc = 0;

            let temp = [];
            while ((temp = o1.next()).length) {
                aa.push(JSON.parse(JSON.stringify(temp)));
                cc++;
            }

            console.log(aa);
        }
    }
}

let o1 = new Permutation();
o1.test();
