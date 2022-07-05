class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        sort(special.begin(), special.end());
        
        int ans = 0, cnt = 0, n = special.size();
        if(bottom < special[0]) ans = max(ans, special[0]-bottom);
        if(top > special[n-1]) ans = max(ans, top-special[n-1]);
        
        for(int i=1;i<n;i++) ans = max(ans, special[i]-special[i-1]-1);
        
        return ans;
    }
};