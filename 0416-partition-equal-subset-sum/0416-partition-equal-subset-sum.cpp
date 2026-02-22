class Solution {
public:

//memoization
bool solve(vector<int> &nums,int sum,int n,vector<vector<int>> &cache){
    if(sum==0){
        return 1;
    }
    if(n<0){
        return 0;
    }
    if(cache[n][sum]!=-1)return cache[n][sum];
    if(sum>=nums[n]){
        return cache[n][sum]=solve(nums,sum-nums[n],n-1,cache)||solve(nums,sum,n-1,cache);
    }
    else{
        return cache[n][sum]=solve(nums,sum,n-1,cache);
    }
}

    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2)return false;
        sum=sum/2;
        vector<vector<int>> cache(n,vector<int>(sum+1,-1));
        return solve(nums,sum,n-1,cache);
    }
};