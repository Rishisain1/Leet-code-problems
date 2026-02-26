class Solution {
public:

// it is similar problem to the subsequence difference the only thing is they ask it in another manner
// recursion
// int solve(vector<int>& nums,int target,int &total,int first,int i){
//     if(i>=nums.size()){
//         if(target==(2*first)-total)return 1;
//         return 0;
//     }
//     return solve(nums,target,total,first+nums[i],i+1)+solve(nums,target,total,first,i+1);
// }

// memoization
int solve(vector<int>& nums,int target,int &total,int first,int i,vector<vector<int>> &dp){
    if(i>=nums.size()){
        if(target==(2*first)-total)return 1;
        return 0;
    }
    if(dp[i][first]!=-1){
        return dp[i][first];
    }
    return dp[i][first]=solve(nums,target,total,first+nums[i],i+1,dp)+solve(nums,target,total,first,i+1,dp);
}

    int findTargetSumWays(vector<int>& nums, int target) {
        int total=0;
        for(auto i:nums){
            total+=i;
        }

        // return solve(nums,target,total,0,0);//recuresion approach
        int n=nums.size();
        // vector<vector<int>> dp(n,vector<int>(total+1,-1));
        // return solve(nums,target,total,0,0,dp);
        if(total<target||(target+total)%2||target+total<0)return 0;

        vector<vector<int>> dp(n+1,vector<int>(total+1,0));
        int subsetsum=(target+total)/2;
        dp[0][0]=1;

        for(int i=1;i<=n;i++){
            for(int j=0;j<=subsetsum;j++){
                    
                    dp[i][j]=dp[i-1][j];
                    if(j>=nums[i-1]){
                        dp[i][j]+=dp[i-1][j-nums[i-1]];
                    }
                
            }
        }
        return dp[n][subsetsum];
    }
};