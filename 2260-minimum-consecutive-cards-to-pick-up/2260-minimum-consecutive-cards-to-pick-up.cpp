class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int, int> mp;
        
        int ans = INT_MAX, n = cards.size();
        for(int i=0;i<n;i++) {
            if(mp[cards[i]] != 0) {
                ans = min(ans, i + 2 - mp[cards[i]]);
            }
            
            mp[cards[i]] = i+1;
        }
        
        if(ans == INT_MAX) return -1;
        return ans;
    }
};