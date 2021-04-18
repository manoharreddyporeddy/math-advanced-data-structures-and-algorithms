// NODEJS common template for everyone - submit answer here https://www.codechef.com/submit/FLOW001 - problem description https://www.codechef.com/problems/FLOW001

var tempStr = "";

process.stdin.resume();
process.stdin.setEncoding("utf8");
process.stdin.on("data", (chunk) => (tempStr += chunk));
process.stdin.on("end", () => main(tempStr.split("\n")));

const main = (INPUT_LINE_ARRAY) => {
    // 1st line - number of tests (T)
    var T = +INPUT_LINE_ARRAY[0];

    // remaining lines   are   input tests
    for (let i = 1; i <= T; i++) {
        // each line has 2 numbers separated by space  e.g;    x y
        let [a, b] = INPUT_LINE_ARRAY[i].split(" ").map((x) => +x);

        console.log(a + b);
    }
};
