class Solution {
public:

    void solve(int n,int cl,int cr,string temp,vector<string> &ans){
        if(cl==n&&cr==n){
           
            ans.push_back(temp);
            return ;
        }
        if(cl<n){
            solve(n,cl+1,cr,temp+'(',ans);
        }
        if(cl-cr>0){// important update becuase firstly we have cr<n but this is more optimised aprach 
            solve(n,cl,cr+1,temp+')',ans);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(n,0,0,"",ans);
        return ans;
    }
};