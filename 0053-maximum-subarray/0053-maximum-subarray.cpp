class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            if(sum<0){
                sum=nums[i];
            }
            else{
                sum+=nums[i];
            }
            ans=max(sum,ans);
        }
        return ans;
        
    }
};