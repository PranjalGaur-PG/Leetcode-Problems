class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
//         int n = land.size(), m = land[0].size();
        
//         vector<vector<int>> ans;
//         vector<vector<int>> vis(n, vector<int> (m, 0));
        
//         for(int i=0;i<n;i++) {
//             for(int j=0;j<m;j++) {
//                 if(land[i][j]) {
//                     vector<int> temp;
//                     temp.push_back(i);
//                     temp
//                 }
//             }
//         }
        int m = land.size();
        int n = land[0].size();
        vector<vector<int>> ans;
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(land[i][j] == 1){
                    int k = j, l = i;
					// traversing in down and right direction until zero or end is hit
                    while(l<m && land[l][j] == 1) l++;
                    while(k<n && land[i][k] == 1) k++;
                    l--;
                    k--;
                    ans.push_back({i, j, l, k});
					// marking all the traversed farm to be visited
                    for(int g = i; g<=l; g++){
                        for(int h = j; h<=k; h++)
                            land[g][h] = -1;
                    }
                }
            }
        }
        return ans;
    }
};