class Solution {
public:
    void rec(vector<int>& can, int tar, vector<int> temp, int ind, vector<vector<int>>& ans) {
        if(tar == 0) {
            ans.push_back(temp);
            return;
        }
        
        int prev = -1;
        for(int i=ind;i<can.size();i++) {
            if(tar < can[i]) return;
            if(i && i>ind && can[i]==prev) continue;
            
            temp.push_back(can[i]);
            rec(can, tar-can[i], temp, i+1, ans);
            temp.pop_back();
            
            prev = can[i];
        }
        
    }
    
    vector<vector<int>> combinationSum2(vector<int>& can, int tar) {
        sort(can.begin(), can.end());
        
        vector<vector<int>> ans;
        vector<int> temp;
        
        rec(can, tar, temp, 0, ans);
        return ans;
    }
};