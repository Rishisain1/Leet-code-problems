class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<int> rows(n,0);
        vector<int> cols(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]){
                    rows[i]++;
                    cols[j]++;
                }
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]){
                    if(rows[i]-1)continue;
                    if(cols[j]-1==0)count++;
                }
            }
        }
        return count;
    }
};