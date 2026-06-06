class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> freq;
        int i=0;
        int ans=0;
        int n=s.length();
        for(int j=0;j<n;j++){
            if(freq[s[j]]){
                while(freq[s[j]]>0){
                    freq[s[i]]--;
                    i++;
                }
            }
            freq[s[j]]++;
            ans=max(ans,j-i+1);
        }
        return ans;
    }
};