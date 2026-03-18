class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int count=0;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int sum=grid[i][j];
                if(i-1>=0&&j-1>=0){
                    sum-=grid[i-1][j-1];
                    sum+=grid[i][j-1];
                    sum+=grid[i-1][j];
                }
                else {
                    if(j-1>=0){
                        sum+=grid[i][j-1];
                    }
                    if(i-1>=0){
                        sum+=grid[i-1][j];
                    }
                }
                // neglect repeated part
                
                grid[i][j]=sum;
                if(sum<=k){
                    count++;
                }
                else{
                    break;
                }
            }
        }
        return count;
    }
};