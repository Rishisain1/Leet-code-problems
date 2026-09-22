class Solution {
public:

    int solve(vector<int>& nums,int k){
        int i=0,j=0,n=nums.size(),d=0;
        long long count=0;
        vector<int> freq(n+1,0);// we use vector instead of map because the nums[i]is always in the range of 0 ans the nums.size();
        while(j<n){
            if(freq[nums[j]]==0){
                d++;
            }
            freq[nums[j]]++;
            while(d>k){
                freq[nums[i]]--;
                if(freq[nums[i]]==0){
                    d--;
                }
                i++;
            }
            count+=(j-i+1);
            j++;
        }
        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums,k)-solve(nums,k-1);
    }
};