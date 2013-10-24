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
		int m = s + (e - s)/2;
		TreeNode* left = helper(head, s, m-1);
		TreeNode* root = new TreeNode(head->val);
		root->left = left;
		head = head->next;
		root->right = helper(head, m+1, e);
		
		return root;
	}
	
    TreeNode *sortedListToBST(ListNode *head) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(!head)
			return NULL;
		int cnt = 0;
		ListNode* ptr = head;
		for(ptr = head; ptr != NULL; ptr = ptr->next)
			cnt++;
		return helper(head, 0, cnt-1);
    }
};