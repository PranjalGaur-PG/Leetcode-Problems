class Solution {
public:
    int fun(string s) {
        vector<int> cnt(26, 0);
        
        for(auto it : s) cnt[it-'a']++;
        for(auto it : cnt) if(it) return it;
        
        return 0;
    }
    
    int fnd(int x, vector<int> arr, int n) {
        int ans = 0;
//         int i=0, j=n-1;
        
//         while(i<=j) {
//             int mid = (i+j)/2;
//             if(arr[mid]>=x) {
//                 ans = mid;
//                 i = mid+1;
//             }
//             else j = mid-1;
//         }
        
//         return n-ans;
        for(int i=0;i<n;i++) if(x<arr[i]) ans++;
        return ans;
    }
    
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        int n = words.size(), m = queries.size();
        vector<int> cnt_words(n), cnt_que(m), ans;
        
        for(int i=0;i<n;i++) cnt_words[i] = fun(words[i]);
        for(int i=0;i<m;i++) cnt_que[i] = fun(queries[i]);
        
        // sort(cnt_words.begin(), cnt_words.end());
        for(int i=0;i<m;i++) {
            ans.push_back(fnd(cnt_que[i], cnt_words, n));
        }
        
        return ans;
    }
};