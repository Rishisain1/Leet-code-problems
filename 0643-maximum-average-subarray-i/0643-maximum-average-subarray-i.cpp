class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum=0;
        
        for(int i=0;i<k;i++){
            sum+=(double(nums[i]));
        }
        
        double ans=sum/double( k);
       
        int i=0,n=nums.size();
        for(int j=k;j<n;j++){
            sum-=((double)nums[i++]);
            sum+=((double)nums[j]);
            
            ans=max(ans,sum/double(k));
        }
        return ans;
    }
};