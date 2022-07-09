class Solution {
public:
//     vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
//         int n = heights.size(), m = heights[0].size();
        
//         vector<vector<bool>> pac(n, vector<bool> (m, false)), atl(n, vector<bool> (m, false));
        
//         for(int i=0;i<n;i++) {
//             for(int j=0;j<m;j++) {
//                 if(i==0 || j==0) pac[i][j] = true;
//                 else if(heights[i][j]>=heights[i-1][j] || heights[i][j]>=heights[i][j-1]) pac[i][j]=true;
//                 else pac[i][j] = false;
//             }
//         }
        
//         for(int i=n-1;i>=0;i--) {
//             for(int j=m-1;j>=0;j--) {
//                 if(i==n-1 || j==m-1) atl[i][j] = true;
//                 else if(heights[i][j]>=heights[i+1][j] || heights[i][j]>=heights[i][j+1]) atl[i][j]=true;
//                 else atl[i][j] = false;
//             }
//         }
        
//         vector<vector<int>> ans;
//         set<pair<int, int>> st;
//         for(int i=0;i<n;i++) {
//             for(int j=0;j<m;j++) {
//                 if(pac[i][j] && atl[i][j] && st.find({i, j})==st.end()) {
//                     vector<int> temp;
//                     temp.push_back(i);
//                     temp.push_back(j);
//                     ans.push_back(temp);
//                 }
//             }
//         }
        
//         return ans;
//     }
    
     void helper(vector<vector<int> > &mat,int i,int j,int m,int n,vector<vector<bool>>& visited){

    if(i<0 or j<0 or i>=m or j>=n or visited[i][j]){
        return;
    }
    visited[i][j]=true;
    // check on four direction if they exist
    if(i-1>=0 && mat[i][j] <= mat[i-1][j] and !visited[i-1][j]){
        helper(mat,i-1,j,m,n,visited);
    }
    if(j-1>=0 && mat[i][j] <= mat[i][j-1] and !visited[i][j-1]){
        helper(mat,i,j-1,m,n,visited);
    }
    if(i+1<m && mat[i][j] <= mat[i+1][j] and !visited[i+1][j]){
        helper(mat,i+1,j,m,n,visited);
    }
    if(j+1<n && mat[i][j] <= mat[i][j+1] and !visited[i][j+1]){
        helper(mat,i,j+1,m,n,visited);
    }
    return;
}    
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& mat){
    int m=mat.size();
    if(m==0){
        return {};
    }
    int n=mat[0].size();
    
    // int count=0;
    vector<vector<bool>> blue(m,vector<bool>(n,false));
    vector<vector<bool>> red(m,vector<bool>(n,false));
    
    for(int i=0;i<m;i++){
        helper(mat,i,0,m,n,blue);
        helper(mat,i,n-1,m,n,red);
    }
    for(int j=0;j<n;j++){
        helper(mat,0,j,m,n,blue);
        helper(mat,m-1,j,m,n,red);
    }
        vector<vector<int>>ans;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(blue[i][j]&&red[i][j]){
                ans.push_back({i,j});
            }
        }
    }
    // return count;
        // cout<<ans.size();
        return ans;
}
    
};