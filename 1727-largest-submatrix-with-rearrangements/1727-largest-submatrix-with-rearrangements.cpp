class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        // step1:- build heights
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1) {
                    mat[i][j] += mat[i-1][j];
                }
            }
        }

        int ans = 0;

        // step2:- process each row
        for (int i = 0; i < m; i++) {
            vector<int> row = mat[i];
            sort(row.begin(), row.end(), greater<int>());

            for (int j = 0; j < n; j++) {
                ans = max(ans, row[j] * (j+1));
            }
        }
        return ans;
        
    }
};