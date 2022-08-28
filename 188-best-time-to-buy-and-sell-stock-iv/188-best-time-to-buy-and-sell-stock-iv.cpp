class Solution {
public:
    int maxProfit(int k, vector<int>& pri) {
         int n = pri.size();
        
        vector<vector<int>> after(2, vector<int> (k+1, 0));
        vector<vector<int>> cur  (2, vector<int> (k+1, 0));
        
        for(int i=n-1;i>=0;i--) {
            for(int j=0;j<2;j++) {
                for(int x=1;x<=k;x++) {
                    if(j==1) cur[j][x] = max(-pri[i]+ after[0][x], after[1][x]);
                    else cur[j][x] = max(pri[i]+ after[1][x-1], after[0][x]);
                }
            }
            after = cur;
        }
        
        return after[1][k];
    }
};