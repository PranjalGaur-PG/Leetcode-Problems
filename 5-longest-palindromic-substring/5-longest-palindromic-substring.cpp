class Solution {
public:
    string printSubStr(string str,int l,int h) {
        string ansStr="";
        for (int i=l;i<=h;++i) ansStr.push_back(str[i]);
        return ansStr;
    }       
    
    string longestPalindrome(string s) {
        int n=s.size(), i,j,k;
        
        bool dp[n][n];
        memset(dp,false,sizeof(dp));
        int mx=1,st=0;
        
        for(i=0;i<n;i++) dp[i][i] = true;
        
        for(i=0;i<n-1;i++) {
            if(s[i] == s[i+1]) {
                dp[i][i+1] = true;
                st = i;
                mx = 2;
            }
        }
        
        for(k=3;k<=n;k++) {
            for(i=0;i < n-k+1;i++) {
                j = i+k-1;
                
                if(s[i] == s[j] && dp[i+1][j-1]) {
                    dp[i][j] = true;
                    
                    if(k>mx) {
                        mx = k;
                        st = i;
                    }
                }
            }
        }
        cout<<st<<" "<<mx;
        
        string ans;
        for(i=st;i<st+mx;i++) ans.push_back(s[i]);
        return ans;
        
    }
};