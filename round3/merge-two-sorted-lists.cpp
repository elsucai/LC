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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
		if(!l1)
			return l2;
		if(!l2)
			return l1;
		ListNode* head, *pre, *p, *q;
		if(l1->val < l2->val){
			head = pre = l1;
			p = pre->next;
			q = l2;
		}
		else{
			head = pre = l2;
			p = pre->next;
			q = l1;
		}

		while(p && q){
			if(p->val > q->val)
				swap(p, q);
			pre->next = p;
			pre = p;
			p = p->next;
		}
		pre->next = q;
		return head;
    }
};
