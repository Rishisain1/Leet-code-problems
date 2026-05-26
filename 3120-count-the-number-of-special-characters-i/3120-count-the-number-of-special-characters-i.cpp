class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char,int> l;
        unordered_map<char,int> u;
        int count=0;
        for(char ch:word){
            if(ch>='a'&&ch<='z'){
                l[ch]=1;
            }
            else if(ch>='A'&&ch<='Z'){
                u[ch]=1;
            }
        }
        for(char ch='a';ch<='z';ch++){
            char upp=ch-'a'+'A';
            if(l[ch]&&u[upp]){
                count++;
            }
        }
return count;
    }
};