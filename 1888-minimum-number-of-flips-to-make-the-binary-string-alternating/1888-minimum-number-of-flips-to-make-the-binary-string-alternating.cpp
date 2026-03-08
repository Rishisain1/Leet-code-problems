class Solution {
public:
    int minFlips(string s) {
        int op0=0;
        int op1=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            // op0=op0+(s[i]^i)&1;//due to order precedence thi output is wrong so carefully write the code 
            op0=op0+((s[i]^i)&1);
        }
        op1=n-op0;
        int ans=min(op0,op1);
        // s=s+s;//there is no need because s[i]==s[n+i] so we assume that we make s+s but its not really 
        for(int i=0;i<n;i++){
            if((s[i]^i)&1){
                op0--;
            }
            else{
                op1--;
            }
            if((s[i]^(i+n))&1){
                op0++;
            }
            else{
                op1++;
            }
            ans=min(ans,min(op1,op0));
        }
        return ans;
    }
};