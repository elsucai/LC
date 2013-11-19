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
    bool isValidBST(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        TreeNode* pre = NULL;
		TreeNode* cur;
		stack<TreeNode*> s;
		if(!root)
			return true;
		cur = root;
		while(true){
			while(cur){
				s.push(cur);
				cur = cur->left;
			}
			if(s.empty())
				return true;
			cur = s.top();
			s.pop();
			if(pre && pre->val >= cur->val)
				return false;
			pre = cur;
			cur = cur->right;
		}
		// should never get here
		return true;
    }
};