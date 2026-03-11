class Solution {
public:
const int mod=1e9+7;
int solve(int zero,int one,int limit,int last,vector<vector<vector<int>>> &dp){
    if(zero==0&&one==0){
        return 1;
    }
    if(last!=-1&&dp[zero][one][last]!=-1)return dp[zero][one][last];
    long long ans=0;
    if(last!=0){
        for(int i=1;i<=limit;i++){
            if(zero>=i){
                ans+=solve(zero-i,one,limit,0,dp)%mod;
            }
        }
    }
    if(last!=1){
        for(int i=1;i<=limit;i++){
            if(one>=i){
                ans+=solve(zero,one-i,limit,1,dp)%mod;
            }
        }
    }
    if(last==-1){
        return ans%mod;
    }
    return dp[zero][one][last]=ans%mod;
}

    int numberOfStableArrays(int zero, int one, int limit) {
        vector<vector<vector<int>>> dp(zero+1,vector<vector<int>>(one+1,vector<int>(2,-1)));
        return solve(zero,one,limit,-1,dp);
    }
};