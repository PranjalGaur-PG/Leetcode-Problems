class Solution {
public:
    void fun(vector<vector<int>> &result, vector<int> &path, int start, int k, int target){
        if(target==0&&k==0){
            result.push_back(path);
            return;
        }
        for(int i=start;i<=10-k&&i<=target;i++){
            path.push_back(i);
            fun(result,path,i+1,k-1,target-i);
            path.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> path;
        fun(res, path, 1, k, n);
        return res;
}


};