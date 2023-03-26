class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int k) {
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
        vector<int> ans;
        
        ans.push_back(a.second.first);
        ans.push_back(a.second.second);
        return ans;

    }
};