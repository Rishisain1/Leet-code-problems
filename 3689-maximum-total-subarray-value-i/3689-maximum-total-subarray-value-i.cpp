class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int mine=INT_MAX,maxe=INT_MIN;
        for(int a:nums){
            mine=min(mine,a);
            maxe=max(maxe,a);
        }
        return (1LL*(maxe-mine)*k);

    }
};