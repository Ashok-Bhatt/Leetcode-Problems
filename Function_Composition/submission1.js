/**
 * @param {Function[]} functions
 * @return {Function}
 */
var compose = function(functions) {
    
    return function(x) {
        if (functions.length == 0){
            return x;
        } else {
            let ans = x, n = functions.length;
            for (let i=n-1; i>=0; i--){
                ans = functions[i](ans);
            }
            return ans;
        }
    }
};

/**
 * const fn = compose([x => x + 1, x => 2 * x])
 * fn(4) // 9
 */