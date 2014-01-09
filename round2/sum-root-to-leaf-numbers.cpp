/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	void helper(TreeNode* cur, int &sum, int given){
		if(!cur)
			return;
		given += cur->val;
		if(!cur->left && !cur->right){
			sum += given;
			return;
		}
		if(cur->left)
			helper(cur->left, sum, given*10);
		if(cur->right)
			helper(cur->right, sum, given*10);
	}

    int sumNumbers(TreeNode *root) {
        if(!root)
			return 0;
		int sum = 0;
		helper(root, sum, 0);
		return sum;
	}
};
