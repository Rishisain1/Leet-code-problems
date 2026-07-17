class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        
        int maxp=INT_MIN;
        
        int ans=INT_MIN;
        for(int i=n-1;i>=0;i--){
            maxp=max(prices[i],maxp);
            ans=max(maxp-prices[i],ans);
        }
        return ans;
    }
};