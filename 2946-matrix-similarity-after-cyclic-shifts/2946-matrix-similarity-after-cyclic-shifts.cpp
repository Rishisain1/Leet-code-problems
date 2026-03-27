class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n=mat.size();
        int m=mat[0].size();
        if(m==1){
            return true;
        }
        vector<vector<int>> ans=mat;
        k=k%m;
        
            for(int i=0;i<n;i++){
                int j=k;
                vector<int> temp;
                for(;j<m;j++){
                    temp.push_back(mat[i][j]);
                }
                for(int x=0;x<k;x++){
                    temp.push_back(mat[i][x]);
                }
                mat[i]=temp;
                if(mat[i]!=ans[i]){
                    return false;
                }
            }
        
    return true;
    }
};