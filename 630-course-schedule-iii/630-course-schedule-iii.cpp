class Solution {
public:
    static bool cus_sort(vector<int> a, vector<int> b) {
        return (a[1]<b[1]);
    }
    int scheduleCourse(vector<vector<int>>& c) {
        // sort(c.begin(), c.end(), cus_sort);

        sort(c.begin(), c.end(), [](const vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });
        
        priority_queue<int> q;
        int sum = 0;
        for(auto i : c) {
            sum += i[0];
            q.push(i[0]);
            if(sum > i[1]) {
                sum -= q.top();
                q.pop();
            }
        }
        return q.size();
    }
};