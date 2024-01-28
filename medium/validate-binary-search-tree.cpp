class Solution {
public:
	bool isValidBST(TreeNode *root) {
		if (root == nullptr)
			return true;

		return isValid(root, ((long long)INT_MIN) - 1, ((long long)INT_MAX) + 1);
	}

	bool isValid(TreeNode *node, long long lo, long long hi) {
		if (node == nullptr)
			return true;

		return node->val < hi && node->val > lo &&
					 isValid(node->left, lo, node->val) &&
					 isValid(node->right, node->val, hi);
	}
};
