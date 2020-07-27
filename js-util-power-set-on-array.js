class SetElements {
    constructor(s) {
        this.s = s;

        // NOTE
        //  this.aa = [[]]; //////// CHECKKK - Empty set is required?
        this.aa = []; // Empty set is not required
    }

    generate(t, start, pos) {
        if (pos == t.length) {
            // console.log(t);
            this.aa.push(JSON.parse(JSON.stringify(t)));
            return true;
        }

        for (let i = start; pos < t.length && i < this.s.length; i++) {
            t[pos] = this.s[i];
            this.generate(t, i + 1, pos + 1);
        }
    }

    getPowerSet() {
        let s = this.s;
        for (let c = 1; c <= s.length; c++) {
            this.generate(s.substr(0, c).split(""), 0, 0);
        }
        return this.aa;
    }

    test() {
        let o1 = new SetElements("ABC");
        console.log(o1.getPowerSet());
    }
}

let o1 = new SetElements();
o1.test();
