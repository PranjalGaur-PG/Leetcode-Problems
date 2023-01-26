struct Node {
    Node* links[26];
    bool flg = false;
    
    bool containsEle(char ch) { 
        return links[ch-'a'] != NULL; 
    }
    void addEle(char ch, Node* node) { 
        links[ch-'a'] = node; 
    }
    Node* nextEle(char ch) { 
        return links[ch-'a']; 
    }
    bool isEnd() { 
        return flg; 
    }
    void setEnd() { 
        flg = true; 
    }
};

class Solution {
public:
    string fun(Node* node, string str) {
        string temp;
        
        for(int i=0;i<str.size();i++) {
            if(node->isEnd()) return temp;
            if(!node->containsEle(str[i])) return str;
            
            temp.push_back(str[i]);
            node = node->nextEle(str[i]);
        }
        
        return str;
    }
    
    string replaceWords(vector<string>& dic, string sen) {
        Node* root = new Node();
        
        for(auto it : dic) {
            Node* node = root;
            for(int i=0;i<it.size();i++) {
                if(!node->containsEle(it[i])) node->addEle(it[i], new Node());
                node = node->nextEle(it[i]);
            }
            node->setEnd();
        }
        
        string ans, temp;
        bool flg = false;
        
        for(auto it : sen) {
            if(it == ' ') {
                cout<<temp<<"-";
                ans += fun(root, temp);
                temp="";
                ans.push_back(' ');
            }
            else temp.push_back(it);
        }
        cout<<temp;
        ans += fun(root, temp);
        
        return ans;
    }
};