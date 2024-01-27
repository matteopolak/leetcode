class Solution {
public:
	TreeNode *invertTree(TreeNode *root) {
		if (root == nullptr)
			return root;

		if (root->left != nullptr) {
			invertTree(root->left);
		}

		if (root->right != nullptr) {
			invertTree(root->right);
		}

		TreeNode *temp = root->left;

		root->left = root->right;
		root->right = temp;

		return root;
	}
};
