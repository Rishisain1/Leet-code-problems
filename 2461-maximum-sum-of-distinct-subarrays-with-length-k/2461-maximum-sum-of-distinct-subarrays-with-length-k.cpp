class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        int n=nums.size();
        long long sum=0;
        long long ans=0;
        for(int i=0;i<k;i++){
            sum+=nums[i];
            freq[nums[i]]++;
        }
        if(freq.size()==k){
            ans=max(ans,sum);
        }
        int j=0;
        for(int i=k;i<n;i++){
            sum-=nums[j];
            freq[nums[j]]--;
            if(freq[nums[j]]==0){
                freq.erase(nums[j]);
            }
            j++;
            cout<<freq.size()<<" ";
            sum+=nums[i];
            freq[nums[i]]++;
            if(freq.size()==k){
                ans=max(ans,sum);
            }
        }
        return ans;
    }
};