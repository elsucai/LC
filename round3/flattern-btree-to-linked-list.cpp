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
	TreeNode* helper(TreeNode* root, TreeNode* &tail){
		if(!root){
			tail = NULL;
			return NULL;
		}
		TreeNode* left, *ltail, *right, *rtail;
		left = helper(root->left, ltail);
		right = helper(root->right, rtail);
		root->left = NULL;
		tail = root;
		if(left){
			tail->right = left;
			tail = ltail;
		}
		tail->right = right;
		if(right)
			tail = rtail;

		return root;
	}

    void flatten(TreeNode *root) {
		if(!root)
			return;
		TreeNode* tail;
		helper(root, tail);
    }
};
