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

int solve(TreeNode* root,int &ans,unordered_map<TreeNode*,int> &dp){
    if(root==NULL){
        return 0;
    }
    if(dp.count(root))return dp[root];
    int left=solve(root->left,ans,dp);
    int right=solve(root->right,ans,dp);
    ans=max(ans,left+right);
    return max(left,right)+1;
}

    int diameterOfBinaryTree(TreeNode* root) {
        int ans=0;
        unordered_map<TreeNode*,int> dp;
        solve(root,ans,dp);
        return ans;
    }
};