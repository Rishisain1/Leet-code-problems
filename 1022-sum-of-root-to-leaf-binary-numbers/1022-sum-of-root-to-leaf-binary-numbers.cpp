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

int binaryToDecimal(string s){
    int pow=1;
    int num=0;
    int n=s.length();
    for(int i=n-1;i>=0;i--){
        if(s[i]=='1'){
            num+=pow;
        }
        pow*=2;
    }
    return num;
}

void solve(TreeNode* root,string s,int &ans){
    if(root==NULL){
        return ;
    }
    if(root->right==NULL&&root->left==NULL){
        s+=string(1,root->val+'0');
        ans+=binaryToDecimal(s);
        return;
    }
    s+=string(1,root->val+'0');
    solve(root->left,s,ans);
    solve(root->right,s,ans);
}

    int sumRootToLeaf(TreeNode* root) {
        int ans=0;
        solve(root,"",ans);
        return ans;
    }
};