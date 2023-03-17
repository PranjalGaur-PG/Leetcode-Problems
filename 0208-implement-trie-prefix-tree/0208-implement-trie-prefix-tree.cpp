struct Node {
    Node* links[26];
    bool End = false;
    
    bool containsChar(char ch) { return links[ch-'a'] != NULL; }
    void addChar(char ch) { links[ch-'a'] = new Node(); }
    Node* nextChar(char ch) { return links[ch-'a']; }
    bool isEnd() { return End; }
    void setEnd() { End = true; }
};

class Trie {
public:
    Node* root;
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        
        for(int i=0; i<word.size(); i++) {
            if(!node->containsChar(word[i])) node->addChar(word[i]);
            node = node->nextChar(word[i]);
        }
        
        node->setEnd();
    }
    
    bool search(string word) {
        Node* node = root;
        
        for(int i=0; i<word.size(); i++) {
            if(!node->containsChar(word[i])) return false;;
            node = node->nextChar(word[i]);
        }
        
        return node->isEnd();
    }
    
    bool startsWith(string word) {
        Node* node = root;
        
        for(int i=0; i<word.size(); i++) {
            if(!node->containsChar(word[i])) return false;;
            node = node->nextChar(word[i]);
        }
        
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */