class Solution {
public:
    static bool srt(pair<int, char> p1, pair<int, char> p2) {
        return p1.first > p2.first;
    }
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        
        for(auto it : s) mp[it]++;
        vector<pair<int, char>> v;
        for(auto it : mp) v.push_back({it.second, it.first});
        
        sort(v.begin(), v.end(), srt);
        
        string ans;
        for(int i=0;i<v.size();i++) {
            char ch = v[i].second;
            for(int j=0;j<v[i].first;j++) ans.push_back(ch);
        }
        
        return ans;
    }
};