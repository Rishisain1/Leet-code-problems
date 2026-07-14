class Solution {
public:

int maxf(unordered_map<char,int> &freq){
    int ans=0;
    for(auto &[ch,i]:freq){
        ans=max(ans,i);
    }
    return ans;
}

    int characterReplacement(string s, int k) {
        unordered_map<char,int> freq;
        int ans=0;
        int i=0,j=0;
        int n=s.length();
        while(j<n){
            freq[s[j]]++;
            int maxfreq=maxf(freq);
            while(j-i+1-maxfreq>k){
                freq[s[i]]--;
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};