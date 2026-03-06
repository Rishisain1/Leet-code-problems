class Solution {
public:


    int concatenatedBinary(int n) {
        long long ans=0;
        string s="1";
        int mod=1e9+7;
        for(int i=1;i<=n;i++){
            int x=s.length()-1;
                       
          
            ans=((ans<<x+1)+i)%mod;
            while(x>=0&&s[x]=='1'){
                s[x]='0';
                x--;
            }
            if(x>=0){
                s[x]='1';
            }else{
                s='1'+s;
            }
            
        }
        return ans;
    }
};