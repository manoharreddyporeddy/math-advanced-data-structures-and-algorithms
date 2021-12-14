/* Deque data structure in javascript / js */

class Deque {
    values = [];
    constructor(values) {
        if (values) this.values = values; // no copy
        // if (values) this.values = [...values]; // copy
    }

    get length() {
        return this.size();
    }
    size = () => this.values.length;
    isEmpty = () => this.size() === 0;

    back = () => this.values[this.size() - 1];
    push_back = (x) => this.values.push(x);
    pop_back = () => this.values.pop();

    front = () => this.values[0];
    push_front = (x) => this.values.unshift(x); // to be tested
    pop_front = () => this.values.shift();
}

function use() {
    let q = new Deque();

    q.push_back(10);
    q.push_back(20);
    console.log(q.size()); //      2      // output
    console.log(q.isEmpty()); //   false
    console.log(q.front()); //     10
    console.log(q.back()); //      20

    console.log(q.pop_front()); // 10
    console.log(q.size()); //      1
    console.log(q.isEmpty()); //   false
    console.log(q.front()); //     20
    console.log(q.back()); //      20

    console.log(q.pop_back()); //  20
    console.log(q.size()); //      0
    console.log(q.isEmpty()); //   true
    console.log(q.front()); //     undefined
    console.log(q.back()); //      undefined
}

use();
