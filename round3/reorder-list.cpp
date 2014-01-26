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
	ListNode* reverse(ListNode* head){
		ListNode* cur, *next;
		ListNode* pre = NULL;
		if(!head || !head->next)
			return head;
		for(cur = head; cur; ){
			next = cur->next;
			cur->next = pre;
			pre = cur;
			cur = next;
		}
		return pre;
	}

	ListNode* interleave(ListNode* p, ListNode* q){
		if(!p)
			return q;
		if(!q)
			return p;
		ListNode* head, *pre;
		head = pre = p;
		p = p->next;
		swap(p, q);
		while(p){
			pre->next = p;
			pre = p;
			p = p->next;
			swap(p, q);
		}
		pre->next = q;
		return head;
	}

    void reorderList(ListNode *head) {
		if(!head || !head->next || !head->next->next)
			return;
		ListNode* slow, *fast;
		for(slow = fast = head; fast->next && fast->next->next; slow = slow->next, fast = fast->next->next)
			;
		ListNode* right = reverse(slow->next);
		slow->next = NULL;
		head = interleave(head, right);
    }
};
