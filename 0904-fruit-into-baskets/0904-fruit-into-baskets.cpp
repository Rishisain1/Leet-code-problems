class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> freq;
        int ans=0;
        int i=0,j=0;
        int n=fruits.size();
        int count=0;
        while(j<n){
            freq[fruits[j]]++;
            while(i<n&&freq.size()>2){
                freq[fruits[i]]--;
                if(freq[fruits[i]]==0){
                    freq.erase(fruits[i]);
                }
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};