class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n-2;i++){
            if(i-1>=0&&nums[i]==nums[i-1])continue;
            int target =-nums[i];
            int j=i+1,k=n-1;
            while(j<k){
                if(nums[j]+nums[k]==target){
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                    while(j<n&&nums[j]==nums[j-1]){
                    j++;
                }
                }
                else if(nums[j]+nums[k]>target){
                    k--;
                }
                else{
                    j++;
                    while(j<n&&nums[j]==nums[j-1]){
                    j++;
                }
                }
                
            }
        }
        return ans;
    }
};