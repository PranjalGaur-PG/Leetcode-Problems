struct Node {
    Node* links[26];
    int cnt = 0;
    
    bool containsEle(char ch) {
        return links[ch-'a'] != NULL;
    }
    
    void addEle(char ch, Node* node) {
        links[ch-'a'] = node;
    }
    
    Node* nextEle(char ch) {
        return links[ch-'a'];
    }
    
    void increCount() {
        cnt++;
    }
    
    int getCount() {
        return cnt;
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        int n = strs.size();
        
        Node* root = new Node();
        for(auto it : strs) {
            Node* node = root;
            
            for(int j=0;j<it.size();j++) {
                if(!node->containsEle(it[j])) 
                    node->addEle(it[j], new Node());
                
                node = node->nextEle(it[j]);
                node->increCount();
            }
        }
        
        string s = strs[0];
        Node* node = root;
        
        for(int i=0;i<s.size();i++) {
            node = node->nextEle(s[i]);
            if(node->getCount()<n) return ans;
            
            ans.push_back(s[i]);
            
        }
        // if(node->getCount()==n) ans+= strs[0][strs[0].size()-1];
        
        return ans;
    }
};