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
		ListNode* pre, *s, *e;
		int cur;
		for(cur = head->val, pre = head, s = e = head->next; e; ){
			for(; e && e->val == cur; e = e->next)
				;
			if(!e){
				pre->next = NULL;
				return head;
			}
			s->val = e->val;
			cur = s->val;
			pre = s;
			s = s->next;
			e = e->next;
		}
		pre->next = NULL;
		return head;
    }
};
