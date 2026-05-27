class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        // using sorting and bootom up approach 
        int n=arr.size();
        int ans=1;
        vector<int> dp(n,-1);
        vector<pair<int,int>> sorted;
        for(int i=0;i<n;i++){
            sorted.push_back({arr[i],i});
        }
        sort(sorted.begin(),sorted.end());
        for(int i=0;i<n;i++){
            auto [x,j]=sorted[i];
            int l=max(0,j-d);
            int r=min(j+d,n-1);
            int left=1;
            for(int a=j-1;a>=l;a--){
                if(arr[a]<x){
                    left=max(dp[a]+1,left);
                }
                else{
                    break;
                }
            }
            int right=1;
            for(int a=j+1;a<=r;a++){
                if(arr[a]<x){
                    right=max(dp[a]+1,right);
                }
                else{
                    break;
                }
            }
            dp[j]=max(right,left);
            ans=max(dp[j],ans);
        }
        
        return ans;

    }
};