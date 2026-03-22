class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        if(mat==target){
            return true;
        }
        int n=mat.size();
        int a=0,b=0;
        //it is for first rotaion 
        int flag1=1;
        for(int j=0;j<n;j++){
            for(int i=n-1;i>=0;i--){
                if(mat[i][j]!=target[a][b]){
                   flag1=0;
                }
                b=(b+1)%n;
            }
            a+=1;
        }
        if(flag1){
            return true;
        }
        a=0;
        b=0;

        // for second rotation 
        int flag2=1;
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(mat[i][j]!=target[a][b]){
                    flag2=0;
                }
                b=(b+1)%n;
            }
            a++;
        }
        if(flag2){
            return true;
        }

        // for 3rd rotation 
        int flag3=1;
        a=0;
        b=0;
        for(int j=n-1;j>=0;j--){
            for(int i=0;i<n;i++){
                if(mat[i][j]!=target[a][b]){
                    flag3=0;
                }
                b=(b+1)%n;
            }
            a++;
        }
        if(flag3)return true;
        return false;
    }
};