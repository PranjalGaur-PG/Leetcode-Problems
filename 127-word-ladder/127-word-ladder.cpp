class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> s(wordList.begin(), wordList.end());
        queue<string> q;
        
        int steps = 0;
        q.push(beginWord);
        while(q.size()) {
            
            int sz = q.size();
            steps++;
            cout<<" "<<steps;
            while(sz--) {
                
                string temp = q.front();
                q.pop();
                
                if(temp == endWord) return steps;
                s.erase(temp);
                
                for(int i=0;i<temp.size();i++) {
                    char ch = temp[i];
                    for(int j=0;j<26;j++) {
                        temp[i] = 'a' + j;
                        if(s.find(temp) != s.end()) q.push(temp);
                    }
                    temp[i] = ch;
                }
            }
        }
        return 0;
    }
};