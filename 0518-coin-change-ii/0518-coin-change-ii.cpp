class Solution {
public:
// recursion
// int solve(int amount,vector<int>&coins,int i){
//     if(amount==0){
//         return 1;
//     }
//     if(i>=coins.size()){
//         return 0;
//     }
//     if(coins[i]<=amount){
//         return solve(amount-coins[i],coins,i)+solve(amount,coins,i+1);
//     }
//     else{
//         return solve(amount,coins,i+1);
//     }
// }

// memoization
int solve(int amount,vector<int>&coins,int i,vector<vector<int>>&dp){
    if(amount==0){
        return 1;
    }
    if(i>=coins.size()){
        return 0;
    }
    if(dp[i][amount]!=-1)return dp[i][amount];
    if(coins[i]<=amount){
        return dp[i][amount]= solve(amount-coins[i],coins,i,dp)+solve(amount,coins,i+1,dp);
    }
    else{
        return dp[i][amount]=solve(amount,coins,i+1,dp);
    }
}

    int change(int amount, vector<int>& coins) {
        // return solve(amount,coins,0);
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return solve(amount,coins,0,dp);
    }
};