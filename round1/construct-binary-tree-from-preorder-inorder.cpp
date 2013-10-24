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

	void helper(TreeNode* &root, vector<int> &preorder, int ps, int pe, vector<int> &inorder, int is, int ie){
		if(ps > pe || is > ie)
			return;
		int i,size,val;
		if(!root){
			val = preorder[ps];
			root = new TreeNode(val);
		}
		//find root in inorder
		for(i = is; i <= ie; i++){
			if(inorder[i] == val)
				break;
		}
		// i is the root in inorder
		size = i - is;
		helper(root->left, preorder, ps+1, ps+size, inorder, is, i-1);
		helper(root->right, preorder, ps+1+size, pe, inorder, i+1, ie);
	}

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		TreeNode* root = NULL;

		if(preorder.empty())
			return NULL;
		if(preorder.size() != inorder.size())
			return NULL;

		int ps, pe, is, ie;
		ps = is = 0;
		pe = ie = preorder.size()-1;

		helper(root, preorder, ps, pe, inorder, is, ie);
		return root;
    }
};
