#define  MOD 1000000007;
class Solution {
public:

int solve(int zero,int one,int limit,int last,int occ,vector<vector<vector<vector<int>>>> &dp){
    if(zero==0&&one==0){
        return 1;
    }
    if(dp[zero][one][last][occ]!=-1)return dp[zero][one][last][occ];
    
    if(last==0){
        int z=0;
        int o=0;
        if(occ<limit&&zero>0){
            z=solve(zero-1,one,limit,0,occ+1,dp);
        }
        if(one>0)
        o=solve(zero,one-1,limit,1,1,dp);
        return dp[zero][one][last][occ]=(z+o)%MOD;
    }
    if(last==1){
        int z=0;
        int o=0;
        if(occ<limit&&one>0){
            o=solve(zero,one-1,limit,1,occ+1,dp);
        }
        if(zero>0){
            z=solve(zero-1,one,limit,0,1,dp);
        }
        return dp[zero][one][last][occ]= (z+o)%MOD;
    }
    return 0;
}


    int numberOfStableArrays(int zero, int one, int limit) {
        vector<vector<vector<vector<int>>>> dp(zero+1,vector<vector<vector<int>>>(one+1,vector<vector<int>>(2,vector<int>(limit+1,-1))));
        return (solve(zero-1,one,limit,0,1,dp)+solve(zero,one-1,limit,1,1,dp))%MOD;
        
    }
    
};