/**
 * @param {number[]} nums
 * @param {number} key
 * @param {number} k
 * @return {number[]}
 */
var findKDistantIndices = function(nums, key, k) {
    let set = new Set();
    
    for(let i = 0; i< nums.length; i++) {
        if(nums[i] === key) {
            let l = Math.max(0, i-k);
            let h = Math.min(nums.length-1, i+k);
            
            while(l<=h) {
                set.add(l);
                l++;
            }
        }
    }
    
    let ans = [];
    for(ele of set.values()) {
        ans.push(ele);
    }
    
    return ans;
};