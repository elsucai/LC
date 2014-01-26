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
		ListNode* s, *pre, *e;
		int cur, cnt;
		for(pre = NULL, s = head, e = head->next, cur = s->val, cnt = 1; e; ){
			for(; e && e->val == cur; cnt++, e = e->next)
				;
			if(!e){
				if(cnt == 1){
					s->val = cur;
					pre = s;
				}
				if(!pre)
					return NULL;
				pre->next = NULL;
				return head;
			}
			if(cnt == 1){
				s->val = cur;
				pre = s;
				s = s->next;

			}
			cur = e->val;
			cnt = 1;
			e = e->next;
		}
		if(cnt == 1){
			s->val = cur;
			pre = s;
		}
		if(!pre)
			return NULL;
		pre->next = NULL;
		return head;
	}
};
