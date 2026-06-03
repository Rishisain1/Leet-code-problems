class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        vector<pair<int,int>> land;
        vector<pair<int,int>> water;
        int n=landStartTime.size();
        int m=waterStartTime.size();
        for(int i=0;i<n;i++){
            land.push_back({landStartTime[i],landDuration[i]});

        }
        for(int i=0;i<m;i++){
            water.push_back({waterStartTime[i],waterDuration[i]});
        }
        sort(land.begin(),land.end());
        sort(water.begin(),water.end());
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            auto [s,d]=land[i];
            if(s>ans)break;
            int res=s+d;
            for(int j=0;j<m;j++){
                auto [sw,dw]=water[j];
                if(sw>ans)break;
                if(sw>=res){
                    ans=min(ans,sw+dw);
                }
                else{
                    ans=min(ans,res+dw);
                }

            }
        }
        for(int i=0;i<m;i++){
            auto [s,d]=water[i];
            if(s>ans)break;
            int res=s+d;
            for(int j=0;j<n;j++){
                auto [sw,dw]=land[j];
                if(sw>ans)break;
                if(sw>=res){
                    ans=min(ans,sw+dw);
                }
                else{
                    ans=min(ans,res+dw);
                }

            }
        }
        return ans;
    }
};