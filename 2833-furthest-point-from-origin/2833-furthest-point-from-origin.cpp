class Solution {
public:
int ans=0;

void solve(string & moves,int i,int temp,vector<vector<int>>& dp){
    int n=moves.size();
    if(i>=n){
        ans=max(ans,abs(temp));
        return;
    }
    if(dp[i][temp+n]!=-1)return ;
    dp[i][temp+n]=1;
    if(moves[i]=='_'){
        solve(moves,i+1,temp+1,dp);
        solve(moves,i+1,temp-1,dp);
    }
    else{
        if(moves[i]=='L'){
           solve(moves,i+1,temp-1,dp);
        }
        else{
            solve(moves,i+1,temp+1,dp);
        }
    }
}

    int furthestDistanceFromOrigin(string moves) {
        int n= moves.size();
        vector<vector<int>> dp(n,vector<int>((n+1)*2,-1));
        solve(moves,0,0,dp);
        return ans;
    }
};