class Solution {
public:
    int candy(vector<int>& ratings) {
//         int n = ratings.size();
        
//         int ans = 1, cnt = 2, j = 0;
//         bool flag = false;
            
//         for(int i=1;i<n;i++) {
//             if(ratings[i]>ratings[i-1]) {
//                 ans += cnt;
//                 cnt++;
//                 j = i;
//                 flag = true;
//             }
//             else {
//                 if(flag) {
//                     ans += 1;
//                     flag = false;
//                 }
//                 else ans += (i-j+1);
//                 cnt = 2;
//             }
//             cout<<ans<<" ";
//         }
        
//         return ans;
        int size = ratings.size();
        if(size<=1) return size;
        
        vector<int> num(size,1);
        for (int i = 1; i < size; i++) {
         if(ratings[i]>ratings[i-1])
             num[i]=num[i-1]+1;
        }
        
        for (int i= size-1; i>0 ; i--) {
         if(ratings[i-1]>ratings[i])
             num[i-1]=max(num[i]+1,num[i-1]);
        }
        
        int result=0;
        for (int i = 0; i < size; i++) {
         result+=num[i];
        }
        
        return result;
    }
};