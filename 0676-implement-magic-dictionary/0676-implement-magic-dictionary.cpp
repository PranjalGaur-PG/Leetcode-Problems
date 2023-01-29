class MagicDictionary {
public:
    unordered_set<string> st;
    MagicDictionary() {}
    
    void buildDict(vector<string> dict) {
        for(auto it : dict) st.insert(it);
    }
    
    bool search(string word) {
        for(int i=0;i<word.size();i++) {
            int val = word[i]-'a';
            
            for(int x=0;x<26;x++) {
                if(x==val) continue;
                word[i] = char(x+'a');
                if(st.find(word)!=st.end()) return true;
            }
            
            word[i] = char('a'+val);
        }
        
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */