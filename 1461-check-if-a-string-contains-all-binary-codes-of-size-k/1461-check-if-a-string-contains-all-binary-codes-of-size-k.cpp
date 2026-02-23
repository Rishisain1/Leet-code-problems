class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(k>s.length()){
            return false;
        }
        unordered_set<string> substr;
        string window="";
        for(int i=0;i<k;i++){
            window+=string(1,s[i]);
        }
        substr.insert(window);
        int n=s.length();
        for(int i=k;i<n;i++){
            window.erase(window.begin());
            window+=string(1,s[i]);
            substr.insert(window);
        }
        if(substr.size()==pow(2,k)){
            return true;
        }
        return false;
    }
};