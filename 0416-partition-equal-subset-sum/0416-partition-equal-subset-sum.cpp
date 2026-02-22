class Solution {
public:

// bool so

//memoization
bool solve(vector<int> &nums,int sum,int rem,int n,vector<vector<int>> &cache){
    if(sum==rem){
        return 1;
    }
    if(n<0){
        return 0;
    }
    if(cache[n][sum]!=-1)return cache[n][sum];
    return cache[n][sum]=solve(nums,sum-nums[n],rem+nums[n],n-1,cache)||solve(nums,sum,rem,n-1,cache);
}

    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        vector<vector<int>> cache(n,vector<int>(sum+1,-1));
        return solve(nums,sum,0,n-1,cache);
    }
};