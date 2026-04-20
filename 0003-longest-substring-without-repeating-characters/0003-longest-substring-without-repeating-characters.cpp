class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> freq;
        int n=s.length();
        if(n<=1){
            return n;
        }
        int ans=0;
        int i=0,j=0;
        while(j<n&&i<n){
           
            if(freq[s[j]]!=0){
                freq[s[i]]--;
                i++;
            }
            else{
                freq[s[j]]++;
                j++;
                
            }
            ans=max(ans,j-i);
        }
        return ans;
    }
};