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
        unordered_map<int,TreeNode*> tree;
        unordered_set <int> childs;
        for(auto & d:descriptions){
            int p=d[0],c=d[1],l=d[2];
            childs.insert(c);
            TreeNode* parent;
            if(tree.count(p)){
                parent=tree[p];
            }
            else{
                parent=new TreeNode(p);
                tree[p]=parent;
            }

            // child
            TreeNode* child;
            if(tree.count(c)){
                child=tree[c];
                
            }
            else{
                child=new TreeNode(c);
                tree[c]=child;
                
            }

            if(l){
                    parent->left=child;
                }
                else{
                    parent->right=child;
                }
        }
        for(auto d: descriptions){
            if(!childs.count(d[0])){
                return tree[d[0]];
            }
        }
        return nullptr;
    }
};