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
	void helper(TreeNode* root, int &sum, int pre){
		if(!root)
			return;
		int sofar = pre*10+root->val;
		if(!root->left && !root->right){
			sum += sofar;
			return;
		}
		helper(root->left, sum, sofar);
		helper(root->right, sum, sofar);
	}

    int sumNumbers(TreeNode *root) {
		int sum = 0;
		helper(root, sum, 0);
		return sum;
    }
};
