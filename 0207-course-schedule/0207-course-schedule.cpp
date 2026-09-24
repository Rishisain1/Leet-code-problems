class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> visited(numCourses,0);
        vector<vector<int>> graph(numCourses);
        vector<int> inorder(numCourses,0);
        for(auto &pre:prerequisites){
            int a=pre[0],b=pre[1];
            inorder[a]++;
            graph[b].push_back(a);
        }
        int count=0;
        queue<int> queue;
        for(int i=0;i<numCourses;i++){
            if(inorder[i]==0){
                queue.push(i);
            }
        }
        while(!queue.empty()){
            count++;
            int curr=queue.front();
            queue.pop();
            for(auto u:graph[curr]){
                inorder[u]--;
                if(inorder[u]==0){
                    queue.push(u);
                }
            }
        }
        if(count == numCourses)return true;
        return false;
    }
};