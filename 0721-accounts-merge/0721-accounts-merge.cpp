class DisjointSet{
    public:
    unordered_map<string,string> parent;
    unordered_map<string ,int> sizes;

    DisjointSet(vector<vector<string>>& accounts){
        int n=accounts.size();
        for(int i=0;i<n;i++){
            int m=accounts[i].size();
            for(int j=1;j<m;j++){
                parent[accounts[i][j]]=accounts[i][j];
                sizes[accounts[i][j]]=1;
            }
        }
    }

    string findpar(string node){
        if(parent[node]== node)return node;
        return parent[node]=findpar(parent[node]);
    }

    void unionBySize(string u,string v){
        string ultp_u=findpar(u);
        string ultp_v=findpar(v);
        if(ultp_u==ultp_v)return ;
        if(sizes[ultp_u]>=sizes[ultp_v]){
            parent[ultp_v]=ultp_u;
            sizes[ultp_u]+=sizes[ultp_v];
        }
        else{
            parent[ultp_u]=ultp_v;
            sizes[ultp_v]+=sizes[ultp_u];
        }
    }

};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        DisjointSet ds(accounts);
        int n=accounts.size();
        for(int i=0;i<n;i++){
            int m=accounts[i].size();
            for(int j=2;j<m;j++){
                
                    ds.unionBySize(accounts[i][1],accounts[i][j]);
                
            }
        }
        vector<vector<string>> ans;
        int index=-1;
        unordered_map<string,int> visited;
        unordered_map<string,int> visitedchild;
        for(int i=0;i<n;i++){
            int m=accounts[i].size();
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            
            for(int j=1;j<m;j++){
                if(!visited[ds.findpar(accounts[i][j])]){
                    index++;
                    visited[ds.findpar(accounts[i][j])]=index+1;
                    temp.push_back(accounts[i][j]);
                    ans.push_back(temp);
                    visitedchild[accounts[i][j]]++;
                }
                else{
                    // ans[visited[accounts[i][j]]-1].push_back(accounts[i][j]); // in this line i did mistake account shoult be the prent then only the index is exist sooo
                    if(!visitedchild[accounts[i][j]]){
                        ans[visited[ds.findpar(accounts[i][j])]-1].push_back(accounts[i][j]);
                        visitedchild[accounts[i][j]]++;
                    }
                }
            }
            
        }
        int s=ans.size();
        for(int i=0;i<s;i++){
            sort(ans[i].begin()+1,ans[i].end());
        }
        return ans;
    }
};