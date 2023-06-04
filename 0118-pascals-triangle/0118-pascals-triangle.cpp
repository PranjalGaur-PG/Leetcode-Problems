class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        temp.push_back(1);
        
        ans.push_back(temp);
        if(n==1) return ans;
        
        temp.resize(2, 1);
        ans.push_back(temp);
        
        for(int i=3;i<=n;i++) {
            temp.resize(i, 1);
            
            for(int j=1;j<i-1;j++) temp[j] = ans[i-2][j] + ans[i-2][j-1];
            ans.push_back(temp);
        }
        
        return ans;
    }
};