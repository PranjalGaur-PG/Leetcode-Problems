class Solution {
public:
    void solve(int val, vector<string>& con, int ind) {
        
    }
        
    bool validUtf8(vector<int>& data) {
        int n = data.size();
        vector<string> con(n);
        for(int i=0;i<n;i++) solve(data[i], con, i);
        
        for(int i=0;i<n;i++) {
            if(data[i]<=127) continue;                      // 0xxxxxxx
            
            else if(data[i]>=192 && data[i]<=223) {         // 110xxxxx 10xxxxxx
                
                if(i+1>=n || !(data[i+1]>=128 && data[i+1]<=191)) return false;
                i += 1;
            }
            
            else if(data[i]>=224 && data[i]<=239) {         // 1110xxxx 10xxxxxx 10xxxxxx
                if(i+2>=n || !(data[i+1]>=128 && data[i+1]<=191) || !(data[i+2]>=128 && data[i+2]<=191)) 
                    return false;
                i += 2;
            }
            
            else if(data[i]>=240 && data[i]<=247) {// 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
                if(i+3>=n || !(data[i+1]>=128 && data[i+1]<=191) 
                   || !(data[i+2]>=128 && data[i+2]<=191) 
                   || !(data[i+3]>=128 && data[i+3]<=191)) 
                        return false;
                i += 3;
            }
            else return false;
        }
        
        return true;
    }
};