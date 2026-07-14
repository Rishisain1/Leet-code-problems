class Solution {
public:

int maxf(vector<int> &freq){
    int ans=0;
    for(auto &i:freq){
        ans=max(ans,i);
    }
    return ans;
}

    int characterReplacement(string s, int k) {
        vector<int> freq(26,0);
        int ans=0;
        int i=0,j=0;
        int n=s.length();
        while(j<n){
            int ch=s[j]-'A';
            freq[ch]++;
            int maxfreq=maxf(freq);
            while(j-i+1-maxfreq>k){
                int x=s[i]-'A';
                freq[x]--;
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};