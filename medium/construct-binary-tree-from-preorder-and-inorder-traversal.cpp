/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
	TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
		unordered_map<int, int> inorderMap;

		for (int i = 0; i < inorder.size(); i++) {
			inorderMap[inorder[i]] = i;
		}

		return buildTree(preorder, 0, preorder.size() - 1, inorderMap, 0,
										 inorder.size() - 1);
	}

private:
	TreeNode *buildTree(vector<int> &preorder, int preStart, int preEnd,
											unordered_map<int, int> &inorderMap, int inStart,
											int inEnd) {
		if (preStart > preEnd)
			return nullptr;

		TreeNode *root = new TreeNode(preorder[preStart]);
		int inRoot = inorderMap[root->val];
		int numsLeft = inRoot - inStart;

		root->left = buildTree(preorder, preStart + 1, preStart + numsLeft,
													 inorderMap, inStart, inRoot - 1);
		root->right = buildTree(preorder, preStart + numsLeft + 1, preEnd,
														inorderMap, inRoot + 1, inEnd);

		return root;
	}
};
