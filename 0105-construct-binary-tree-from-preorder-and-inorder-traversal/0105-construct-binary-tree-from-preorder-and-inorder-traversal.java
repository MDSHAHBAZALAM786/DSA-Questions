/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        
        HashMap<Integer, Integer> valueInorderIndexMap = new HashMap<>();
        int n = inorder.length;
        for(int idx=0; idx < n; ++idx){
            valueInorderIndexMap.put(inorder[idx], idx);
        }

        TreeNode completeTree = buildTreeHelper(preorder, inorder, 0, n-1, 0, n-1,              
                                                              valueInorderIndexMap);
        return completeTree;
    }

    public TreeNode buildTreeHelper(int[] preorder, int[] inorder, int preStart, int preEnd,
                            int inStart, int inEnd, HashMap<Integer, Integer> valueInorderIndexMap){
        
        if(preStart > preEnd || inStart>inEnd){
            return null;
        }
        int rootNodeValue = preorder[preStart];

        TreeNode root = new TreeNode(rootNodeValue);
        int inorderIndex = valueInorderIndexMap.get(rootNodeValue);
        int countLeftSubTreeNodes = inorderIndex - inStart;

        root.left = buildTreeHelper(preorder, inorder, preStart+1, preStart + countLeftSubTreeNodes,
                                    inStart, inorderIndex - 1, valueInorderIndexMap);
        root.right = buildTreeHelper(preorder, inorder, preStart + countLeftSubTreeNodes+1, preEnd,
                                 inorderIndex + 1, inEnd, valueInorderIndexMap);
        
        return root;
                            }
}