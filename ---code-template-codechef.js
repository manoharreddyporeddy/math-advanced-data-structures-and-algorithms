let inputStr = "";
const _toInt = (x) => +x;
process.stdin.resume();
process.stdin.setEncoding("utf8");
process.stdin.on("data", (chunk) => (inputStr += chunk));

// NODEJS common template for everyone - problem FLOW001
process.stdin.on("end", () => {
    const inputLinesArr = inputStr.split("\n");

    var T = +inputLinesArr[0]; // # of tests

    for (let i = 1; i <= T; i++) {
        let [a, b] = inputLinesArr[i].split(" ").map(_toInt); // each test case

        console.log(a + b);
    }
});

// NODEJS common template for everyone - problem HS08TEST
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
