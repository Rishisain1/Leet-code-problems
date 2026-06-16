class Solution {
public:

void duplicateapp(stack<char> &stk){
    stack<char> temp;
    stack<char> temp2;
    while(!stk.empty()){
        temp.push(stk.top());
        stk.pop();
    }
    temp2=temp;
    while(!temp.empty()){
        stk.push(temp.top());
        temp.pop();
    }
    while(!temp2.empty()){
        stk.push(temp2.top());
        temp2.pop();
    }

}

void reversecurr(stack<char> &stk){
    string s="";
    while(!stk.empty()){
        s+=stk.top();
        stk.pop();

    }
    for(auto ch:s){
        stk.push(ch);
    }
}

    string processStr(string s) {
        stack<char> stk;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]=='*'){
                if(stk.size())stk.pop();
            }
            else if(s[i]=='#'){
                duplicateapp(stk);
            }
            else if(s[i]=='%'){
                reversecurr(stk);
            }
            else{
                stk.push(s[i]);
            }
        }
        string result="";
        while(!stk.empty()){
            result+=stk.top();
            stk.pop();
        }
        reverse(result.begin(),result.end());
        return result;
    }
};