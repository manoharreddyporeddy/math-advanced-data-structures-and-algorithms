//
// ht tp s://www.geeksforgeeks.org/binary-heap/
//
// A class for Min Heap
class MinHeap {
    // Constructor: Builds a heap from a given array a[] of given size
    constructor(capacity) {
        // console.log("constructor", capacity);
        this.INT_MIN = -2147483648;

        this.size = 0; // Current number of elements in min heap
        this.capacity = capacity; // maximum possible size of min heap
        this.a = []; // new Array(capacity); // pointer to array of elements in heap

        // console.log("size, capacity, a - ", this.size, this.capacity, this.a);
    }

    parent(i) {
        return Math.trunc((i - 1) / 2);
    }

    leftChild(i) {
        return 2 * i + 1;
    }

    rightChild(i) {
        return 2 * i + 2;
    }

    // Inserts a new key 'k'
    insertKey(k) {
        if (this.size == this.capacity) {
            console.log("\nOverflow: Could not insertKey\n");
            return;
        }

        // First insert the new key at the end
        this.size++;
        let i = this.size - 1;
        this.a[i] = k;

        // Fix the min heap property if it is violated
        while (i != 0 && this.a[this.parent(i)] > this.a[i]) {
            [this.a[i], this.a[this.parent(i)]] = [
                this.a[this.parent(i)],
                this.a[i],
            ];
            i = this.parent(i);
        }

        return null;
    }

    // Decreases key value of key at index i to new_val
    // Decreases value of key at index 'i' to new_val. It is assumed that
    // new_val is smaller than this.a[i].
    decreaseKey(i, new_val) {
        this.a[i] = new_val;
        while (i != 0 && this.a[this.parent(i)] > this.a[i]) {
            [this.a[i], this.a[this.parent(i)]] = [
                this.a[this.parent(i)],
                this.a[i],
            ];
            i = this.parent(i);
        }

        return null;
    }

    // to extract the root which is the minimum element
    // Method to remove minimum element (or root) from min heap
    extractMin() {
        if (this.size <= 0) return INT_MAX;
        if (this.size == 1) {
            this.size--;
            return this.a[0];
        }

        // Store the minimum value, and remove it from heap
        let root = this.a[0];
        this.a[0] = this.a[this.size - 1];
        this.size--;
        this.MinHeapify(0);

        return root;
    }

    // Returns the minimum key (key at root) from min heap
    getMin() {
        // console.log(this.a[0], ", arr =", this.a);
        return this.a[0];
    }

    // Deletes a key stored at index i
    // This function deletes key at index i. It first reduced value to minus
    // infinite, then calls extractMin()
    deleteKeyAt(i) {
        this.decreaseKey(i, this.INT_MIN);
        this.extractMin();
        return null;
    }

    //	// to heapify a subtree with the root at given index
    // A recursive method to heapify a subtree with the root at given index
    // This method assumes that the subtrees are already heapified
    MinHeapify(i) {
        let l = this.leftChild(i);
        let r = this.rightChild(i);
        let smallest = i;
        if (l < this.size && this.a[l] < this.a[i]) smallest = l;
        if (r < this.size && this.a[r] < this.a[smallest]) smallest = r;
        if (smallest != i) {
            [this.a[i], this.a[smallest]] = [this.a[smallest], this.a[i]];

            this.MinHeapify(smallest);
        }
    }

    test() {

        // new MinHeap(11).test();

        let o1 = new MinHeap(11);

        o1.insertKey(3);
        console.log("insertKey 3, ", o1.a, ", ", o1.getMin());

        o1.insertKey(2);
        console.log("insertKey 2, ", o1.a, ", ", o1.getMin());

        o1.deleteKeyAt(1);
        console.log("deleteKeyAt 1 , ", o1.a, ", ", o1.getMin());

        o1.insertKey(15);
        console.log("insertKey 15, ", o1.a, ", ", o1.getMin());

        o1.insertKey(5);
        console.log("insertKey 5, ", o1.a, ", ", o1.getMin());

        o1.insertKey(4);
        console.log("insertKey 4, ", o1.a, ", ", o1.getMin());

        o1.insertKey(45);
        console.log("insertKey 45, ", o1.a, ", ", o1.getMin());

        console.log("extractMin ", o1.extractMin(), "", o1.a, ",", o1.getMin());

        o1.decreaseKey(2, 1);
        console.log("decreaseKey 2,1 , ", o1.a, ", ", o1.getMin());

        /*
        // new MinHeap(11).test();

        // operation parameters,   arr,                   getMin
            insertKey 3,           [ 3 ] ,                 3
            insertKey 2,           [ 2, 3 ] ,              2
            deleteKeyAt 1 ,        [ 2, 2 ] ,              2
            insertKey 15,          [ 2, 15 ] ,             2
            insertKey 5,           [ 2, 15, 5 ] ,          2
            insertKey 4,           [ 2, 4, 5, 15 ] ,       2
            insertKey 45,          [ 2, 4, 5, 15, 45 ] ,   2
            extractMin  2          [ 4, 15, 5, 45, 45 ] ,  4
            decreaseKey 2,1 ,      [ 1, 15, 4, 45, 45 ] ,  1        
        
        */
    }
}

// new MinHeap(11).test();
