class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length()>s2.length())return false;
        vector<int> freq1(26,0);
        vector<int> freq2(26,0);
        for(auto ch:s1){
            int x=ch-'a';
            freq1[x]++;
        }
        int i=0,j=0,n=s1.length();
        for(j=0;j<n;j++){// keep in mind we not suppose to redefine the j
            int x=s2[j]-'a';
            freq2[x]++;
        }
        if(freq1==freq2)return true;
        int n2=s2.length();
        while(j<n2){
            int x=s2[i]-'a';
            freq2[x]--;
            x=s2[j]-'a';
            freq2[x]++;
            if(freq1==freq2)return true;
            i++;
            j++;

        }
        return false;
    }
};