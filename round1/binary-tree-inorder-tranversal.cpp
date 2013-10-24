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
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		// iteratively
		stack<TreeNode*> s;
		TreeNode* cur;
		vector<int> ret;
		if(!root)
			return ret;
		s.push(root);
		cur = root->left;
		bool done = false;
		
		while(!done){
			if(cur){
				s.push(cur);
				cur = cur->left;
			}
			else{
				// print top of the stack
				if(s.empty()){
					done = true;
					break;
				}
				cur = s.top();
				s.pop();
				ret.push_back(cur->val);
				cur = cur->right;
			}
		}
		
		return ret;
    }
};