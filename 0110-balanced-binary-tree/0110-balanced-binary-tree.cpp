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
    pair<int,bool> isBalanceHelper(TreeNode* root){
        if(root == nullptr){
            return {0, true};
        }
        pair<int,bool> leftInfo = isBalanceHelper(root->left);
        pair<int,bool> rightInfo = isBalanceHelper(root->right);

        bool isCurrTreeBalanced = leftInfo.second == true && rightInfo.second == true &&
                                    abs(leftInfo.first - rightInfo.first)<=1;
        int currTreeHeight = max(leftInfo.first, rightInfo.first) + 1;

        return {currTreeHeight, isCurrTreeBalanced};
    }
    bool isBalanced(TreeNode* root) {
        return isBalanceHelper(root).second;
    }
};