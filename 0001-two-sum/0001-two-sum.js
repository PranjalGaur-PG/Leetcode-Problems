/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    let n = nums.length;
    
    let st = new Map()
    for(let i=0; i<n; i++) {
        if(st.has(target - nums[i])) return [i, st.get(target-nums[i])];
        st.set(nums[i], i);
    }
    
    return [];
};