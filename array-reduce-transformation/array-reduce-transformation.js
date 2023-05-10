/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */
 // POS Js
var reduce = function(nums, fn, init) {
   let accumulator = init;
   for(const index in nums){
       accumulator = fn(accumulator, nums[index]);
   }
   return accumulator;
};