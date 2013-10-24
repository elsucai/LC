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

	void helper(vector<TreeNode*> &bad, TreeNode* root, TreeNode* &pre){
		if(!root)
			return;
		helper(bad, root->left, pre);
		if(pre != NULL && pre->val > root->val){
			bad.push_back(pre);
			bad.push_back(root);
		}
		
		pre = root;
		helper(bad, root->right, pre);
	}
	
    void recoverTree(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		
		if(!root)
			return;
		
		TreeNode* pre = NULL;
		vector<TreeNode*> bad;
		helper(bad, root, pre);
		
		if(bad.size() < 2)
			return;
		
		swap(bad[0]->val, bad[bad.size()-1]->val);
    }
};
