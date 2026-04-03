class Solution {
public:




int solve(int i,int j,int nue, int n, int m,vector<vector<int>>& coins,vector<vector<vector<int>>> &dp){
    if(i==n-1&&j==m-1){
        if(coins[i][j]>=0){
            return coins[i][j];
        }
        else{
            if(nue>0){
                return 0;
            }
            else{
                return coins[i][j];
            }
        }
    }
    if(dp[i][j][nue]!=INT_MIN){
        return dp[i][j][nue];
    }
    int r=INT_MIN;
    int d=INT_MIN;
    if(i+1<n){
        if(coins[i][j]>=0){
            d=solve(i+1,j,nue,n,m,coins,dp)+coins[i][j];
        }
        else{
            if(nue>0){
                int nu=solve(i+1,j,nue-1,n,m,coins,dp);
                int nnu=solve(i+1,j,nue,n,m,coins,dp)+coins[i][j];
                d=max(nu,nnu);
            }
            else{
                d=solve(i+1,j,nue,n,m,coins,dp)+coins[i][j];
            }
        }
    }
    if(j+1<m){
        if(coins[i][j]>=0){
            r=solve(i,j+1,nue,n,m,coins,dp)+coins[i][j];
        }
        else{
            if(nue>0){
                int nu=solve(i,j+1,nue-1,n,m,coins,dp);
                int nnu=solve(i,j+1,nue,n,m,coins,dp)+coins[i][j];
                r=max(nu,nnu);
            }
            else{
                 r=solve(i,j+1,nue,n,m,coins,dp)+coins[i][j];
            }
        }
    }
    return dp[i][j][nue]= max(d,r);

}

    int maximumAmount(vector<vector<int>>& coins) {
        int n=coins.size();
        int m=coins[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(3,INT_MIN)));
        return solve(0,0,2,n,m,coins,dp);
    }
};