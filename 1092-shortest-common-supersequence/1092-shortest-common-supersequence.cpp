class Solution {
public:

// void solve(string &str1, string &str2,int i,int j,string temp,string &ans){
//     if(i>=str1.length()){
//         while(j<str2.size()){
//             temp+=str2[j];
//             j++;
//         }
//         if(ans!=""){
//             if(ans.size()>temp.size()){
//                 ans=temp;
//             }
//         }else{
//             ans=temp;
//         }
//         return ;
//     }
//     if(j>=str2.length()){
//         while(i<str1.size()){
//             temp+=str1[i];
//             i++;
//         }
//         if(ans!=""){
//             if(ans.size()>temp.size()){
//                 ans=temp;
//             }
//         }else{
//             ans=temp;
//         }
//         return ;
//     }

//     if(str1[i]==str2[j]){
//         solve(str1,str2,i+1,j+1,temp+str1[i],ans);
//     }
//     else{
//         solve(str1,str2,i+1,j,temp+str1[i],ans);
//         solve(str1,str2,i,j+1,temp+str2[j],ans);
//     }
// }


    string shortestCommonSupersequence(string str1, string str2) {
        string ans="";
        // solve(str1,str2,0,0,"",ans);
        int n=str1.size();
        int m=str2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(str1[i-1]==str2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        int i=n;
        int j=m;
        while(i>0&&j>0){
            if(str1[i-1]==str2[j-1]){
                ans+=str1[i-1];
                i--;j--;
            }
            else{
                if(dp[i-1][j] > dp[i][j-1]){
                    ans+=str1[i-1];
                    i--;
                }
                else {
                    ans+=str2[j-1];
                    j--;
                }
            }
        }
        while(i>0){
            ans+=str1[i-1];
            i--;
        }
        while(j>0){
            ans+=str2[j-1];
            j--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};