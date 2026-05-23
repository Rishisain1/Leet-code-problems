class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int max1=-1,max2=-1;
        int n=nums.size();
        int ans=-1;
        for(int i=0;i<n;i++){
            if(nums[i]>max2){
                max1=max2;
                max2=nums[i];
                ans=i;
            }
            else{
                max1=max(max1,nums[i]);
            }
        }
        if(max1*2<=max2){
            return ans;
        }
        return -1;
    }
};