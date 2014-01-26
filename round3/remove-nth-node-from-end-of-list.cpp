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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
		if(!head)
			return NULL;
		ListNode* pre, *s, *e;
		pre = NULL;
		s = e = head;
		for(int i = 1; i < n; i++){
			if(!e->next)
				return head;
			e = e->next;
		}
		while(e->next){
			e = e->next;
			pre = s;
			s = s->next;
		}
		if(!pre)
			return head->next;
		pre->next = pre->next->next;
		return head;
    }
};
