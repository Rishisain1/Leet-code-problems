class Solution {
public:
    bool check(vector<int>& nums) {
        int a;
        int n=nums.size();
        for(int i=0;i<n;i++){
            bool ans=true;
           
            a=nums[i];
            int j=i+1;
            while(j<n){
                if(a>nums[j]){
                    ans=false;
                    break;
                }
                a=nums[j]; 
                j++;           
            }
            if(ans){
                for(int k=0;k<i;k++){
                    if(a>nums[k]){
                        ans=false;
                        break;
                    }
                    a=nums[k];
                }
            }
            if(ans){
                return true;
            }
        }
        return false;
    }
};