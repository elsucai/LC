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
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(!root)
			return;
		stack<TreeNode*> s;
		TreeNode* cur = root;
		vector<TreeNode*> disorder;
		TreeNode* pre = NULL;
		
		while(true){
			while(cur){
				s.push(cur);
				cur = cur->left;
			}
			if(s.empty())
				break;
			cur = s.top();
			s.pop();
			if(pre && pre->val > cur->val){
				disorder.push_back(pre);
				disorder.push_back(cur);
			}
			pre = cur;
			cur = cur->right;
		}
		
		swap(disorder[0]->val, disorder.back()->val);
		return;
    }
};