class Solution {
public:
    int getCommon(vector<int>& firstBranch, vector<int>& secondBranch) {
        set<int> count;
        int n = firstBranch.size(), m = secondBranch.size();
    
        for(int i=0;i<n;i++) count.insert(firstBranch[i]);

        int ans = INT_MAX;
        for(int i=0;i<m;i++) {
            if(count.find(secondBranch[i]) != count.end()) {
                ans = min(ans, secondBranch[i]);
            }
        }

        if(ans == INT_MAX) return -1;
        return ans;
    }
};