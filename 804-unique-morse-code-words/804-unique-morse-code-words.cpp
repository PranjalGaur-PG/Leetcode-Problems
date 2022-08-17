class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string al[]={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        int i,j,k,c=0,x,y,n=words.size();
        if(n==0) return 0;
        string s[n];
        set<string> ss;
        for(i=0;i<n;i++) {
            for(j=0;j<words[i].size();j++) {
                s[i] += al[words[i][j]-'a'];
            }
            ss.insert(s[i]);
        }
        return ss.size();
    }
};