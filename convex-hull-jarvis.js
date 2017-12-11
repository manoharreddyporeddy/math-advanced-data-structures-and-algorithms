
class Point {

    constructor(x, y) {
        this.x = x;
        this.y = y;
        console.log(this);
    }

    approxDistanceTo(B) {
        // actually it is squareRoot, but when we skip for all distances we dont need to do since we company squares instead of sqrt
        let dX = Math.abs(B.x - this.x);
        let dY = Math.abs(B.y - this.y);
        return dX + dY;
    }

    closerToB_by(B, C) {
        let dB = this.approxDistanceTo(B);   // A B approxDistanceTo
        let dC = this.approxDistanceTo(C);   // A C approxDistanceTo
        return (dC - dB); // difference

        // (>0)  B is closer  than C, to A
        // (<0)  B is farther than C, to A
        // (=0)  B & C are equi-distance to A
    }

    static C_is_leftOfAB(A, B, C) { // crossProduct will do
        let dABx = (A.x - B.x);
        let dABy = (A.y - B.y);

        let dACx = (A.x - C.x);
        let dACy = (A.y - C.y);
//
//        let minOfAll =
//                Math.min(
//                        Math.min(dABx, dACy),
//                        Math.min(dACx, dABy)
//                        );
//
//        console.log('\t\t\t\t\t', dABx, dACy, dACx, dABy);
//
//        if (minOfAll > 1) {
//            console.log('YES_--------------------');
//            minOfAll = minOfAll - 1;
//            console.log(minOfAll);
//        } else if (minOfAll < 1) {
//            console.log('YES_--------------------');
//            minOfAll = minOfAll - 1;
//            console.log(minOfAll);
//        } else {
//            minOfAll = 0;
//        }
//
//
//        dABx = dABx - minOfAll;
//        dACy = dACy - minOfAll;
//        dACx = dACx - minOfAll;
//        dABy = dABy - minOfAll;

//        let sign1 = 1;
//        sign1 = (dACy < 0) ? -1 * sign1 : sign1;
//        sign1 = (dABx < 0) ? -1 * sign1 : sign1;
//
//        let sign2 = 1;
//        sign2 = (dACx < 0) ? -1 * sign2 : sign2;
//        sign2 = (dABy < 0) ? -1 * sign2 : sign2;
//
//        return sign1 * (dABx + dACy) - sign2 * (dACx + dABy);
        return dABx * dACy - dACx * dABy;

        // (<0)  C is left of AB
        // (>0)  C is right of AB
        // (=0)  C is on AB, collinear
    }

    static convexHull__jarvisMarch(parr) {

        if (!parr[0]) {
            throw new Error("what??");
        }

        let slmi = 0;

        console.log('parr[slmi]');
        console.log(parr[slmi]);
        for (let i = 0; i < parr.length; i++) {
            // console.log('\t', parr[slmi].x, parr[i].x);
            if (parr[slmi].x > parr[i].x) {
                slmi = i;
            }
        }
        console.log('parr[slmi]');
        console.log(parr[slmi]);

        let start_leftmost = parr[slmi];  // copy
        console.log('start_leftmost');
        console.log(start_leftmost);

        console.log('parr');
        console.log(parr);
        delete parr[slmi];
        console.log('parr');
        console.log(parr);


    }

}

//let A = new Point(-6, -2);
//let B = new Point(4, 6);
//let C = new Point(8, -4);
//
//let dB = A.approxDistanceTo(B);
//let dC = A.approxDistanceTo(C);
//console.log("dB: " + dB);
//console.log("dC: " + dC);
//
//console.log("closerToB_by?" + A.closerToB_by(B, C));
////console.log("closerToB_by?" + A.closerToB_by(C, B));
//
//console.log("---------------");
//console.log("C_is_leftOfAB?" + Point.C_is_leftOfAB(A, B, C));
//console.log("C_is_leftOfAB?" + Point.C_is_leftOfAB(A, C, B));
//console.log("C_is_leftOfAB?" + Point.C_is_leftOfAB(B, C, A));
//
//console.log("---------------");

let parr = [
    new Point(2, 0),
    new Point(2, 2),
    new Point(0, 2),
    new Point(-2, 2),
    new Point(0, 0),
    new Point(-2, 0),
    new Point(-2, -2),
    new Point(0, -2),
    new Point(2, -2)
];

Point.convexHull__jarvisMarch(parr);
