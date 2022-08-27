class Solution {
public:
    int rec(vector<int>& pri, int ind, int buy, vector<vector<int>>& dp, int n) {
        if(ind == n) return 0;
        
        if(dp[ind][buy] != -1) return dp[ind][buy];
        
        if(buy) {
            return dp[ind][buy] = max(-pri[ind] + rec(pri, ind+1, 0, dp, n) , rec(pri, ind+1, 1, dp, n));
        }
        else {
            return dp[ind][buy] = max( pri[ind] + rec(pri, ind+1, 1, dp, n) , rec(pri, ind+1, 0, dp, n));
        }
    }
    
    int maxProfit(vector<int>& pri) {
        
        int n = pri.size();
        vector<int> ahead(2, 0), cur(2, 0);
        
        for(int i=n-1;i>=0;i--) {
            for(int j=0;j<2;j++) {
                if(j == 1) cur[j] = max(-pri[i] + ahead[0], ahead[1]);
                else       cur[j] = max( pri[i] + ahead[1], ahead[0]);
            }
            ahead = cur;
        }
        
        return ahead[1];
    }
};