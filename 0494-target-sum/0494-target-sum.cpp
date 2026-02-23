class Solution {
public:
// recursion
// int solve(vector<int>& nums, int target,int sum,int i){
//     if(i>=nums.size()){
//         if(sum==target)return 1;
//         return 0;
//     }
//     return solve(nums,target,sum,i+1)+solve(nums,target,sum-(nums[i]*2),i+1);
// }


int msolve(vector<int>& nums, int target,int sum,int i,vector<vector<int>> &dp){
    if(i>=nums.size()){
        if(sum==target)return 1;
        return 0;
    }
    if(sum<0) return 0;// additional condition only for memoization because it may give error
    if(dp[i][sum]!=-1){return dp[i][sum];}

    return dp[i][sum] = msolve(nums,target,sum,i+1,dp)+msolve(nums,target,sum-(nums[i]*2),i+1,dp);
}

    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        for(auto i: nums){
            sum+=i;

        }
        // normal recursion
        // return solve(nums,target,sum,0);

        //memoization
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        return msolve(nums,target,sum,0,dp);

    }
};