class DisjointSet{
    vector<int> sizes;
    vector<int> parent;
    public:
        DisjointSet(int n){
            sizes.resize(n,1);
            parent.resize(n);
            for(int i=0;i<n;i++)parent[i]=i;
        }

        int findpar(int node){
            if(parent[node]==node)return node;
            return parent[node]=findpar(parent[node]);
        }
        void unionBySize(int u,int v){
            int ultp_u=findpar(u);
            int ultp_v=findpar(v);
            if(ultp_u==ultp_v)return;
            if(sizes[ultp_u]>=sizes[ultp_v]){
                parent[ultp_v]=ultp_u;
                sizes[ultp_u]+=sizes[ultp_v];
            }
            else {
                parent[ultp_u]=ultp_v;
                sizes[ultp_v]+=sizes[ultp_u];
            }
        }
        int connected(){
            int n=parent.size();
            unordered_set<int> set;
            for(int i=0;i<n;i++){
                set.insert(findpar(i));// we not use parent[i] because it may be case where when last node is connected then the ultimate parent is not updated that's why we have to use findpar(i)
            }
            return set.size();
        }
};


class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        DisjointSet ds(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1&&ds.findpar(i)!=ds.findpar(j)){
                    ds.unionBySize(i,j);
                }
            }
        }
        return ds.connected();
    }
};