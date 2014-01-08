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
		if(is > ie || ps > pe)
			return NULL;
		int cur_root = postorder[pe];
		//find index in inorder
		int index = is;
		for(; index <= ie; index++){
			if(inorder[index] == cur_root)
				break;
		}
		if(index > ie)
			return NULL;
		int leftsize = index-is;
		TreeNode* root = new TreeNode(cur_root);
		root->left = helper(inorder, is, index-1, postorder, ps, ps+leftsize-1);
		root->right = helper(inorder, index+1, ie, postorder, ps+leftsize, pe-1);
		return root;
	}

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
		if(inorder.empty() || inorder.size() != postorder.size())
			return NULL;
		int size = inorder.size();
		return helper(inorder, 0, size-1, postorder, 0, size-1);
    }
};
