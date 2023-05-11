/**
 * @param {Function[]} functions
 * @return {Function}
 */
var compose = function(functions) {
	return function(x) {
        if (!functions.length) return x
        let ans = x
        for (i = functions.length - 1; i >= 0; i--) {
            const fn = functions[i]
            ans = fn(ans)
        }
        return ans
    }
};

/**
 * const fn = compose([x => x + 1, x => 2 * x])
 * fn(4) // 9
 */