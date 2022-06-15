class Solution {
public:
    int longestStrChain(vector<string>& words) {
         sort(words.begin(),words.end(),[](string a, string b){return a.size() < b.size();});
        map<string, int> dp;
        int res = 0;
        for(string s : words){
            for(int i = 0; i<s.size(); i++ ){
                dp[s] = max(dp[s.substr(0,i) + s.substr(i+1)] + 1, dp[s]);
            }
            res = max(res, dp[s]);
        }
        
        return res;
    }
};