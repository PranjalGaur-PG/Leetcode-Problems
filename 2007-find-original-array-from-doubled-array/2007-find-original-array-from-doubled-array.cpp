class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        unordered_map<int, int> mp;
        sort(changed.begin(), changed.end());
        
        vector<int> ans;
        for(int i=0;i<n;i++) {
            if(changed[i]%2==0 && mp[changed[i]/2] > 0) {
                ans.push_back(changed[i]/2);
                mp[changed[i]/2]--;
            }
            else mp[changed[i]]++;
        }
        
        if(ans.size()*2 != n) return {};
        return ans;
    }
};