class Solution {
public:
    int solve(vector<int>& nums, int k) {
        int count = 0;
        unordered_map<int, int> freq;
        int i = 0, j = 0, n = nums.size();
        // we have to update count in every single step not only in the case of freqsize()==k
        while (j < n) {
            freq[nums[j]]++;

            while (freq.size() > k) {
                freq[nums[i]]--;
                if (freq[nums[i]] == 0) {
                    freq.erase(nums[i]);
                }

                i++;
            }
            count += (j - i + 1);

            j++;
        }
        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums, k) - solve(nums, k - 1);
    }
};