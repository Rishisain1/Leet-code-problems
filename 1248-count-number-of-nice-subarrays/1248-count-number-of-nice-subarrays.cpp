class Solution {
public:

    int solve(vector<int>&nums,int k){
        int n=nums.size(),i=0,j=0,count=0,f=0;
        while(j<n){
            if(nums[j]%2){
                f++;
            }
            while(f>k){
                if(nums[i]%2){
                    f--;
                }
                i++;
            }
            count+=(j-i+1);
            j++;
        }
        return count;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums,k)-solve(nums,k-1);
    }
};