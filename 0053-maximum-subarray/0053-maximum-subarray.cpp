class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res=nums[0];
        int maxending=nums[0];
        int n=nums.size();
        for(int i=1;i<n;i++){
            maxending=max(nums[i],maxending+nums[i]);
            res=max(res,maxending);
        }
        return res;
    }
};