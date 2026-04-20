class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> ch(256,0);
        int n=s.length();
        if(n<=1){
            return n;
        }
        int ans=0;
        int i=0,j=0;
        while(j<n&&i<n){
            int indx=s[j];
            if(ch[indx]){
                int x=s[i];
                ch[x]--;
                i++;
            }
            else{
                j++;
                ch[indx]++;
            }
            ans=max(ans,j-i);
        }
        return ans;
    }
};