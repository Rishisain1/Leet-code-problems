class Solution {
public:

    int solve(vector<int>&nums,int robbed,int i,vector<vector<int>>&dp){
        int n=nums.size();
        if(i>=n)return 0;
        if(dp[i][robbed]!=-1)return dp[i][robbed];
        if(i==0){
            return dp[i][robbed]=max(solve(nums,1,i+2,dp)+nums[i],solve(nums,0,i+1,dp));
        }
        else if(i==n-1){
            if(robbed){
                return 0;
            }
            else{
                return nums[i];
            }
        }
        else{
            return dp[i][robbed]= max(solve(nums,robbed,i+2,dp)+nums[i],solve(nums,robbed,i+1,dp));
        }
    }

    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return solve(nums,0,0,dp);
    }
};