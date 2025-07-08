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

void preOrderHelper(TreeNode* root, vector<int>& ans){
    if(root == NULL){
        return;
    }
    preOrderHelper(root->left, ans);
    ans.push_back(root->val);
    preOrderHelper(root->right, ans);
}
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        preOrderHelper(root, ans);
        return ans; 
    }
};