/**
 * @param {Array} arr
 * @param {number} size
 * @return {Array[]}
 */
var chunk = function(arr, size) {
    const ans = [];
    for (let i = 0; i < arr.length; i++) {
        if (i * size < arr.length) {
            ans.push(arr.slice(i * size, Math.min(size * (i + 1), arr.length)));
        }
    }

    return ans;
};
