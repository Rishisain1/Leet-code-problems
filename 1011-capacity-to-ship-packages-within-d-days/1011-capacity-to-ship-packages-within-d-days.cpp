class Solution {
public:

    int countDays(vector<int>& weights,int capacity){
        int weight=0,days=0;
        for(int i=0;i<weights.size();i++){
            if(weight+weights[i]<=capacity){
                weight+=weights[i];
            }
            else{
                days++;
                weight =weights[i];
            }
        }
        return days+1;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int left=0;
        int right =0;
        for(auto i:weights){
            left=max(i,left);
            right +=i;
        }
        int ans=0;
        while(left<=right ){
            int mid=(left+right)/2;
            int day=countDays(weights,mid);
            if(day<=days){
                ans=mid;
                right=mid-1;
            }
            
            else {
               left=mid+1;
            }
            
           
        }
        return ans;
    }
};