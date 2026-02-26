class Solution {
public:
unordered_map<string,int> palindrome;

bool check(string s){
    int n=s.length();
    if(n<=1)return true;
    if(palindrome[s]){
        if(palindrome[s]==1){
            return false;
        }else{
            return true;
        }
    }
    palindrome[s]=1;
    
    
    for(int i=0;i<n/2;i++){
        if(s[i]!=s[n-i-1])
        return false;
    }
    palindrome[s]=2;
    return true;
}

int solve(string &s,int i,string &temp){
    if(i>=s.length()){
        if(check(temp))return temp.length();
        return 0;
    }
    
    int u=solve(s,i+1,temp);
    temp+=s[i];
    int t=solve(s,i+1,temp);
   
    temp.pop_back();
    return max(u,t);
}

    int longestPalindromeSubseq(string s) {
        // string temp="";
        // return solve(s,0,temp);
        string s2=s;
        int n=s.size();
        reverse(s2.begin(),s2.end());
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==s2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][n];
    }
};