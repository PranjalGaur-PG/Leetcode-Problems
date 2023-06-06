class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        set<vector<int>> st;
        
        int n = nums.size();
        if(n<4) return ans;
        
        sort(nums.begin(), nums.end());
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                long long tar = (long long)target - nums[i] - nums[j];
                
                int x = j+1, y = n-1;
                while(x<y) {
                    if(nums[x] + nums[y] == tar) {
                        st.insert({nums[i], nums[j], nums[x], nums[y]});
                        x++; y--;
                    }
                    else if(nums[x] + nums[y] < tar) x++;
                    else y--;
                }
            }
        }
        
        for(auto it : st)
            ans.push_back(it);
        return ans;
    }
};