/**
 * @param {Function} fn
 * @return {Function}
 */
 // POD- js, Functional Programing
var curry = function(fn) {
    return function curried(...args) {
        if(args.length == fn.length){
            return fn(...args);
        } else{
            return function(...newArgs){
                return curried(...args, ...newArgs);
            }
        }
    };
};

/**
 * function sum(a, b) { return a + b; }
 * const csum = curry(sum);
 * csum(1)(2) // 3
 */