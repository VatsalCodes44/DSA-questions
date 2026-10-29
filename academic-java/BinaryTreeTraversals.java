import java.util.*;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class inOrder {
    void inorder(TreeNode node, ArrayList<Integer> ans) {
        if (node == null) return;
        inorder(node.left, ans);
        ans.add(node.val);
        inorder(node.right, ans);
    }
    public List<Integer> inorderTraversal(TreeNode root) {
        ArrayList<Integer> ans = new ArrayList<>();
        inorder(root, ans);
        return ans;
    }
}

class preOrder {
    void f(TreeNode node, ArrayList<Integer> arr) {
		if (node == null) return;
		arr.add(node.val);
		f(node.left, arr);
		f(node.right, arr);
	}
    public List<Integer> preorderTraversal(TreeNode root) {
		ArrayList<Integer> ans = new ArrayList<>();
		f(root, ans);
		return ans;
    }
}

class LevelOrder {
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> ans = new ArrayList<>();
        if (root == null) return ans;
        Deque<TreeNode> dq = new ArrayDeque<>();
        dq.push(root);
        while (!dq.isEmpty()) {
            int n = dq.size();
            ArrayList<Integer> lvl = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                TreeNode curr = dq.getFirst();
                lvl.add(curr.val);
                dq.removeFirst();
                if (curr.left != null) dq.addLast(curr.left);
                if (curr.right != null) dq.addLast(curr.right);
            }
            ans.addLast(lvl);
        }
        return ans;
    }
}
