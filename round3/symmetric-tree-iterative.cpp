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
    bool isSymmetric(TreeNode *root) {
		if(!root)
			return true;
		stack<TreeNode* >sa;
		stack<TreeNode* >sb;
		TreeNode* a,*b; 

		int cnt;
		
		cnt = 0;
		if(root->left){
			sa.push(root->left);
			cnt++;
		}
		if(root->right){
			sb.push(root->right);
			cnt++;
		}
		if(cnt == 1)
			return false;
			
		while(!sa.empty() && !sb.empty()){
			a = sa.top();
			b = sb.top();
			sa.pop();
			sb.pop();
			if(a->val != b->val)
				return false;
			cnt = 0;
			if(a->left){
				sa.push(a->left);
				cnt++;
			}
			if(b->right){
				sb.push(b->right);
				cnt++;
			}
			if(cnt == 1)
				return false;
			
			cnt = 0;
			if(a->right){
				sa.push(a->right);
				cnt++;
			}
			if(b->left){
				sb.push(b->left);
				cnt++;
			}
			if(cnt == 1)
				return false;
		}
		return true;
    }
};
