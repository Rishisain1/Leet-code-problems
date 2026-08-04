class Solution {
public:

bool solve(int p1,int p2,int left,int right ,vector<int> &nums){
    if(left>right){
        if(p1>=p2)return true;
        return false;
    }
    if(left==right){
        return solve(p1+nums[left],p2,left+1,right,nums);
    }
    else{
        bool l=false,r=false;
        
            l=solve(p1+nums[left],p2+nums[left+1],left+2,right,nums)&&
        
        solve(p1+nums[left],p2+nums[right],left+1,right-1,nums);
    
       
            r=solve(p1+nums[right],p2+nums[left],left+1,right-1,nums)&&
        solve(p1+nums[right],p2+nums[right-1],left,right-2,nums);
       
        return l||r;
    }
}

    bool predictTheWinner(vector<int>& nums) {
        return solve(0,0,0,nums.size()-1,nums);
    }
};