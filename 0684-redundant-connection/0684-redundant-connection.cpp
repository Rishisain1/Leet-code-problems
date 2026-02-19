class DisjointSet {
    vector<int> parent;
    vector<int> sizes;
public:    
    DisjointSet(int n) {
        parent.resize(n+1);
        sizes.resize(n+1, 1);
        for (int i = 0; i <= n; i++) {
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


class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        DisjointSet ds(n);

        for(auto e:edges){
            int u=e[0];
            int v=e[1];
            if(ds.findpar(u)==ds.findpar(v)){
                return e;
            }
            else{
                ds.unionBySize(u,v);
            }
        }
        return {};
    }
};