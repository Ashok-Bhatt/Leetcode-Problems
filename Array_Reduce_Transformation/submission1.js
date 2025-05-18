/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */
var reduce = function(nums, fn, init) {
    
    let ans = init, n = nums.length;
    for (let i=0; i<n; i++){
        ans = fn(ans, nums[i]);
    }

    return ans;
};