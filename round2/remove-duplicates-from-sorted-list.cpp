/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
		if(!head || !head->next)
			return head;
		ListNode* curnode, *ptr, *pre;
		int cur_val;
		
		curnode = ptr = head->next;
		cur_val = head->val;
		pre = head;

		while(ptr){
			if(ptr->val != cur_val){
				cur_val = curnode->val = ptr->val;
				pre = curnode;
				curnode = curnode->next;
			}
			ptr = ptr->next;
		}
		pre->next = NULL;
		return head;
    }
};
