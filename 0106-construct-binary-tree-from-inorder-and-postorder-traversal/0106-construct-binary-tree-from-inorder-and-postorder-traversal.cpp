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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> valueInorderIndexMap;
        int n = inorder.size();

        for (int i = 0; i < n; ++i) {
            valueInorderIndexMap[inorder[i]] = i;
        }

        return buildTreeHelper(postorder, inorder, 0, n - 1, 0, n - 1, valueInorderIndexMap);
    }
    TreeNode* buildTreeHelper(vector<int>& postorder, vector<int>& inorder,
                              int postStart, int postEnd,
                              int inStart, int inEnd,
                              unordered_map<int, int>& valueInorderIndexMap) {
        if (postStart > postEnd || inStart > inEnd) {
            return nullptr;
        }

        int rootVal = postorder[postEnd];
        TreeNode* root = new TreeNode(rootVal);

        int inorderIndex = valueInorderIndexMap[rootVal];
        int leftSize = inorderIndex - inStart;

        root->left = buildTreeHelper(postorder, inorder,
                                     postStart, postStart + leftSize - 1,
                                     inStart, inorderIndex - 1, valueInorderIndexMap);

        root->right = buildTreeHelper(postorder, inorder,
                                      postStart + leftSize, postEnd - 1,
                                      inorderIndex + 1, inEnd, valueInorderIndexMap);

        return root;
    }
};