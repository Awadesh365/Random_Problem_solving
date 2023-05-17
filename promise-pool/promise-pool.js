/**
 * @param {Function[]} functions
 * @param {number} n
 * @return {Function}
 */
 //POD js
 // about promise pool in js

 // approach 2:- Async/Await + Promise.all() + Array.shift()

var promisePool = async function(functions, n) {
    async function evaluateNext(){
        if(functions.length===0)    return;

        const fn = functions.shift();
        await fn();
        await evaluateNext();
    }
    const nPromises = Array(n).fill().map(evaluateNext);
    await Promise.all(nPromises);
};

/**
 * const sleep = (t) => new Promise(res => setTimeout(res, t));
 * promisePool([() => sleep(500), () => sleep(400)], 1)
 *   .then(console.log) // After 900ms
 */