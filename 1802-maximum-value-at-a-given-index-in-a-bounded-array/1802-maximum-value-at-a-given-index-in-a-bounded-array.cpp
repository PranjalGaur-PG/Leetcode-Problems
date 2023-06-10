class Solution {
public:
     bool isValid(long long mid, long long n, long long index, long long maxSum){

        long long minSum = n;
        mid--;
        minSum += (min(mid,index)*(2*(mid-1) + 1 - min(mid,index)))/2 + (min(mid,(n-index))*(2*mid+1-min(mid,(n-index))))/2;

        if(minSum<=maxSum){
            return true;
        }
        return false;
    }
    

    int maxValue(int n, int index, int maxSum) {
        
        int start = 1, end = 1e9;
        int ans;
        long long a=n, b=index, c=maxSum;
        while(start<=end){
            long long mid = (start+end)/2;
            if(isValid(mid,a,b,c)){
                ans = mid;
                start = mid+1;
            }else{
                end = mid-1;
            }
        }
        return ans;
    }
};