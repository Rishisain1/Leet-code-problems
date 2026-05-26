class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int k) {
        unordered_map<int,int> p;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(p.count(k-nums[i])){
                return {p[k-nums[i]],i};
            }
            p[nums[i]]=i;
        }
        return {};
    }
};