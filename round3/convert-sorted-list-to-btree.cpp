/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
	TreeNode* helper(ListNode* &head, int s, int e){
		if(s > e)
			return NULL;
		int m = s + (e-s)/2;
		TreeNode* left = helper(head, s, m-1);
		TreeNode* root = new TreeNode(head->val);
		head = head->next;
		TreeNode* right = helper(head, m+1, e);
		root->left = left;
		root->right = right;
		return root;
	}

    TreeNode *sortedListToBST(ListNode *head) {
		if(!head)
			return NULL;
		int n = 0;
		for(ListNode* ptr = head; ptr; ptr = ptr->next)
			n++;
		return helper(head, 0, n-1);
    }
};
