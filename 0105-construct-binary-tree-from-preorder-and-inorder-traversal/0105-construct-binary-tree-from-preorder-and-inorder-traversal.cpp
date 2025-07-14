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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> valueInorderIndexMap;
        int n = inorder.size();
        for (int idx = 0; idx < n; ++idx) {
            valueInorderIndexMap[inorder[idx]] = idx;
        }

        return buildTreeHelper(preorder, inorder, 0, n - 1, 0, n - 1, valueInorderIndexMap);
    }

    TreeNode* buildTreeHelper(vector<int>& preorder, vector<int>& inorder,
                              int preStart, int preEnd, int inStart, int inEnd,
                              unordered_map<int, int>& valueInorderIndexMap) {

        if (preStart > preEnd || inStart > inEnd) {
            return nullptr;
        }

        int rootNodeValue = preorder[preStart];
        TreeNode* root = new TreeNode(rootNodeValue);

        int inorderIndex = valueInorderIndexMap[rootNodeValue];
        int countLeftSubTreeNodes = inorderIndex - inStart;

        root->left = buildTreeHelper(preorder, inorder, preStart + 1, preStart + countLeftSubTreeNodes,
                                     inStart, inorderIndex - 1, valueInorderIndexMap);

        root->right = buildTreeHelper(preorder, inorder, preStart + countLeftSubTreeNodes + 1, preEnd,
                                      inorderIndex + 1, inEnd, valueInorderIndexMap);

        return root;
    }
};