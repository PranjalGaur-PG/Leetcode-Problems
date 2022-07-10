class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<unordered_set<int>> st(n);
        
        for(auto it : roads) {
            st[it[0]].insert(it[1]);
            st[it[1]].insert(it[0]);
        }
        
        int ans = 0;
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                int rank = st[i].size() + st[j].size();
                
                if(st[i].count(j)) rank--;
                
                ans = max(ans, rank);
            }
        }
        
        return ans;
    }
};