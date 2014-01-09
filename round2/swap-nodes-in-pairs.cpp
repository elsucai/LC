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
		ListNode*s, *e, *remain;
		s = head;
		e = head->next;
		remain = e->next;
		e->next = s;
		s->next = swapPairs(remain);
		return e;
    }
};
