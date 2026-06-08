class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int pcount=0,n=nums.size();
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(nums[i]==pivot)pcount++;
            else if (nums[i]<pivot){
                ans.push_back(nums[i]);
            }
        }
        for(int i=0;i<pcount;i++){
            ans.push_back(pivot);
        }
        for(int i=0;i<n;i++){
            if(nums[i]>pivot){
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};