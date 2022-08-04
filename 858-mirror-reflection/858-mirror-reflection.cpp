class Solution {
public:
    int mirrorReflection(int p, int q) {
        while (p % 2 == 0 && q % 2 == 0){ 
            p/=2;
            q/=2;
        }
      
        
       // q->even, p->odd
        if(q%2==0 && p%2!=0)
            return 0;
        
        // p->even, q->odd
        if(p%2==0 && q%2!=0)
            return 2;
        
        //p->odd, q->odd
        if(p%2!=0 && q%2!=0)
            return 1;
        
        return -1;
    }
};