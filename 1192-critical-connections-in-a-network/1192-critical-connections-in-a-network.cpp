    class Solution {
    public:

        void solve(vector<vector<int>>& list,vector<int>&visited,vector<int>& tin,vector<int>&low,vector<vector<int>>&ans,int curr,int pi,int &count){
            visited[curr]=1;
            tin[curr]=count;
            low[curr]=count;
            count++;
            for(auto u:list[curr]){
                if(!visited[u]){
                    solve(list,visited,tin,low,ans,u,curr,count);
                    low[curr]=min(low[u],low[curr]);
                }
                else if(u!=pi){
                    low[curr]=min(low[curr],tin[u]);
                }

                if(tin[curr]<low[u]){
                    ans.push_back({curr,u});
                }
            }
        }

        vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
            vector<vector<int>> ans;
            vector<vector<int>> list(n);
            for(auto e:connections){
                list[e[0]].push_back(e[1]);
                list[e[1]].push_back(e[0]);
            }
            vector<int> visited(n,0),tin(n),low(n);
            int count=0;
            solve(list,visited,tin,low,ans,0,-1,count);
            return ans;
        }
    };