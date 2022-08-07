class Solution {
public:
    int countVowelPermutation(int n) {
        int N = 1e9 + 7;
        long a,e,i,o,u;
        long pa,pe,pi,po,pu;
        pa=pe=pi=po=pu=1;
        for(int j=2;j<=n;++j)
        {
            a=pe;           //a  e
            e=pa+pi;        //e  a/i
            i=pa+pe+po+pu;  //i  a/e/o/u
            o=pi+pu;        //o  i/u
            u=pa;           //u  a
            pa=a%N,pe=e%N,pi=i%N,po=o%N,pu=u%N;
        }
        long ans=(pa+pe+pi+po+pu)%N;
        return ans;
    }
};