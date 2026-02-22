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
        // vector<vector<int>> cache(n,vector<int>(sum+1,-1));
        // return solve(nums,sum,n-1,cache);
         vector<vector<int>> cache(n+1,vector<int>(sum+1,0));
        for(int i=0;i<=n;i++){
            cache[i][0]=1;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                if(j>=nums[i-1]){
                    cache[i][j]=cache[i-1][j-nums[i-1]]||cache[i-1][j];
                }
                else{
                   cache[i][j]=cache[i-1][j];
                }
            }
        }
        return cache[n][sum];
    }
};