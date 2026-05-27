class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left=0;
        int n=nums.size();
        if(n==0)return {-1,-1};
        int right=n-1;
        vector<int>ans(2,-1);

        while(left<right){
            int mid=(right+left)/2;
            if(nums[mid]==target){
                right=mid;
            }
            else if(nums[mid]<target){
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        if(right>=0&&nums[right]==target){
            ans[0]=right;
        }
        else{
            return {-1,-1};
        }
        right =n-1;
        left=0;
        while(left<right){
            int mid=(right+left)/2;
            if(nums[mid]==target){
                left=mid;
            }
            else if(nums[mid]>target){
                right=mid-1;
            }
            else{
                left=mid+1;
            }
            if(left+1==right){
                break;
            }
        }
        if(nums[right]==target){
            ans[1]=right;
        }
        else{

            ans[1]=left;
        }
        return ans;

    }
};