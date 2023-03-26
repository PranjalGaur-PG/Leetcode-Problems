class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int k) {
//         priority_queue<pair<double, pair<int,int>>>pq;
//         for(int i = 0; i < A.size(); i++)
//         {
//             for(int j=i+1;j<A.size();j++) {
//                 pq.push({1.0*A[i]/A[j], {A[i],A[j]}});
//             }
            
//         }
        
//        while(k--) pq.pop();
        
//         vector<int> ans;
//         ans.push_back(pq.top().second.first);
//         ans.push_back(pq.top().second.second);
//         return ans;
        priority_queue<pair<double,pair<int,int>>> Q;
        
        for(int i=0;i<A.size();i++){
            for(int j=A.size()-1;j>i;j--){
                double a = (double)A[i]/(double)A[j];
                Q.push({a,{A[i],A[j]}});
            }
        }
        
        int n = Q.size();
        while(n>k){
        Q.pop();
        n--;
        }
        auto a = Q.top();
        vector<int> ans(2);
        ans[0] = a.second.first;
        ans[1] = a.second.second;
        return ans;

    }
};