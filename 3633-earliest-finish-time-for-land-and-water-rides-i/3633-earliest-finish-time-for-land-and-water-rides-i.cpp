class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int land=INT_MAX,water=INT_MAX,n=landStartTime.size(),m=waterStartTime.size(),ans=INT_MAX;
        for(int i=0;i<n;i++){
            land=min(land,landStartTime[i]+landDuration[i]);
        }
        //join with water
        for(int i=0;i<m;i++){
            water=min(water,waterStartTime[i]+waterDuration[i]);
            if(waterStartTime[i]<=land){
                ans=min(ans,land+waterDuration[i]);
            }
            else{
                ans=min(ans,waterStartTime[i]+waterDuration[i]);
            }
        }
        // water join to land
        for(int i=0;i<n;i++){
            if(landStartTime[i]<=water){
                ans=min(ans,water+landDuration[i]);
            }
            else{
                ans=min(ans,landStartTime[i]+landDuration[i]);
            }
        }
        return ans;
    }
};