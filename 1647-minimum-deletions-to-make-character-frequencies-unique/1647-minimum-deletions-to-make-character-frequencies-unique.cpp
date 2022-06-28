class Solution {
public:
    int minDeletions(string s) {
        int n = s.size();
        unordered_map<int, int> mp;
        
        for(int i=0;i<n;i++) mp[s[i]-'a']++;
        
        // vector<int> temp;
        // for(auto it : mp) temp.push_back(it.second);
        // sort(temp.begin(), temp.end());
        
        int ans = 0;
        unordered_map<int, int> temp;
        
        for(auto it : mp) {
            int cnt = it.second;
            
            if(temp[cnt]>0) {
                while(cnt>0 && temp[cnt]>0) {
                    cnt--;
                    ans++;
                }
            }
            if(cnt>0) temp[cnt]++;
        }
        
        return ans;
    }
};