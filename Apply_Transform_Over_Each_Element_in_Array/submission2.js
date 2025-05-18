/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {

    let returnArr = [];
    let n = arr.length;

    for (let i=0; i<n; i++){
        returnArr.push(fn(arr[i], i));
    }

    return returnArr;
};