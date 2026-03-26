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

int solve(TreeNode* root,int& ans){
    if(root==NULL){
        return 0;
    }
    int left=max(0,solve(root->left,ans));//if we not want to select left that's why we find max of 0,left
    int right=max(0,solve(root->right,ans));
    ans=max(ans,root->val+left+right);
    return max(left,right)+root->val;
}

    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        solve(root,ans);
        return ans;
    }
};