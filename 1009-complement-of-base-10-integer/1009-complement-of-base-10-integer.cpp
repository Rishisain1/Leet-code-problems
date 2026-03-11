class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0){
            return 1;
        }
        int ans=0;
        unsigned p=1;
        while(n>0){
            if((n&1)==0){
                ans+=p;
            }
            n=n>>1;
            p=p*2;
        }
        return ans;
    }
};