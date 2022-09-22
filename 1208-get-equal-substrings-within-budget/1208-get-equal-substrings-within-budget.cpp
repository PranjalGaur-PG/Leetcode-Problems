class Solution {
public:
    bool solve(vector<int>& amt, int sz, int cost, int n) {
        int temp = 0;
        for(int i=0;i<sz;i++) temp += amt[i];
        
        if(temp <= cost) return true;
        for(int i=sz;i<n;i++) {
            temp += (amt[i]-amt[i-sz]);
            if(temp <= cost) return true;
        }
        
        return false;
    }
        
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        
        vector<int> amt(n);
        for(int i=0;i<n;i++) amt[i] = abs(s[i]-t[i]);
        
//         int i=0, j=0, temp=0, ans=0;
//         while(j<n) {
//             temp += amt[j];
//             while(temp > maxCost) temp -= amt[i++];
            
//             ans = max(ans, j-i+1);
//             j++;
//         }
        
//         return ans;
        
//         cout<<n;
        
        int i = 1, j = n, ans = 0;
        
        while(i<=j) {
            int mid = i + (j-i)/2;
            if(solve(amt, mid, maxCost, n)) {
                ans = max(mid, ans);
                i = mid+1;
            }
            else j = mid-1;
        }
        
        return ans;
    }
};