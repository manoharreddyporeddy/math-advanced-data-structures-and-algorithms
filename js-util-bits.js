class BitManip {
    constructor(n) {
        this.n = n;
    }

    getNum() {
        return this.n;
    }

    getBitCount() {
        let sum = 0;
        while (this.n) {
            sum += this.n & 1;
            this.n = this.n >> 1;
        }
        return sum;
    }

    getKthIndexBit(k) {
        if (k < 0) {
            console.log("k -ve invalid - getKthIndexBit");
            return this.n;
        }
        return (this.n >> k) & 1;
        // return this.n & (1 << k); // ---- bitwise AND (&)
    }

    setKthIndexBit(k) {
        if (k < 0) {
            console.log("k -ve invalid - setKthIndexBit");
            return this.n;
        }
        this.n = this.n | (1 << k); // ---- bitwise OR (|)
        return this.n;
    }

    unsetKthIndexBit(k) {
        if (k < 0) {
            console.log("k -ve invalid - unsetKthIndexBit");
            return this.n;
        }

        // & this.n, with a number with all set bits except the k'th bit

        this.n = this.n & ~(1 << k); // ----  bitwise AND (&)
        return this.n;
    }

    // ----------

    /*

    toggleKthBit(k) {
        if (k < 1) return this.n;

        // ^ this.n, with a number with all set bits except the k'th bit
        return this.n ^ (1 << k); // ---------------- bitwise AND (&)
    }

    */
}


//     let o1 = new BitManip(682);
//     let act = o1.setKthIndexBit(0); // 683
