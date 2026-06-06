class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
        int right=accumulate(nums.begin(),nums.end(),0);
        int left=0;
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            right-=nums[i];
            ans[i]=abs(right-left);
            left+=nums[i];
        }
        return ans;
    }
};