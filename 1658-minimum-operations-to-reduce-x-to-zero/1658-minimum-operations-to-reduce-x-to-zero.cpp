class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int s=0, n=nums.size(), tot=0, temp=0;
        unordered_map<int,int> mp;
        mp[0]=-1;
        
        tot = accumulate(nums.begin(),nums.end(),0);
        if(tot == x) return n;
        x = tot-x;
        
        for(int i=0;i<n;i++) {
            s += nums[i];
            if(mp.find(s-x) != mp.end()) {
                temp = max(temp,i-mp[s-x]);
            }
            
            if(mp.find(s) == mp.end()) mp[s] = i;
        }
        
        // cout<<temp<<" ";
        if(temp == 0) return -1;
        return (n-temp);
    }
};