class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        for(int i=0;i<numRows;i++){
            vector<int> temp;
            for(int j=0;j<=i;j++){
                int sum=0;
                if(i-1>=0&&j<=i-1){
                    sum+=result[i-1][j];
                }
                if(i-1>=0&&j-1>=0){
                    sum+=result[i-1][j-1];
                }
                if(sum==0){
                    temp.push_back(1);
                }
                else{
                    temp.push_back(sum);
                }
            }
            result.push_back(temp);
        }
        return result;
    }
};