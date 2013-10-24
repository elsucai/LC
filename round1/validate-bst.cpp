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
	// using iterative in-order tranverse
	bool isValidBST(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		if(!root)
			return true;
			
		stack<TreeNode*> s;
		int pre = INT_MIN;
		int val;
		
		TreeNode* current;
		s.push(root);
		current = root->left;
		
		while(true){
			if(current){
				s.push(current);
				current = current->left;
			}
			else{
				if(s.empty())
					return true;
				val = s.top()->val;
				if(pre >= val)
					return false;
				current = s.top()->right;
				s.pop();
				pre = val;
			}
		}
		return true;
    }
	
/*
	bool helper(TreeNode* root, int min, int max){
		if(!root)
			return true;
		if(root->val > max || root->val < min)
			return false;
		
		return helper(root->left, min, root->val - 1) && helper(root->right, root->val+1, max);
	}
	
    bool isValidBST(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		if(!root)
			return true;
			
		return helper(root, INT_MIN, INT_MAX);
    }
*/	
};