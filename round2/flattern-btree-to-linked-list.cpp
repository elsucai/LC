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
		// return tail of the flatterned list
		if(!root)
			return NULL;;

		TreeNode *lhead, *rhead, *ltail, *rtail;
		lhead = root->left;
		rhead = root->right;
		
		ltail = helper(root->left);
		rtail = helper(root->right);

		root->left = NULL;
		if(lhead)
			root->right = lhead;
		else if(rhead)
			root->right = rhead;
		else
			root->right = NULL;

		if(ltail)
			ltail->right = rhead;
		if(rtail)
			return rtail;
		if(ltail)
			return ltail;
		return root;
	}


    void flatten(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
		
		helper(root);
	}
};
