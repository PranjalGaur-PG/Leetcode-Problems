class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        
        set<int> visited(forbidden.begin(),forbidden.end());

        queue<int> q;
        q.push(0);
        
        int step = 0;
        
        while(!q.empty()){
            int sz = q.size();
          
            for(int i = 0; i < sz; i++){
                
                int cur = q.front();
                q.pop();
                bool wasBack = cur < 0;
                cur = abs(cur);
                
                if(cur == x) return step; 
                
                int next = cur + a;
                if(next < 6000 && visited.find(next) == visited.end()){
                    visited.insert(next);
                    q.push(next);
                }
                
                next = cur - b;
                if(!wasBack && next > 0 && visited.find(next) == visited.end()){
                    q.push(next * -1);
                }
            }
             step++;
        }
        
        return -1;
    }
};