class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> first(26,0);
        vector<int> second(26,0);
        int n1=s.length();
        int n2=t.length();
        if(n1!=n2)return false;
        for(int i=0;i<n1;i++){
            int i1=s[i]-'a';
            int i2=t[i]-'a';
            first[i1]++;
            second[i2]++;
        }
        for(int i=0;i<26;i++){
            if(first[i]!=second[i])return false;
        }
        return true;
    }
};