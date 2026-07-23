class Solution {
public:

    int atmost(vector<int>&nums,int k){
        int i=0;
        int j=0;
        int n=nums.size();
        unordered_map<int,int> freq;
        int count=0;
        while(j<n){
            freq[nums[j]]++;
            while(freq.size()>k){
                freq[nums[i]]--;
                if(freq[nums[i]]==0){
                    freq.erase(nums[i]);
                }
                i++;
            }
            // this makes the condition invalid because we count at most k but it create inconsistency for result so just use 
            // if(freq.size()==k){
            //     count+=(j-i+1);
            // }
            count+=j-i+1;
            j++;
        }
        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return  atmost(nums,k) - atmost(nums,k-1);
    }
};