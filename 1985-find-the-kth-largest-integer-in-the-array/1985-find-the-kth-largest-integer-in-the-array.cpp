class Solution {
public:
    static bool cus_sort(pair<int, string> a, pair<int, string> b) {
        if(a.first == b.first) return a.second > b.second;
        return a.first > b.first;
    }
    string kthLargestNumber(vector<string>& nums, int k) {
        vector<pair<int, string>> v;
        
        for(auto it : nums) {
            v.push_back({ it.size(), it });
        }
        
        sort(v.begin(), v.end(), cus_sort);
        return v[k-1].second;
        
    }
};