class Solution {
public:
bool check(string& s){
    
    int n=s.length();
    if(n==1)return true;
    for(int a=0;a<(n)/2;a++){
        if(s[a]!=s[n-a-1])
        return false;
    }
    return true;
}
void  solve(string &s,int i,int j,vector<vector<string>> &ans,vector<string> &temp){
    if(i>j){
       return;
    }
    
    for(int k=i;k<=j;k++){   
        string str=s.substr(i,k-i+1);
        
        if(check(str)){
            temp.push_back(str);
           solve(s,k+1,j,ans,temp);
           if(k==j){
            ans.push_back(temp);
           }
           temp.pop_back();
            
        }
    }  
}

    vector<vector<string>> partition(string s) {
        int n=s.length();
        vector<vector<string>> ans;
        vector<string> temp;
         solve(s,0,n-1,ans,temp);
        return ans;
    }
};