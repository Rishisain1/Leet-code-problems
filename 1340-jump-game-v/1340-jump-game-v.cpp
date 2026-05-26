class Solution {
public:

int solve(vector<int>& arr, int d,int i,vector<int>& dp){
    int n=arr.size();
    int x=max(0,i-d);
    int y=min(n-1,i+d);
    int left=1;
    for(int j=i-1;j>=x;j--){
        if(arr[i]<=arr[j])break;
        if(dp[j]==-1){
            left=max(solve(arr,d,j,dp)+1,left);
        }
        else{
            left=max(dp[j]+1,left);
        }
    }
    int right=1;
    for(int j=i+1;j<=y;j++){
        if(arr[i]<=arr[j])break;
        if(dp[j]==-1){
            right=max(solve(arr,d,j,dp)+1,right);
        }
        else{
            right=max(right,dp[j]+1);
        }
    }
    return dp[i]=max(left,right);

}

    int maxJumps(vector<int>& arr, int d) {
        int ans=1;
        int n=arr.size();
        vector<int> dp(n,-1);
        for(int i=0;i<n;i++){
            int count=1;
            if(dp[i]==-1){
                count=solve(arr,d,i,dp);
            }
            else{
                count=dp[i];
            }
            ans=max(ans,count);       
        }
        for(int i:dp){
        cout<<i<<" ";
        }
        return ans;
    }
};