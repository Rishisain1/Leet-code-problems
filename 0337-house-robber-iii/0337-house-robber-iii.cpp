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
    map<pair<TreeNode*,int>,int> dp;
    int solve(TreeNode* root,int choose){
        if(root==NULL)return 0;
        if(dp.count({root,choose}))return dp[{root,choose}];
        int c=0,nc=0;
        if(choose){
            c=solve(root->left,0)+solve(root->right,0)+root->val;
        }
            nc=solve(root->left,1)+solve(root->right,1); 
        
        return dp[{root,choose}]= max(c,nc);
    }

    int rob(TreeNode* root) {
        return solve(root,1);
    }
};