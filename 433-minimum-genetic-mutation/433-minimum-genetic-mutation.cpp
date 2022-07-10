class Solution {
public:
    void addWord(string word, unordered_set<string>& st, queue<string>& q) {
        st.erase(word);
        for(int i=0; i<word.size(); i++) {
            char tmp = word[i];
            for(char c:string("ACGT")) {
                word[i] = c;
                if(st.count(word)) {
                    q.push(word);
                    st.erase(word);
                }
            }
            word[i] = tmp;
        }
    }
    
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> st(bank.begin(), bank.end());
        // st.insert(start);
        // st.insert(end);
        
        queue<string> q;
        q.push(start);
        
        string s = "ACGT";
        
        int ans = -1;
        while(q.size()) {
            int n = q.size();
            ans++;
            
            while(n--) {
                string temp = q.front();
                q.pop();
                
                if(temp == end) return ans;
                for(int i=0;i<8;i++) {
                    char ch = temp[i];
                    
                    for(int j=0;j<4;j++) {
                        if(ch == s[j]) continue;
                        temp[i] = s[j];
                        if(st.find(temp) != st.end()) {
                            q.push(temp);
                            st.erase(temp);
                        }
                    }
                    
                    temp[i] = ch;
                }
            }
        }
        
        return -1;
    }
};