class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans=0;
        int i=0,j=0;
        int n=nums.size();
        while(i<n&&j<n){
            if(nums[j]==1){
                j++;
            }
            else{
                if(k>0){
                    k--;
                    j++;
                }
                else if(nums[i]==0){
                    k++;
                    i++;
                }
                else{
                    i++;
                }
                
            }
            ans=max(ans,j-i);
        }
        return ans;
    }
};