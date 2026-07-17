class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int> fm(n);
        int maxp=INT_MIN;
        for(int i=n-1;i>=0;i--){
            maxp=max(maxp,prices[i]);
            fm[i]=maxp;
        }
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            ans=max(ans,fm[i]-prices[i]);
        }
        return ans;
    }
};