class Solution {
public:

    int sum(int n){
        int num=0;
        while(n>0){
           num+=n%10;
           n=n/10;
        }
        return num;
    }

    int minElement(vector<int>& nums) {
        int mini=INT_MAX;
        for(auto i:nums){
            mini=min(mini,sum(i));
        }
        return mini;
    }
};