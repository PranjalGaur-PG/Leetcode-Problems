class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<long long, int>> pq;
        
        for(int i=0;i<points.size();i++) {
            int x = points[i][0];
            int y = points[i][1];
            pq.push({-1*(pow(x,2) + pow(y,2)), i});
        }
        
        vector<vector<int>> ans;
        while(k--) {
            int ind = pq.top().second;
            pq.pop();
            vector<int> t;
            t.push_back(points[ind][0]);
            t.push_back(points[ind][1]);
            ans.push_back(t);
        }
        
        return ans;
        
    }
};