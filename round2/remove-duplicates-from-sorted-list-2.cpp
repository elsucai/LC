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

		ListNode* front, *pre, *ptr;
		int cnt = 0;
		int cur_val = head->val;
		front = ptr = head;
		pre = NULL;

		while(ptr){
			while(ptr && ptr->val == cur_val){
				cnt++;
				ptr = ptr->next;
			}
			if(cnt == 1){
				front->val = cur_val;
				pre = front;
				front = front->next;
			}
			if(ptr){
			    cur_val = ptr->val;
			    cnt = 0;
			}
		}
		if(!pre)
			return NULL;
		pre->next = NULL;
		return head;
    }
};
