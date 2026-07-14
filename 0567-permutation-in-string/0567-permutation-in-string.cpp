class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size())return false;
        vector<int> freq1(26,0);
        vector<int> freq2(26,0);
        for(auto ch:s1){
            int i=ch-'a';
            freq1[i]++;
        }
        int n=s1.length();
        int j=0;
        for(;j<n;j++){
            int ch=s2[j]-'a';
            freq2[ch]++;
        }
        if(freq1==freq2){
            return true;
        }
        int n2=s2.size();
        int i=0;
        while(j<n2){
            int ch=s2[i]-'a';
            freq2[ch]--;
            i++;
            ch=s2[j]-'a';
            freq2[ch]++;
            j++;
            if(freq1==freq2){
                return true;
            }
        }
        return false;
    }
};