/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    const ans = arr.map((element, index)=>fn(element, index));

    return ans;
};