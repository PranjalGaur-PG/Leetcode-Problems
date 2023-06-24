class Solution {
public:
    int ans;
    void rec(vector<int>& rods, int l1, int l2, int ind, int& n) {
        if(ind == n) {
            if(l1 == l2) ans = max(ans, l1);
            return;
        }
        
        rec(rods, l1, l2, ind+1, n);
        rec(rods, l1+rods[ind], l2, ind+1, n);
        rec(rods, l1, l2+rods[ind], ind+1, n);
    }
    
    int tallestBillboard(vector<int>& rods) {
//         ans = 0;
//         int n = rods.size();
        
//         if(n==1) return 0;
//         rec(rods, 0, 0, 0, n);
        
//         return ans;
        
        unordered_map<int, int> dp; 
        dp[0] = 0; 
        for (auto& x : rods) {
            unordered_map<int, int> temp = dp; 
            for (auto& [k, v] : temp) {
                dp[k + x] = max(dp[k + x], v); 
                if (x <= k) dp[k-x] = max(dp[k - x], v + x); 
                else dp[x - k] = max(dp[x - k], v + k); 
            }
        }
        return dp[0]; 
    }
};