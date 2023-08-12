class Solution {
public:
    vector<int> grayCode(int n) {
        if(n==1) return { 0, 1 };
        
        vector<int> ans = grayCode(n-1);
        int ans_size = ans.size();
        int a = pow(2,n-1);
        
        for(int i=ans_size-1;i>=0; i--){
            ans.push_back(ans[i]+a);
        }
        
        return ans;
    }
};