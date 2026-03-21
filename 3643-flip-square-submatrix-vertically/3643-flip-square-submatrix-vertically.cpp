class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int n = grid.size();
        int m = grid[0].size();

        if (x < 0 || y < 0 || x + k > n || y + k > m) return {};

        for (int col = y; col < y + k; col++) {
            for (int i = 0; i < k / 2; i++) {
                swap(grid[x + i][col], grid[x + k - 1 - i][col]);
            }
        }

        return grid;
    }
};