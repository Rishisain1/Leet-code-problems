class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;

        vector<vector<pair<int,int>>> g(n,vector<pair<int,int>>(m,{0,0}));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int x=g[i][j].first;
                int y=g[i][j].second;
                if(grid[i][j]=='X'){
                    x++;
                }
                else if(grid[i][j]=='Y'){
                    y++;
                }
                if(i-1>=0&&j-1>=0){                    
                    x+=g[i-1][j].first;
                    x+=g[i][j-1].first;
                    y+=g[i-1][j].second;
                    y+=g[i][j-1].second;
                    g[i][j]={x-g[i-1][j-1].first,y-g[i-1][j-1].second};
                }
                else if(i-1>=0){
                     x+=g[i-1][j].first;
                     y+=g[i-1][j].second;
                     g[i][j]={x,y};
                }
                else if(j-1>=0){
                    x+=g[i][j-1].first;
                     y+=g[i][j-1].second;
                     g[i][j]={x,y};
                }
                else{
                    g[i][j]={x,y};
                }
                if(g[i][j].first==g[i][j].second&&g[i][j].first!=0){
                    count++;
                }
            }
        }
        return count;
    }
};