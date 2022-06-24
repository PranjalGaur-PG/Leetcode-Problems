class Solution {
public:
    bool isPossible(vector<int>& target) {
         priority_queue<long long int> pq;
    int n=target.size();
    long long int sum=0;
    for(auto i: target)
    {
        pq.push(i);    // putting every element in max heap
        sum+=i;     //calculating total sum of target vector
    }
    while(pq.top()!=1)
    {
        long long int l=pq.top();     // max element
        pq.pop();
        long long int m=sum-l;    //remaining sum execpt max element
        if(m==1)                          // Eg: [1,100000] to avoid so many loops
            return true;  
        if(m>=l or m==0)          //Eg: [9,9,9] 
            return false;
        long long int x=l%m;     //new element to replace max element
        if(x==0)
            return false;
        pq.push(x);
        sum=m+x;          //updating new sum
    }
    return true;
    }
};