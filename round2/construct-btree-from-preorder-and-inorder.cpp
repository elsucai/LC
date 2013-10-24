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
		if(ps > pe || is > ie)
			return NULL;
		int cur = preorder[ps];
		TreeNode* root = new TreeNode(cur);
		// find left and right subtrees
		int i;
		for(i = is; i <= ie; i++){
			if(inorder[i] == cur)
				break;
		}
		
		if(i > ie)
			return NULL;
		// i is the root position
		int leftsize = i - is;
		root->left = helper(preorder, ps+1, ps + leftsize, inorder, is, i-1);
		root->right = helper(preorder, ps+leftsize+1, pe, inorder, i+1, ie);
		
		return root;
	}

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(preorder.size() != inorder.size() || preorder.empty())
			return NULL;
		return helper(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
};