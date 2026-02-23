class Solution {
public:
// recursion with tle
// int solve(vector<int>& coins, int amount,int i){
//     if(amount==0){
//         return 0;
//     }
//     if(i<0){
//         return INT_MAX-1;
//     }
//     int take=INT_MAX;
//     int ntake=INT_MAX;
//     if(coins[i]<=amount){
//         return min(solve(coins,amount-coins[i],i)+1,solve(coins,amount,i-1));
//     }
    
//     return solve(coins,amount,i-1);
      
// }
int solve(vector<int>& coins, int amount,int i,vector<vector<int>>&dp){
    if(amount==0){
        return 0;
    }
    if(i<0){
        return INT_MAX-1;
    }
    if(dp[i][amount]!=-1)return dp[i][amount];
    if(coins[i]<=amount){
        return dp[i][amount]=min(solve(coins,amount-coins[i],i,dp)+1,solve(coins,amount,i-1,dp));
    }
    
    return dp[i][amount]=solve(coins,amount,i-1,dp);
      
}

    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        // int ans=solve(coins,amount,n-1);
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans=solve(coins,amount,n-1,dp);

        if(ans==INT_MAX-1){
            return -1;
        }
        return ans;
    }
};