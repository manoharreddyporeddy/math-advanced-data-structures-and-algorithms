// NODEJS (Node 7.4.0) common template for everyone

// NOTE: This is common code - MUST be there for all problems below
let inputStr = "";
const _toInt = (x) => +x;
process.stdin.resume();
process.stdin.setEncoding("utf8");
process.stdin.on("data", (chunk) => (inputStr += chunk));

// problem https://www.codechef.com/problems/START01
process.stdin.on("end", () => {
    console.log(+inputStr);
});

// problem https://www.codechef.com/problems/FLOW001
process.stdin.on("end", () => {
    const inputLinesArr = inputStr.split("\n");

    let T = +inputLinesArr[0]; // # of tests

    for (let i = 1; i <= T; i++) {
        let [a, b] = inputLinesArr[i].split(" ").map(_toInt); // each test case

        console.log(a + b);
    }
});

// problem https://www.codechef.com/problems/INTEST
process.stdin.on("end", () => {
    const inputLinesArr = inputStr.split("\n");

    let [n, k] = inputLinesArr[0].split(" ").map(_toInt);

    let count = 0;

    for (let i = 1; i <= n; i++) {
        let ti = +inputLinesArr[i];
        if (ti % k === 0) {
            count++;
        }
    }

    console.log(count);
});

// problem https://www.codechef.com/problems/HS08TEST
process.stdin.on("end", () => {
    let [a, b] = inputStr.split(" ").map(_toInt); // each test case

    let res = b - a - 0.5;
    if (a % 5 === 0 && res >= 0) {
        // all good
    } else {
        res = b;
    }

    console.log(res);
});
