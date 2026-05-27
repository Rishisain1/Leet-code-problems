class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char,int> occ;
        int n=word.length();
        for(int i=0;i<n;i++){
            if(word[i]>='a'&&word[i]<='z'){
                occ[word[i]]=i;
            }
            else if(!occ.count(word[i])){
                occ[word[i]]=i;
            }
        }
        int count=0;
        for(char ch='a';ch<='z';ch++){
            char CH=ch-'a'+'A';
            if(occ.count(ch)&&occ.count(CH)&&occ[ch]<occ[CH]){
                count++;
            }
        }
        return count;
    }
};