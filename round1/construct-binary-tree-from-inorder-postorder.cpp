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

    void helper(TreeNode* &root, vector<int> &inorder, int is, int ie, vector<int> &postorder, int ps, int pe){
		if(is > ie || ps > pe)
			return;
		int i, val, size;
		if(!root){
			val = postorder[pe];
			root = new TreeNode(val);
		}
		for(i = is; i <= ie; i++){
			if(inorder[i] == val)
				break;
		}
		// i is the root in inorder
		size = i - is;
		helper(root->left, inorder, is, i-1, postorder, ps, ps + size - 1);
		helper(root->right, inorder, i+1, ie, postorder, ps + size, pe-1);
	}

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		TreeNode* root = NULL;
		if(inorder.empty())
			return NULL;
		if(inorder.size() != postorder.size())
			return NULL;

		int is, ie, ps, pe;
		is = ps = 0;
		ie = pe = inorder.size()-1;

		helper(root, inorder, is, ie, postorder, ps, pe);
        return root;	
    
    }
};
