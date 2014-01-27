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
    ListNode *reverseKGroup(ListNode *head, int k) {
		if(!head || !head->next || k <= 1)
			return head;
		ListNode* A, *B, *s, *cur, *e, *pre, *next;
		pre = A = B = e = next = cur = NULL;
		s = e = head;
		int i;
		while(s){
			for(e = s, i = 1; i < k; i++){
				if(!e)
					return head;
				e = e->next;
			}
			if(!e)
				return head;
			B = e->next;
			// reverse this segment
			for(pre = NULL, cur = s; cur != B;){
				next = cur->next;
				cur->next = pre;
				pre = cur;
				cur = next;
			}
			s->next = B;
			if(!A)
				head = e;
			else
				A->next = e;
			A = s;
			s = B;
		}
		return head;
    }
};
