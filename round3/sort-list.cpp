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
	ListNode* merge(ListNode* p, ListNode* q){
		if(!p)
			return q;
		if(!q)
			return p;
		ListNode* head = new ListNode(0);
		ListNode* pre = head;
		while(p && q){
			if(p->val > q->val)
				swap(p, q);
			pre->next = p;
			pre = p;
			p = p->next;
		}
		pre->next = q;
		return head->next;
	}

    ListNode *sortList(ListNode *head) {
		if(!head || !head->next)
			return head;
		ListNode* slow, *fast, *remain;
		for(slow = fast = head; fast && fast->next && fast->next->next; slow = slow->next, fast = fast->next->next)
			;
		remain = slow->next;
		slow->next = NULL;
		head = sortList(head);
		remain = sortList(remain);
		return merge(head, remain);
    }
};
