class Solution {
public:
    string pushDominoes(string dom) {
        int n = dom.length(); 
       queue<pair<char,int>> q;
       for(int i=0;i<n;i++)
       {
           if(dom[i]!='.')q.push({dom[i],i});
       }
       while(q.empty()==false)
       {
           char ch = q.front().first;
           int ind = q.front().second;
           q.pop();
           if(ch=='L')
           {
               if(ind-1>=0 && dom[ind-1]=='.')
               {
                  dom[ind-1] = 'L';
                  q.push({'L',ind-1}); 
               }
           }
           else if(ch=='R')
           {
               if(ind+1<n && dom[ind+1]=='.')
               {
                   if(ind+2<n && dom[ind+2]=='L')
                       q.pop();
                   else{
                       dom[ind+1]='R';
                       q.push({'R',ind+1});
                   }
               }
           }
       }
       return dom; 
    }
};