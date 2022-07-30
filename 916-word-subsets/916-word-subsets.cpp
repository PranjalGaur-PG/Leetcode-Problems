class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        
        vector<int> hash(26, 0);
        for(auto it : words2) {
            vector<int> temp(26, 0);
            
            for(auto it2 : it) temp[it2-'a']++;
            
            for(int i=0; i<26; i++) hash[i] = max(temp[i], hash[i]); 
        }
        
        vector<string> ans;
        for(auto it: words1) {
            vector<int> temp(26, 0);
            
            for(auto it2 : it) temp[it2-'a']++;
            
            bool flg = true;
            for(int i=0;i<26;i++) {
                if(temp[i]<hash[i]) flg = false;
            }
            
            if(flg) ans.push_back(it);
        }
        
        return ans;
    }
};