/**
 * @param {number[]} deliciousness
 * @return {number}
 */
var countPairs = function(nums) {
    let ans = 0, mod = 1e9+7;
    let count = {};
    
    for(let num of nums) {
        for(let i = 0; i<=21; i++) {
            if(count[Math.pow(2, i) - num]) {
                ans += count[Math.pow(2, i) - num];
                ans = ans%mod;
            }
        }
        
        if(count[num]) count[num]++;
        else count[num] = 1;
    }
    
    return ans;
};