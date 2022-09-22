class Solution {
public:
    string reverseWords(string s) {
        int i = 0;
        for (int j = 0; j < s.size(); ++j) {
            if (s[j] == ' ') {
                reverse(s.begin() + i, s.begin() + j);
                i = j + 1;
            }
        }
        reverse(s.begin() + i, s.end());
        return s;
//         stack<char> stk;
//         int n=s.size();
        
//         s.push_back(' ');
//         for(int i=0;i<=n;i++) {
//             if(s[i] != ' ') stk.push(s[i]);
//             else {
//                 int sz=stk.size();
//                 for(int j=i-sz;j>i;j++) {
//                     s[j] = stk.top();
//                     stk.pop();
//                 }
//             }
//         }
//         s.erase(n,1);
//         return s;
    }
};