/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */
 // POS Js
var reduce = function(nums, fn, init) {
   let accumulator = init;
   nums.forEach((element)=>{
       accumulator = fn(accumulator,element);
   });
   return accumulator;
};