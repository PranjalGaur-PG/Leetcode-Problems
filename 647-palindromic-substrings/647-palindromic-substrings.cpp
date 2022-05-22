class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        
        int ans = 0;
        int i,j,k;
        for(int i=0;i<n;i++) {
            j = k = i;
            while(j>=0 && k<n) {
                if(s[j] == s[k]) ans++;
                else break;
                j--; k++;
            }
            j = i;
            k = i+1;
            while(j>=0 && k<n) {
                if(s[j] == s[k]) ans++;
                else break;
                j--; k++;
            }
        }
        
        return ans;
    }
};