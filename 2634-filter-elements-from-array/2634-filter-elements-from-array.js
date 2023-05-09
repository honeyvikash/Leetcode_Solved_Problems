/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    let newarr = [];
    let s=0;
    for (let i = 0; i < arr.length; i++) {
        if(fn(arr[i],i))  newarr[s++] = arr[i];
      }
      return newarr;
};