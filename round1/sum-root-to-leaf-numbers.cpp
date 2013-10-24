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
	void helper(int &sum, int so_far, TreeNode* root){
		if(!root)
			return;

		so_far = so_far*10 + root->val;
		if(!(root->left) && !(root->right)){
			// a leaf node, should contribute to sum
			sum += so_far;
			return;
		}

		// not a leaf node
		helper(sum, so_far, root->left);
		helper(sum, so_far, root->right);
	}

    int sumNumbers(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		
		if(!root)
			return 0;
		int sum = 0;
		helper(sum, 0, root);
		return sum;
    }
};
