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
    
	void helper(vector<TreeNode*> &ret, int start, int end){
		TreeNode* root;
		if(start > end){
			root = NULL;
			ret.push_back(root);
			return;
		}
		
		if(start == end){
			root = new TreeNode(start);
			ret.push_back(root);
			return;
		}
		if(end == start+1){
			// 2 variations
			root = new TreeNode(start);
			root->right = new TreeNode(end);
			ret.push_back(root);
			
			root = new TreeNode(end);
			root->left = new TreeNode(start);
			ret.push_back(root);
			
			return;
		}
		
		// recursive call
		vector<TreeNode* > left;
		vector<TreeNode*> right;
		int i,j;
		for(int center = start; center <= end; center++){
			left.clear();
			right.clear();
			helper(left, start, center-1);
			helper(right, center+1, end);
			
			for(i = 0; i < left.size(); i++){
				for(j = 0; j < right.size(); j++){
					root = new TreeNode(center);
					root->left = left[i];
					root->right = right[j];
					ret.push_back(root);
				}
			}
		}
		return;
	}

    vector<TreeNode *> generateTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<TreeNode* >ret;
		
		helper(ret, 1, n);
		return ret;
    }
};