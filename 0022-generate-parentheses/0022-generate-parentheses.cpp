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

    void solve(int i,int n,string temp,vector<string> &ans){
        if(i==n){
            if(validate(temp)){
                ans.push_back(temp);
            }
            return ;
        }
        solve(i+1,n,temp+'(',ans);
        solve(i+1,n,temp+')',ans);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(0,n*2,"",ans);
        return ans;
    }
};