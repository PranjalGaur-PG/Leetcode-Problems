class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        int mn = prices[0], pro = 0;
        for(auto it : prices) {
            if(it > mn) {
                pro = max(pro, it-mn);
            }
            mn = min(mn, it);
        }
        
        return pro;
    }
};