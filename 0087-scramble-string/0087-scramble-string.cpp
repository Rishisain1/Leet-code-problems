class Solution {
public:

bool solve(string s1,string s2,unordered_map<string,int> &dp){
    string key=s1+'#'+s2;//previous may s=a and s2 =bc & s1 =sb and s2 =c so s1+s2 is same for taht case that's why we ahve to add a seperator
    if(dp[key])return (dp[key])%2;
    if(s1==s2){
        dp[key]=1;
        return true;}
        string a=s1,b=s2;
        //important check becuase is scrambling possible or not 
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        if(a!=b){
            dp[key]=2;
        return false;
        }
    int n=s1.length();
    for(int i=0;i<n-1;i++){
        if(solve(s1.substr(0,i+1),s2.substr(n-i-1),dp) && solve(s1.substr(i+1),s2.substr(0,n-i-1),dp))        {
            dp[key]=1;
            return true;
        }
        if(solve(s1.substr(0,i+1),s2.substr(0,i+1),dp)&&solve(s1.substr(i+1),s2.substr(i+1),dp)){
            dp[key]=1;
            return true;}
    }
    dp[key]=2;
    return false;
}
    bool isScramble(string s1, string s2) {
        unordered_map<string,int> dp;
        return solve(s1,s2,dp);
    }
};