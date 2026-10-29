class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode (int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class Solution {
    int maxD = 0;
    int maxDepth(TreeNode node) {
        if (node == null) return 0;
        int left = maxDepth(node.left);
        int right = maxDepth(node.right);
        this.maxD = Math.max(maxD, left+right);
        return Math.max(left, right) + 1;
    }
    int diameterOfBinaryTree(TreeNode root) {
        maxDepth(root);
        int ans = this.maxD;
        this.maxD = 0;
        return ans;
    }
}