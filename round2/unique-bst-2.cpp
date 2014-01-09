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
	void helper(vector<TreeNode*> &ret, int s, int e){
		if(s > e){
			ret.push_back(NULL);
			return;
		}
		TreeNode* root;
		vector<TreeNode*> left;
		vector<TreeNode*> right;
		int l,r;
		for(int i = s; i <= e; i++){
			left.clear();
			right.clear();
	//		root = new TreeNode(i);
			helper(left, s, i-1);
			helper(right, i+1, e);
			
			if(left.empty() && right.empty()){
			    root = new TreeNode(i);
				ret.push_back(root);
				continue;
			}
			if(left.empty()){
				for(r = 0; r < right.size(); r++){
				    root = new TreeNode(i);
					root->right = right[r];
					ret.push_back(root);
				}
				continue;
			}
			
			if(right.empty()){
				for(l = 0; l < left.size(); l++){
				    root = new TreeNode(i);
					root->left = left[l];
					ret.push_back(root);
				}
				continue;
			}

			for(l = 0; l < left.size(); l++){
				for(r = 0; r < right.size(); r++){
				    root = new TreeNode(i);
					root->left = left[l];
					root->right = right[r];
					ret.push_back(root);
				}
			}
		}
	}

    vector<TreeNode *> generateTrees(int n) {
		vector<TreeNode*> ret;
		if(n <= 0){
			ret.push_back(NULL);
			return ret;
		}
		
		helper(ret, 1, n);
		return ret;
    }
};
