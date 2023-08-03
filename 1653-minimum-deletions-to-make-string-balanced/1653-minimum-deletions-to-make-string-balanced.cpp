class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        vector<int> bvec(n), avec(n);
        
        int cnt = 0;
        for(int i = 0; i < n; i++){
            bvec[i] = cnt;
            if(s[i] == 'b') cnt++;
        }
        
        cnt = 0;
        for(int i = n - 1; i >= 0; i--){
            avec[i] = cnt;
            if(s[i] == 'a') cnt++;
        }
        
        int mini = INT_MAX;
        for(int i = 0; i < n; i++) mini = min(mini, bvec[i] + avec[i]);
        
        return mini;
        
//         int n = s.size();
//         vector<int> cnt_a(n), cnt_b(n);
        
//         for(int i=0, x=0;i<n;i++) {
//             if(s[i]=='b') x++;
//             cnt_b[i] = x;
//         }
//         for(int i=n-1, x=0;i>=0;i--) {
//             if(s[i]=='a') x++;
//             cnt_a[i] = x;
//         }
        
//         return ans;
    }
};