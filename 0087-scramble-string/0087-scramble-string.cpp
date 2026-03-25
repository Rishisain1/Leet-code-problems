class Solution {
public:

bool solve(string s1,string s2,unordered_map<string,int> &dp){
    if(dp[s1+s2])return (dp[s1+s2])%2;
    if(s1==s2){
        dp[s1+s2]=1;
        return true;}
    int n=s1.length();
    for(int i=0;i<n-1;i++){
        if(solve(s1.substr(0,i+1),s2.substr(n-i-1,i+1),dp) && solve(s1.substr(i+1,n-i-1),s2.substr(0,n-i-1),dp))        {
            dp[s1+s2]=1;
            return true;
        }
        if(solve(s1.substr(0,i+1),s2.substr(0,i+1),dp)&&solve(s1.substr(i+1,n-i-1),s2.substr(i+1,n-i-1),dp)){
            dp[s1+s2]=1;
            return true;}
    }
    dp[s1+s2]=2;
    return false;
}
    bool isScramble(string s1, string s2) {
        unordered_map<string,int> dp;
        return solve(s1,s2,dp);
    }
};