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
	
    vector<int> inorderTraversal(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
     	vector<int> ret;
		stack<TreeNode*> s;
		if(!root)
			return ret;

		TreeNode* cur = root;
		
		while(1){
			while(cur){
				s.push(cur);
				cur = cur->left;
			}
			// reached the leftmost
			if(s.empty())
				break;
			cur = s.top();
			s.pop();
			ret.push_back(cur->val);
			cur = cur->right;
		}
     	
     	return ret;
    }
};
