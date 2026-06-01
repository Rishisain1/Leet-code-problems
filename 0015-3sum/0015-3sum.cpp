class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        set<vector<int>> unique;
        for(int i=0;i<n-2;i++){
            int left=i+1;
            int right=n-1;
            while(left<right){
                if(nums[i]+nums[left]+nums[right]==0){
                    unique.insert({nums[i],nums[left],nums[right]});
                    left++;
                    right--;
                }
                else if(nums[left]+nums[right]>-nums[i]){
                    right--;
                }
                else {
                    left++;
                }
            }
        }
        vector<vector<int>> ans;
        for(auto a:unique){
            ans.push_back(a);
        }
        return ans;
    }
};