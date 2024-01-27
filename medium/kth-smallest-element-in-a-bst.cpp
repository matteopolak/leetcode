class Solution {
public:
	int kthSmallest(TreeNode *root, int k) {
		// approach:
		// go to the smallest node (left until there's nothing)
		// then, we can go to the next smallest in the following way:
		//
		// 1. the element to the right, if it exists
		// 2. the parent element
		//
		// note: this is just inorder traversal, so we're going
		// to construct it and get the kth element (1-indexed, so -1)

		vector<int> vals;

		inorder(k, 0, root, vals);

		printf("hello world");

		return vals[k - 1];
	}

	int inorder(int k, int i, TreeNode *node, vector<int> &vals) {
		if (node == nullptr || i >= k)
			return i;

		i = inorder(k, i, node->left, vals);
		i++;
		vals.push_back(node->val);

		return inorder(k, i, node->right, vals);
	}
};
