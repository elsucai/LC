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
    void recoverTree(TreeNode *root) {
		TreeNode* cur, *pre;
		stack<TreeNode*> s;
		vector<TreeNode*> reverse;

		if(!root)
			return;
		cur = root;
		pre = NULL;
		while(1){
			while(cur){
				s.push(cur);
				cur = cur->left;
			}
			if(s.empty())
				break;
			cur = s.top();
			s.pop();
			if(pre && pre->val > cur->val){
				reverse.push_back(pre);
				reverse.push_back(cur);
			}
			pre = cur;
			cur = cur->right;
		}
		swap(reverse[0]->val, reverse.back()->val);
    }
};
