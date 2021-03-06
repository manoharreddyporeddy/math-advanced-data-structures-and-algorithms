// Knight Tour problem

// GOAL:
//      knight on the top-left corner (0)
//          should jump to
//              all squares
//              on chess board / (8x8) matrix

/*
    0	59	38	33	30	17	8	63
    37	34	31	60	9	62	29	16
    58	1	36	39	32	27	18	7
    35	48	41	26	61	10	15	28
    42	57	2	49	40	23	6	19
    47	50	45	54	25	20	11	14
    56	43	52	3	22	13	24	5
    51	46	55	44	53	4	21	12
*/

class KnightTour {
    //

    constructor() {
        //

        this.N = 8;
        this.aa = Array.from({ length: this.N }, () => new Array(this.N));

        // next moves/ (x, y) coordinates of Knight
        this.xMoves = [2, 1, -1, -2, -2, -1, 1, 2];
        this.yMoves = [1, 2, 2, 1, -1, -2, -2, -1];

        /*
                       x,y
               1,-2             2,1
                                
           -1,-2                    1,2
                                
               -2,-1             -1,2
                       -2,1
        */
    }

    isSafe(x, y) {
        return (
            x >= 0 && //
            x < this.N &&
            y >= 0 &&
            y < this.N &&
            this.aa[x][y] == -1
        );
    }

    // returns fals e, if no complete tour is possible,
    // return tru e, prints the tour.
    //      multiple solutions may exist - after 1 solution found, exit
    solveKT() {
        //

        for (let x = 0; x < this.N; x++) {
            for (let y = 0; y < this.N; y++) {
                this.aa[x][y] = -1;
            }
        }

        // Knight is initially at the first block
        this.aa[0][0] = 0;

        /*
             0	-1	-1	-1	-1	-1	-1	-1
            -1	-1	-1	-1	-1	-1	-1	-1
            -1	-1	-1	-1	-1	-1	-1	-1
            -1	-1	-1	-1	-1	-1	-1	-1
            -1	-1	-1	-1	-1	-1	-1	-1
            -1	-1	-1	-1	-1	-1	-1	-1
            -1	-1	-1	-1	-1	-1	-1	-1
            -1	-1	-1	-1	-1	-1	-1	-1
        */

        // start from 0,0 and explore all tours
        if (this.solveKTUtil(0, 0, 1)) {
            this.printSolution();
        } else {
            console.log("Solution does not exist");
        }
    }

    solveKTUtil(x, y, movei) {
        if (movei == this.N * this.N) return true;

        // try all next moves from the current x, y
        for (let k = 0; k < this.N; k++) {
            //

            let next_x = x + this.xMoves[k];
            let next_y = y + this.yMoves[k];

            if (this.isSafe(next_x, next_y)) {
                //

                this.aa[next_x][next_y] = movei;
                /*
                    // final solution will be

                    0	59	38	33	30	17	8	63
                    37	34	31	60	9	62	29	16
                    58	1	36	39	32	27	18	7
                    35	48	41	26	61	10	15	28
                    42	57	2	49	40	23	6	19
                    47	50	45	54	25	20	11	14
                    56	43	52	3	22	13	24	5
                    51	46	55	44	53	4	21	12
                */

                if (this.solveKTUtil(next_x, next_y, movei + 1)) {
                    // solution is complete
                    return true;
                } else {
                    // backtracking - goto prev stage
                    this.aa[next_x][next_y] = -1;
                }
            }
        }

        return false;
    }

    printSolution() {
        let str = "";
        for (let x = 0; x < this.N; x++) {
            str = "";
            for (let y = 0; y < this.N; y++) str += this.aa[x][y] + " ";
            console.log(str);
        }
    }
}

let a = new KnightTour();
a.solveKT();

/*

Time Complexity looks like:

- 1st move 8 possibilities
- From 2nd move <=7 possibilities, since we don't go back to same position.
-- There are 63 moves like 2nd move.

8 * 7 * 7 * ... * 7 (*7 is for 63 times)
= 8 * (7 ^ 63)
= 8 * (8-1) ^(64-1)
= 8 * (8-1) ^(r*c-1)
= 8 ^ (r*c) approx      -- r and c  are  # of rows & columns of matrix

*/
