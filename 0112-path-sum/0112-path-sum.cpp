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

    bool hasPathSumHelper(TreeNode* root, int targetSum, int currPathSum){
        if(root == NULL){   // NULL Case
            return false;
        }
        currPathSum += root->val;
        // leafnode condition
        if(root->left == NULL && root->right == NULL){
            if(currPathSum == targetSum){
                return true;
            }else{
                return false;
            }
        }
        else{
            return hasPathSumHelper(root->left, targetSum, currPathSum) ||
                    hasPathSumHelper(root->right, targetSum, currPathSum);
        }
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        
        return hasPathSumHelper(root, targetSum, 0);
    }
};