class Solution {
public:

    bool validate(string &s){
        stack<char>stack;
        for(char c:s){
            if(c=='('){
                stack.push(c);
            }
            else{
                if(stack.empty()){
                    return false;
                }
                else{
                    stack.pop();
                }
            }
        }
        if(stack.empty())
        return true;
        return false;
    }

    void solve(int n,int cl,int cr,string temp,vector<string> &ans){
        if(cl==n&&cr==n){
            if(validate(temp))
            ans.push_back(temp);
            return ;
        }
        if(cl<n){
            solve(n,cl+1,cr,temp+'(',ans);
        }
        if(cr<n){
            solve(n,cl,cr+1,temp+')',ans);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(n,0,0,"",ans);
        return ans;
    }
};