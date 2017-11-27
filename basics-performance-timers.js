// for aws, azure, nodejs - performance timers
//  time & timeEnd

let startTimeArray = undefined;
let endTimeArray = undefined;
let strMessage = undefined;

// =========
// If you are working on micrsoft azure functions
// then replace all
//  context
//      to
//  context
// =========

module.exports = {
    time: time,
    timeEnd: timeEnd
};

function time(strMessage1, context) {

    if (!context) {
        context = console;
    }

    if (process.env.CS_TIME_LOGS !== '1') {
        return;
    }

    if (startTimeArray !== undefined) {
        context.log.error('Error: timeEnd() was not called, resetting');

        startTimeArray = undefined; // clear previous timer
    }

    startTimeArray = process.hrtime(); // from current time // start new timer
    strMessage = strMessage1;
}

function timeEnd(strMessage1, context) {
    if (process.env.CS_TIME_LOGS !== '1') {
        return;
    }

    if (!context) {
        context = console;
    }

    if (startTimeArray === undefined) {
        context.log.error('Error: time() was not called, resetting');

        startTimeArray = undefined; // clear previous timer
        endTimeArray = undefined; // clear previous timer
        return;
    }

    if (strMessage !== strMessage1) {
        context.log.error('Error: time() & timeEnd() messages don\'t match, resetting');

        startTimeArray = undefined; // clear previous timer
        endTimeArray = undefined; // clear previous timer
        return;
    }

    endTimeArray = process.hrtime(startTimeArray); // from start time
    // [seconds, nanoseconds]

    // context.log(strMessage1 + " " + (endTimeArray[0] + (endTimeArray[1] / 1e9)).toFixed(3) + ' seconds');
    context.log(strMessage1 + " " + (endTimeArray[0] * 1e6 + (endTimeArray[1] / 1e3)).toFixed(3) + ' microseconds');
    // context.log(strMessage1 + " " + (endTimeArray[0] * 1e9 + (endTimeArray[1])) + ' nanoseconds');

    startTimeArray = undefined; // clear previous timer
    endTimeArray = undefined; // clear previous timer
}

/*
 function doMain() {

 context.log('=======================');
 context.log('testing positive cases');
 context.log('=======================');

 // case 1: 1 second
 time();
 for (let i = 0; i < 1e9; i++) {
 }
 timeEnd();

 // case 2: 8 second
 time();
 for (let i = 0; i < 3 * 1e9; i++) {
 }
 timeEnd();


 context.log('=======================');
 context.log('testing negative cases');
 context.log('=======================');

 // case 3: error scenarios
 timeEnd();
 time();
 time();
 context.log('=======================');
 }

 doMain();
 */
