class Solution {
public:

int todecimal(string ans){
    int n=ans.size();
    int p2=1;
    int mod=1e9+7;
    int num=0;
    for(int i=n-1;i>=0;i--){
        if(ans[i]=='1'){
            num=(num+p2)%mod;            
        }
        p2=(p2*2)%mod;
    }
    return num;
}

    int concatenatedBinary(int n) {
        string ans="";
        string s="1";
        for(int i=1;i<=n;i++){
            ans+=s;
            int x=s.length()-1;
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
        return todecimal(ans);
    }
};