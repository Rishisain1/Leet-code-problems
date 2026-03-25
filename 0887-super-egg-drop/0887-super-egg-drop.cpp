class Solution {
public:

int solve(int k,int n,vector<vector<int>> &dp){
    if(k==1||n==1||n==0){
        return n;
    }
   if(dp[k][n]!=-1)return dp[k][n];
    int ans=INT_MAX;
    int low=1,high=n;
    while(low<=high){
        int a=(low+high)/2;
        int br;
        if(dp[k-1][a-1]!=-1){
            br=dp[k-1][a-1];

        }
        else{
            br=solve(k-1,a-1,dp);
        }
        int nbr;
        if(dp[k][n-a]!=-1){
            nbr=dp[k][n-a];
        }
        else{
            nbr=solve(k,n-a,dp);
        }
        ans=min(ans,1+max(br,nbr));
        if(nbr>br){
            low=a+1;
        }
        else{
            high=a-1;
        }
    }
    return dp[k][n]=ans;
}

    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(k+1,vector<int>(n+1,-1));
        return solve(k,n,dp);
    }
};