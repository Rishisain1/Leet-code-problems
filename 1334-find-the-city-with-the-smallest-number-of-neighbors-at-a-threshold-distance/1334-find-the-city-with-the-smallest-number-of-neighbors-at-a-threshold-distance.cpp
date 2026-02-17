class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n,vector<int>(n,distanceThreshold+1));
        for(auto edge:edges){
           int u =edge[0];
            int v=edge[1];
            int w=edge[2];
            if(w>distanceThreshold)continue;
            dist[u][v]=w;
            dist[v][u]=w;
        }
        int ans=0;
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(i==j)continue;
                    if(dist[i][k]<=distanceThreshold&&dist[k][j]<=distanceThreshold){
                        dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                    }
                }
            }
        }
        int count=INT_MAX;
        for(int i=0;i<n;i++){
            int temp=0;
            for(int j=0;j<n;j++){
                if(dist[i][j]<=distanceThreshold)temp++;
            }
            if(count>=temp){
                ans=i;
                count=temp;
            }
        }
        return ans;
    }
};