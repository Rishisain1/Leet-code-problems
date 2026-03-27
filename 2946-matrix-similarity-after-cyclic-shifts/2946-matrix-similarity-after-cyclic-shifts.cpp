class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n=mat.size();
        int m=mat[0].size();
        
        k=k%m;        
            for(int i=0;i<n;i++){
                int j=k;
                vector<int> temp;
                vector<int> ans=mat[i];
                for(;j<m;j++){
                    temp.push_back(mat[i][j]);
                }
                for(int x=0;x<k;x++){
                    temp.push_back(mat[i][x]);
                }
                mat[i]=temp;
                if(mat[i]!=ans){
                    return false;
                }
            }
        
    return true;
    }
};