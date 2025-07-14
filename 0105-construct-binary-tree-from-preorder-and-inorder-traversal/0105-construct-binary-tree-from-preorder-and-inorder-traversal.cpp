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
        unordered_map<int, int> map;
        for (int i = 0; i < inorder.size(); ++i) {
            map[inorder[i]] = i;
        }
        return build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, map);
    }

    TreeNode* build(vector<int>& preorder, int prestart, int preend, 
                    vector<int>& inorder, int instart, int inend, 
                    unordered_map<int, int>& map) {
        if (prestart > preend || instart > inend) return nullptr;

        TreeNode* node = new TreeNode(preorder[prestart]);
        int x = map[preorder[prestart]];
        int y = x - instart;

        node->left = build(preorder, prestart + 1, prestart + y, inorder, instart, x - 1, map);
        node->right = build(preorder, prestart + y + 1, preend, inorder, x + 1, inend, map);

        return node;
    }
};