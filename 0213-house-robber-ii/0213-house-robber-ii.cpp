class Solution {
public:

    int solve(vector<int>&nums,vector<int>&dp,int i,int n){
        if(i>=n){
            return 0;
        }
        if(dp[i]!=-1)return dp[i];
        return dp[i]=max(solve(nums,dp,i+1,n),solve(nums,dp,i+2,n)+nums[i]);
    }

    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        vector<int>dp1(n,-1);
        vector<int>dp2(n,-1);
        return max(solve(nums,dp1,0,n-1),solve(nums,dp2,1,n));
    }
};