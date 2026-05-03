class Solution {
public:
    bool rotateString(string s, string goal) {
        int n=s.length();
        if(s==goal)return true;
        for(int i=0;i<n;i++){
             s=s+s[0];
            s=s.substr(1);
            if(s==goal){
                return true;
            }
        } 
        return false;     
    }
};