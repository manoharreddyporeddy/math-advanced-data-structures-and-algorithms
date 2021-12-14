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

    console.log(q.front())
    console.log(q.back())

    console.log(q.pop_front())
    console.log(q.pop_back())
}
