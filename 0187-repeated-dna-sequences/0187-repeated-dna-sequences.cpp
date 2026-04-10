class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n=s.length();
        if(n<10){
            return {};
        }
        vector<string> ans;
        unordered_map<string,int> freq;
        for(int i=0;i<=n-10;i++){
            string str=s.substr( i,10);
           freq[str]++;
        }
        for(auto [str,f]:freq){
            if(f>1){
                ans.push_back(str);
            }
        }
        return ans;
    }
};