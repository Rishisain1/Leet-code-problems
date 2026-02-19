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
    int validcomponent(int n){
        unordered_set<int> set;
        for(int i=0;i<n;i++){
            set.insert(findpar(i));
        }
        int count=0;
        for(int i:set){
            if(sizes[i]>1){
                count++;
            }
        }
        return count;
    }
};


class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int maxrow=0;
        int maxcol=0;
        int n=stones.size();
        for(auto s:stones){
            int r=s[0];
            int c=s[1];
            maxrow=max(maxrow,r);
            maxcol=max(maxcol,c);
        }

        DisjointSet ds((++maxrow)+(++maxcol));
        for(auto s:stones){
            int u=s[0];
            int v=s[1]+maxrow;
            ds.unionBySize(u,v);         

        }
        return n - ds.validcomponent(maxrow+maxcol);

    }
};