class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int mod = 1e9 + 7;
        for (auto q : queries) {
            int s = q[0], e = q[1], k = q[2], v = q[3];
            for (int i = s; i <= e; i = i + k) {
                nums[i] = (1LL * nums[i] * v) % mod;
            }
        }
        int ans = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            ans ^= nums[i];
        }
        return ans;
    }
};