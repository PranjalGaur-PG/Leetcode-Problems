class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map <char,int> m;
        int i=0,j=0,ans=0;
        while(i<s.length()) {
            if(m[s[i]] == 0) {
                m[s[i]]++; i++;
            }
            else {
                m[s[j]]--; j++;
            }
            ans = max(ans,(i-j));
        }
        return ans;
    }
};