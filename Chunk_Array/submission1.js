/**
 * @param {Array} arr
 * @param {number} size
 * @return {Array}
 */
var chunk = function(arr, size) {
    const newArr = [];
    let n = arr.length, i = 0;

    while (i<n){
        newArr.push(arr.slice(i, i+size));
        i = i + size;
    }

    return newArr;
};
