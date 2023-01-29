struct Node {
    Node* links[26];
    bool end = false;
    
    bool containsEle(char ch) { return links[ch-'a']!=NULL; }
    void addEle(char ch) { links[ch-'a']=new Node(); }
    Node* nextEle(char ch) { return links[ch-'a']; }
    bool isEnd() { return end; }
    void setEnd() { end = true; }
};

class Solution {
public:
    string longestWord(vector<string>& words) {
        Node* root = new Node();
        
        for(auto it : words) {
            Node* node = root;
            for(int i=0;i<it.size();i++) {
                if(!node->containsEle(it[i]))
                    node->addEle(it[i]);
                node = node->nextEle(it[i]);
            }
            node->setEnd();
        }
        
        int len = 0;
        string ans = "";
        for(auto it : words) {
            Node* node = root;
            bool flg = true;
            for(int i=0;i<it.size();i++) {
                node = node->nextEle(it[i]);
                if(!node->isEnd()) {
                    flg = false;
                    break;
                }
            }
            
            if(flg) {
                if(len < it.size()) {
                    len = it.size();
                    ans = it;
                }
                else if(len == it.size()) ans = min(ans, it);
            }
        }
        
        return ans;
    }
};