class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       unordered_map<int,vector<int>> pos;
       int n=nums.size();
       for(int i=0;i<n;i++){
            pos[nums[i]].push_back(i);
        }
        for(int i=0;i<n;i++){
            if(pos.count(target-nums[i])){
                for(auto j:pos[target-nums[i]]){
                    if(j!=i){
                        return {i,j};
                    }
                }
            }
        }
        return {-1,-1};
    }
};