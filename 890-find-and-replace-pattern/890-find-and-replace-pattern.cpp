class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans; //answer vector that is to be returned
        for(auto &word : words) 
        {
            char a[26], b[26];           // two charater arrays to store one to one relationship                  
            if(word.size() != pattern.size()) //obvious
                continue;
            for(int i=0; i<26; i++) //intialize with something identifiable
            {
                b[i] = '.'; 
                a[i]='.';
            }
            bool f = 1;
            for(int i=0; i<pattern.size(); i++)
            {
                if(a[pattern[i]-'a'] == '.' && b[word[i]-'a'] == '.') { //word not inserted already
                    a[pattern[i]-'a'] = word[i];
                    b[word[i]-'a'] = pattern[i];
                }
                else {
                    if(a[pattern[i]-'a'] != word[i] || b[word[i]-'a'] != pattern[i])  //if either violates the one-to-one relationship the set flag to zero
                        f=0;
                }
                
            }
            
            if(f)
                ans.push_back(word);
        }
        
        
       return ans;
    }
};