/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,int> visited;
        unordered_map<int,vector<pair<int,int>>> graph;
        for(auto & a:descriptions){
            visited[a[1]]=1;
            graph[a[0]].push_back({a[1],a[2]});
        }
        queue<TreeNode*> queue;
        for(auto &a:descriptions){
            if(!visited.count(a[0])){
                TreeNode* temp=new TreeNode(a[0]);
                queue.push(temp);
                break;
            }
        }
        TreeNode* tree=queue.front();
        while(!queue.empty()){
            auto curr=queue.front();
            queue.pop();
            for(auto [u,left]:graph[curr->val]){
                TreeNode* temp=new TreeNode(u);
                if(left){
                    curr->left=temp;
                }
                else{
                    curr->right =temp;
                }
                queue.push(temp);
            }
        }
        return tree;
    }
};