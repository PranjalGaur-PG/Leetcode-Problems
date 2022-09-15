class Solution {
public:
    static bool cmp(int a, int b) {
        return abs(a)<abs(b);
    }
    
    bool canReorderDoubled(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end(), cmp);
        
        unordered_map<int, int> mp;
        for(auto it : arr) mp[it]++;
        
        int cnt = 0, cntz=0;
        for(auto it : arr) {
            if(it == 0) cntz++;
                
            else if(mp[it]>0 && mp[it*2]>0) {
                cnt++;
                mp[it]--;
                mp[it*2]--;
            }
        }
        cout<<cnt*2 + cntz<<endl;
        
        // if(cntz%2) return false;
        return (((cnt*2) + cntz) == n);
    }
};