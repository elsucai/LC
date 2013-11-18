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
		
		ListNode* pre, *head;
		if(p->val < q->val){
			pre = head = p;
			p = p->next;
		}
		else{
			pre = head = q;
			q = q->next;
		}

		while(p && q){
			if(p->val < q->val){
				pre->next = p;
				pre = p;
				p = p->next;
			}
			else{
				pre->next = q;
				pre = q;
				q = q->next;
			}
		}

		if(p)
			pre->next = p;
		if(q)
			pre->next = q;
		return head;
	}

    ListNode *sortList(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
		
		if(!head || !head->next)
			return head;
		ListNode* slow, *fast;
		slow = head;
		fast = slow->next;
		while(fast){
			if(!fast->next || !fast->next->next)
				break;
			slow = slow->next;
			fast = fast->next->next;
		}

		fast = slow->next;
		slow->next = NULL;
		head = sortList(head);
		fast = sortList(fast);
		return merge(head, fast);
    }
};
