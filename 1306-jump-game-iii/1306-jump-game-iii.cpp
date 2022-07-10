class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        queue<int> q;
        int n = arr.size();
        q.push(start);
        
        while(q.size()) {
            int ind = q.front();
            q.pop();
            
            if(ind == INT_MIN || arr[ind] == INT_MIN) continue;
            if(arr[ind]==0) return true;
            
            if(ind + arr[ind] < n) q.push(ind + arr[ind]);
            if(ind - arr[ind] >=0) q.push(ind - arr[ind]);
            arr[ind] = INT_MIN;
        } 
        
        return false;
    }
};