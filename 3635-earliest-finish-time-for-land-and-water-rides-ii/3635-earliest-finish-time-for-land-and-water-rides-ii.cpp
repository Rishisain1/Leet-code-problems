class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int land=INT_MAX;
        int ans=INT_MAX;
        int n=landStartTime.size();
        for(int i=0;i<n;i++){
            land=min(land,landStartTime[i]+landDuration[i]);
        }
        int water=INT_MAX;
        int m=waterStartTime.size();
        for(int i=0;i<m;i++){
            water=min(water,waterStartTime[i]+waterDuration[i]);
            if(land>=waterStartTime[i]){
                ans=min(ans,land+waterDuration[i]);
            }
            else{
                ans=min(ans,waterStartTime[i]+waterDuration[i]);
            }
        }
        for(int i=0;i<n;i++){
            if(water>=landStartTime[i]){
                ans=min(ans,landDuration[i]+water);
            }
            else{
                ans=min(ans,landStartTime[i]+landDuration[i]);
            }
        }
        return ans;
    }
};