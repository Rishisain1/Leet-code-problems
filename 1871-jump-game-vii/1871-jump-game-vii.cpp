class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n=s.length();
        vector<int> dp(n,0);
        int rc=0;
        dp[0]=1;
        for(int i=0;i<n;i++){
            if(i-minJump>=0&&dp[i-minJump]){
                rc++;
            }
            if(i-maxJump-1>=0&&dp[i-maxJump-1]){
                rc--;
            }
            if(s[i]=='0'&&rc>0){
                dp[i]=1;
            }
        }
        return dp[n-1];
    }
};