class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans=INT_MAX;
        int i=0,j=0;
        int n=nums.size();
        int sum=0;
        while(j<n){
            sum+=nums[j];
            
            while(i<n&&sum>=target){
                if(sum>=target){
                    ans=min(ans,j-i+1);
                }
                sum-=nums[i];
                i++;
            }
            j++;
        }
        return (ans==INT_MAX)?0:ans;
    }
};