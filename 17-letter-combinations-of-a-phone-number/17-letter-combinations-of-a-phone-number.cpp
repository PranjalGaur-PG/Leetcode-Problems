class Solution {
public:
    vector<string> ans;
    
    void fun(string digits, int ind, string& temp, unordered_map<char,string>& mp) {
        if(ind == digits.size()) {
            ans.push_back(temp);
        }
        
        string s = mp[digits[ind]];
        for(int i=0; i<s.size(); i++) {
            
            temp.push_back(s[i]);
            fun(digits, ind+1, temp, mp);
            temp.pop_back();
            
        }
    }
    
    vector<string> letterCombinations(string digits) {
        
        unordered_map<char,string> mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        
        if(digits.size()==0) return ans;
        
        string temp = "";
        fun(digits, 0, temp, mp);
        return ans;
    }
};