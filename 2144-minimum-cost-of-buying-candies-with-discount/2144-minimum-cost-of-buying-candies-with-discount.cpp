class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end());
        int ans=0;
        int n=cost.size()-1;
        
        while(n>=0){
            ans+=cost[n];
            n--;
            if(n>=0){
                ans+=cost[n];
                n--;
            }else{
                break;
            }
            n--;
        }
        return ans;
    }
};