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
	bool is_mirror(TreeNode* a, TreeNode* b){
		if(!a)
			return !b;
		if(!b)
			return !a;
		if(a->val != b->val)
			return false;
		
		return is_mirror(a->left, b->right) && is_mirror(a->right, b->left);
	}
	
    bool isSymmetric(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		if(!root)
			return true;
		
		return is_mirror(root->left, root->right);
    }
};