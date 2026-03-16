#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        set<int, greater<int>> distinct;
        
        // Add all single cells (size 0 rhombus)
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                distinct.insert(grid[i][j]);
        
        // Try all possible rhombus centers and sizes
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // size k means k steps from center to corner
                for (int k = 1; i-k >= 0 && i+k < m && j-k >= 0 && j+k < n; k++) {
                    int sum = 0;
                    
                    // Top to right corner
                    for (int d = 0; d < k; d++)
                        sum += grid[i-k+d][j+d];
                    
                    // Right to bottom corner
                    for (int d = 0; d < k; d++)
                        sum += grid[i+d][j+k-d];
                    
                    // Bottom to left corner
                    for (int d = 0; d < k; d++)
                        sum += grid[i+k-d][j-d];
                    
                    // Left to top corner
                    for (int d = 0; d < k; d++)
                        sum += grid[i-d][j-k+d];
                    
                    distinct.insert(sum);
                }
            }
        }
        
        vector<int> result;
        for (int val : distinct) {
            result.push_back(val);
            if (result.size() == 3) break;
        }
        return result;
    }
};