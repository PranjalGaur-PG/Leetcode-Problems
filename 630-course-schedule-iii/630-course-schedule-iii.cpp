class Solution {
public:
    static bool cus_sort(pair<int, int> a, pair<int, int> b) {
        return (a.second < b.second);
    }
    int scheduleCourse(vector<vector<int>>& c) {
        vector<pair<int, int>> p;
        
        for(auto it : c) p.push_back({it[0], it[1]});
        
        sort(p.begin(), p.end(), cus_sort);
        
        priority_queue<int> pq;
        int time = 0;
        for(auto it : p) {
            time += it.first;
            pq.push(it.first);
            
            if(time > it.second) {
                time -= pq.top();
                pq.pop();
            }
        }
        
        return pq.size();
    }
};