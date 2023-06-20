class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
         int n = nums.size();

        if(k*2+1 > n) {
            vector<int> ans(n, -1);
            return ans;
        }

        vector<int> ans(k, -1);
        long s = 0;
        for(int i=0;i<2*k+1;i++) s += nums[i];
        for(int i=2*k+1;i<n;i++) {
            cout<<s<<" ";
            ans.push_back(s/(2*k+1));
            s += (nums[i]-nums[i-(2*k+1)]);
        }

        cout<<s<<" ";
        ans.push_back(s/(2*k+1));
        for(int i=0;i<k;i++) ans.push_back(-1);

        return ans;
    }
};