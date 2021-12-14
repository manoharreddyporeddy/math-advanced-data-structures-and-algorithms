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

    front = () => this.values[0];
    push_front = (x) => this.values.unshift(x); // untested
    pop_front = () => this.values.shift();

    back = () => this.values[this.size() - 1];
    push_back = (x) => this.values.push(x);
    pop_back = () => this.values.pop();
}
