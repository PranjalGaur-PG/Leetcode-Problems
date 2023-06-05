class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& inter) {
        sort(inter.begin(), inter.end());
        int n = inter.size();
        
        vector<vector<int>> ans;
        int i = 0;
        while(i<n) {
            int x = inter[i][0];
            int y = inter[i][1];
            while(i<n && y>=inter[i][0]) {
                y= max(y, inter[i][1]);
                i++;
            }
            
            ans.push_back({x, y});
        }
        
        return ans;
    }
};