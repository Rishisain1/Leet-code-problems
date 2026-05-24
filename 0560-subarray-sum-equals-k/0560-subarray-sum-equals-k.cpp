class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> s;
        int sum=0;
        int count=0;
        int n=nums.size();
        s[0]++;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(s[sum-k]!=0){
                count+=s[sum-k];
            }
            s[sum]++;
           
        }
        return count;
    }
};
