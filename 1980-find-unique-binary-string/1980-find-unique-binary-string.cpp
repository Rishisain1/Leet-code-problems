class Solution {
public:
void solve(int i,int n,unordered_map<string,int> &comb,string & ans,string temp){
    if(ans!="")return;
    if(i>=n){
        if(comb[temp]==0){
            ans=temp;
           
        }
         return ;
    }
    solve(i+1,n,comb,ans,temp+'0');
    solve(i+1,n,comb,ans,temp+'1');
}


    string findDifferentBinaryString(vector<string>& nums) {
        int n=nums.size();
        unordered_map<string,int> comb;
        for(auto s:nums){
            comb[s]=1;
        }
        string ans="";
        solve(0,n,comb,ans,"");
        return ans;
    }
};