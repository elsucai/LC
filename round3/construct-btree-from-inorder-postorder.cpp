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
	TreeNode* helper(vector<int> &inorder, int is, int ie, vector<int> &postorder, int ps, int pe){
		if(is > ie)
			return NULL;
		int rootval = postorder[pe];
		TreeNode* root = new TreeNode(rootval);
		int x;
		for(x = is; x <= ie; x++){
			if(inorder[x] == rootval)
				break;
		}
		// x is the root index in inorder
		int lsize = x-is;
		root->left = helper(inorder, is, x-1, postorder, ps, ps+lsize-1);
		root->right = helper(inorder, x+1, ie, postorder, ps+lsize, pe-1);
		return root;
	}

	TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
		if(inorder.empty() || inorder.size() != postorder.size())
			return NULL;
		return helper(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
    }
};
