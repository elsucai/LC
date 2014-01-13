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
	TreeNode* helper(vector<int> &preorder, int ps, int pe, vector<int> &inorder, int is, int ie){
		if(ps > pe)
			return NULL;
		int x;
		int rootval = preorder[ps];
		for(x = is; x <= ie; x++){
			if(inorder[x] == rootval)
				break;
		}
		int lsize = x-is;
		TreeNode* root = new TreeNode(rootval);
		root->left = helper(preorder, ps+1, ps+lsize, inorder, is, x-1);
		root->right = helper(preorder, ps+lsize+1, pe, inorder, x+1, ie);
		return root;
	}

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
		if(preorder.empty() || preorder.size() != inorder.size())
			return NULL;
		return helper(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
};
