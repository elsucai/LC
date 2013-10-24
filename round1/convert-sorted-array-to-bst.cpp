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
	void helper(TreeNode* &root, vector<int> &num, int s, int e){
		if(s > e)
			return;
		int m = s + (e - s)/2;
		if(!root){
			root = new TreeNode(num[m]);
		}

		helper(root->left, num, s, m-1);
		helper(root->right, num, m+1, e);
	}


    TreeNode *sortedArrayToBST(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
       
		TreeNode* root = NULL;
		if(num.empty())
			return NULL;

		int s, e;
		s = 0;
		e = num.size()-1;
		helper(root, num, s, e);
		return root;
    }
};
