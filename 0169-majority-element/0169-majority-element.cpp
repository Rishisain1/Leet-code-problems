class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> freq;
        for(int i:nums){
            freq[i]++;
        }
        for(auto [i,f]:freq){
            if(f>(n/2)){
                return i;
            }
        }
        return -1;
    }
};