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
	TreeNode* helper(TreeNode* root){
		// flattern tree to list
		// return tail node
		if(!root)
			return NULL;
		TreeNode* lefttail = helper(root->left);
		TreeNode* righttail = helper(root->right);

		TreeNode* tmp = root->right;
				
		if(lefttail){
			root->right = root->left;
			root->left = NULL;
			lefttail->right = tmp;
		}
		
		if(righttail)
			return righttail;
		if(lefttail)
			return lefttail;
		return root;
	}

    void flatten(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		if(!root)
			return;
		TreeNode* tmp = helper(root);
	}
};
