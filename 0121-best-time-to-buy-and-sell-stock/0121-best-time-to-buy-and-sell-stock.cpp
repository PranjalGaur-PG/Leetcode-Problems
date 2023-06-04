class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ans = 0, mn = prices[0];
        
        for(int i=1;i<n;i++) {
            if(prices[i]>mn) ans = max(ans, prices[i]-mn);
            mn = min(mn, prices[i]);
        }
        
        return ans;
    }
};