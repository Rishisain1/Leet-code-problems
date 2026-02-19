class DisjointSet {

public:
    vector<int> parent;
    vector<int> sizes;
    DisjointSet(int n) {
        parent.resize(n);
        sizes.resize(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findpar(int node) {
        if (parent[node] == node) {
            return node;
        }
        return parent[node] = findpar(parent[node]);
    }
    void unionBySize(int u, int v) {
        int ultp_u = findpar(u);
        int ultp_v = findpar(v);
        if (ultp_u == ultp_v)
            return;
        if (sizes[ultp_u] >= sizes[ultp_v]) {
            parent[ultp_v] = ultp_u;
            sizes[ultp_u] += sizes[ultp_v];
        } else {
            parent[ultp_u] = ultp_v;
            sizes[ultp_v] += sizes[ultp_u];
        }
    }
};

int area(int i, int j, int n, DisjointSet &ds,vector<vector<int>>& grid) {
   
    unordered_map<int,int> visited;
    int area=1;
    if (i + 1 < n&&grid[i+1][j]) {
        int v=((i+1)*n)+j;
        int u=ds.findpar(v);
        if(!visited[u])
            {area+=ds.sizes[u]  ; 
            visited[u]++; }     
    }
    if (i - 1 >= 0&&grid[i-1][j]) {
        int v=((i-1)*n)+j;
        int u=ds.findpar(v);
        if(!visited[u])
            {area+=ds.sizes[u]  ; 
            visited[u]++; }  
    }
    if (j + 1 < n&&grid[i][j+1]) {
        int v=((i)*n)+j+1;
        int u=ds.findpar(v);
        if(!visited[u])
            {area+=ds.sizes[u]  ; 
            visited[u]++; }  
    }
    if (j - 1 >= 0&&grid[i][j-1]) {
        int v=((i)*n)+j-1;
        int u=ds.findpar(v);
        if(!visited[u])
            {area+=ds.sizes[u]  ; 
            visited[u]++; }  
    }
    return area;
}
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n * n);
        
        int ans = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                   
                    
                    int u = (i * n) + j;
                    if (i + 1 < n&&grid[i+1][j] ) {
                        int v = ((i + 1) * n) + j;
                       
                            ds.unionBySize(u, v);
                        
                    }
                    if (i - 1 >= 0&&grid[i-1][j]) {
                        int v = ((i - 1) * n) + j;
                        
                            ds.unionBySize(u, v);
                        
                    }
                    if (j + 1 < n&& grid[i][j+1] ) {
                        int v = ((i)*n) + j + 1;
                        
                            ds.unionBySize(u, v);
                        
                    }
                    if (j - 1 >= 0&&grid[i][j-1]) {
                        int v = ((i)*n) + j - 1;
                        
                            ds.unionBySize(u, v);
                        
                    }
                    ans = max(ans, ds.sizes[ds.findpar(u)]);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    ans = max(ans, area(i, j, n, ds,grid));
                }
            }
        }
        return ans;
    }
};