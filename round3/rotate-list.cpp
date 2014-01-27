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
    ListNode *rotateRight(ListNode *head, int k) {
		if(!head || !head->next || k <= 0)
			return head;
		int cnt = 0;
		ListNode* pre, *s, *e;
		for(s = head; s; s = s->next)
			cnt++;
		k = k%cnt;
		if(k == 0)
			return head;
		int i;
		for(s = e = head, i = 1; i < k; i++)
			e = e->next;
		for(pre = NULL; e->next; ){
			pre = s;
			s = s->next;
			e = e->next;
		}
		e->next = head;
		pre->next = NULL;
		return s;
    }
};
