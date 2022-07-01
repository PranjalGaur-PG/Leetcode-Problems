class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int ts) {
        vector<pair<int,int>> v;
        int i,j,c=0,n=boxTypes.size(),val=0;
        
        for(i=0;i<n;i++) v.push_back({boxTypes[i][1],boxTypes[i][0]});
        
        sort(v.rbegin(),v.rend());
        i=0;
        while(ts>0 && i<n) {
            if(v[i].second <= ts) {
                val += ((v[i].first) * (v[i].second));
                ts -= v[i].second;
            }
            else {
                val += v[i].first*ts;
                ts=0;
            }
            i++;
            cout<<val<<" ";
        }
        return val;
    }
};