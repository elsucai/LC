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
    ListNode *swapPairs(ListNode *head) {
		if(!head || !head->next)
			return head;
		ListNode* front, *pre, *cur, *remain, *s, *e, *next;
		front = pre = cur = remain = s = e = next = NULL;

		for(s = e = head; s; ){
			// locate e and remain
			e = s->next;
			if(!e)
				return head;
			remain = e->next;

			for(pre = NULL, cur = s; cur != remain;){
				next = cur->next;
				cur->next = pre;
				pre = cur;
				cur = next;
			}

			if(!front)
				head = e;
			else
				front->next = e;
			s->next = remain;
			front = s;
			s = remain;
		}
		return head;
    }
};
