class Solution {
public:

int atmost(vector<int>& nums,int k){
    int i=0,j=0,co=0;
    int n=nums.size();
    int count=0;
    while(j<n){
        if(nums[j]%2==1){
            co++;
        }
        while(co>k){
            if(nums[i]%2==1){
                co--;
            }
            i++;
        }
        count+=(j-i+1);
        j++;
    }
    return count;
}

    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmost(nums,k)-atmost(nums,k-1);
    }
};