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
	
	ListNode* revert(ListNode* p){
		if(!p || !p->next)
			return p;
		ListNode* pre = NULL;
		ListNode* next;

		while(p){
			next = p->next;
			p->next = pre;
			pre = p;
			p = next;
		}
		return pre;
	}

	void interleave(ListNode* p1, ListNode* p2){
		if(!p1 || !p2)
			return;
		ListNode* next;
		while(p1){
			next = p1->next;
			p1->next = p2;
			p1 = p2;
			p2 = next;
		}
	}

    void reorderList(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.

		if(!head || !head->next || !head->next->next)
			return;
		ListNode* p1, *p2;
		ListNode* slow, *fast;
		slow = fast = head;
		p1 = head;

		while(fast->next && fast->next->next){
			slow = slow->next;
			fast = fast->next->next;
		}
		p2 = slow->next;
		slow->next = NULL;

		//revert p2, then interleave p1 and p2
		p2 = revert(p2);
		interleave(p1, p2);
    }
};
