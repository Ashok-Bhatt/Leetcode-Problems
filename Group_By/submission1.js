/**
 * @param {Function} fn
 * @return {Object}
 */
Array.prototype.groupBy = function(fn) {
    const ans = {};
    for (let i=0; i<this.length; i++){
        let newValue = fn(this[i]);
        if (!ans[newValue]){
            ans[newValue] = [this[i]];
        } else {
            ans[newValue].push(this[i]);
        }
    }
    return ans;
};

/**
 * [1,2,3].groupBy(String) // {"1":[1],"2":[2],"3":[3]}
 */