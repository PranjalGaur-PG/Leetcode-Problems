class Solution {
public:
    int fun(int n, int x, int y, string s, int ind, int sz) {
        for(int i=ind;i<sz;i++) {
            if(s[i]=='L') y--;
            else if(s[i]=='R') y++;
            else if(s[i]=='U') x--;
            else x++;
            
            if(x<0 || x>=n || y<0 || y>=n) return i-ind;
        }
        
        return sz-ind;
    }
        
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        int sz = s.size();
        vector<int> ans(sz);
        
        int x = startPos[0], y = startPos[1];
        for(int i=0;i<sz;i++) {
            ans[i] = fun(n, x, y, s, i, sz);
        }
        
        return ans;
    }
};