/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*
 * For this problem, a height-balanced binary tree is defined as a binary tree
 * in which the depth of the two subtrees of every node never differ by more
 * than 1. 
 * */

class Solution {
public:
    bool get_max(TreeNode* root, int& max){
		if(!root){
			max = 0;
			return true;
		}
		int cur_lmax, cur_rmax;

		
		if(!get_max(root->left, cur_lmax))
			return false;
		if(!get_max(root->right, cur_rmax))
			return false;
	
		if(abs(cur_lmax - cur_rmax) > 1)
			return false;

		if(cur_lmax > cur_rmax)
			max = cur_lmax+1;
		else
			max = cur_rmax+1;
		return true;
	}

    bool isBalanced(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		
		if(!root)
			return true;
		int max;
		return get_max(root, max);
    }
};
