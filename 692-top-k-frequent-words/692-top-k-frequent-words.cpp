class Solution {
public:
    static bool c_sort(pair<int, string> p1, pair<int, string> p2) {
        if(p1.first == p2.first) return (p1.second < p2.second);
        return p1.first > p2.first;
    }
        
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        vector<pair<int, string>> v;
        
        for(auto it : words) mp[it]++;
        for(auto it : mp) v.push_back({it.second, it.first});
        
        sort(v.begin(), v.end(), c_sort);
        
        vector<string> ans;
        int i = 0;
        while(i<k) {
            ans.push_back(v[i].second);
            i++;
        }
        
        return ans;
    }
};