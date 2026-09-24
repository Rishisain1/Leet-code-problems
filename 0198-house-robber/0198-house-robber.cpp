class Solution {
public:

    // int solve(vector<int>&nums,int i,vector<int>&dp){
    //     int n=nums.size();
    //     if(i>=n){
    //         return 0;
    //     }
    //     if(dp[i]!=-1)return dp[i];
    //     return dp[i]=max(solve(nums,i+2,dp)+nums[i],solve(nums,i+1,dp));
    // }
    int solve(vector<int>&nums,int i,int n){
        int prev1=0,prev2=0;
        for(;i<n;i++){
            int curr=max(prev1,prev2+nums[i]);
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
    int rob(vector<int>& nums) {
        // vector<int> dp(nums.size(),-1);
        // return solve(nums,0,dp);
        return solve(nums,0,nums.size());
    }
};