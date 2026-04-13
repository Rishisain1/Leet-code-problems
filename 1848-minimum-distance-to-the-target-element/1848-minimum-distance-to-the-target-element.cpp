class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int ans=INT_MAX;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(target==nums[i]){
                ans=min(ans,abs(i-start));
            }
        }
        return ans;
    }
};