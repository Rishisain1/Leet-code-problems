class Solution {
public:

int solve(vector<int> & arr,int i,int k,vector<int>&dp){
    int n=arr.size();
    if(i>=n){
        return 0;
    }
    if(dp[i]!=-1)return dp[i];
    int ans=INT_MIN;
    int maxelement=INT_MIN;
    for(int a=i;a<min(n,i+k);a++){
        maxelement=max(arr[a],maxelement);
        ans=max(ans,maxelement*(a-i+1)+solve(arr,a+1,k,dp));
    }
    return dp[i]=ans;
}

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
            int n=arr.size();

        vector<int> dp(n,-1);
        return solve(arr,0,k,dp);
    }
};