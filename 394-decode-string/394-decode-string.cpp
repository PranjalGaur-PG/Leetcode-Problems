class Solution {
public:
    string decodeString(string s) {
        int n = s.size();
        stack<pair<int, string>> st;
        
        string ans;
        int num = 0;
        
        for(int i=0;i<n;i++) {
            if(isdigit(s[i])) {
                num = (num*10) + (s[i]-'0');
            }
            else if(s[i]=='[') {
                st.push({num, ans});
                ans = "";
                num = 0;
            }
            else if(s[i]==']') {
                string t = ans;
                for(int j=1;j<st.top().first;j++)
                    t += ans;
                ans = st.top().second + t;
                st.pop();
            }
            else ans.push_back(s[i]);
        }
        
        return ans;
    }
};