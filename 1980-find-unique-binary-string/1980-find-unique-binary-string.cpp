class Solution {
public:

void solve(int i,int n,unordered_map<string,int> &comb,string &temp){
    if(i>=n){
        comb[temp]=-1;
        return ;
    }
    string s=temp;
    temp+='0';
    solve(i+1,n,comb,temp);
    temp=s;
    temp+='1';
    solve(i+1,n,comb,temp);
    temp=s;
}

    string findDifferentBinaryString(vector<string>& nums) {
        int n=nums.size();
        unordered_map<string,int> comb;
        string temp="";
        solve(0,n,comb,temp);
        for(auto s:nums){
            comb[s]=1;
        }
        for(auto [s,f]:comb){
            if(f==-1){
                return s;
            }
        }
        return "";
    }
};