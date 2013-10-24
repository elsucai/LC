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
	void compute(int x, int y, int& carry, int& remainder, ListNode* &p, ListNode* &head){
		int tmp = x + y + carry;
		carry = tmp/10;
		remainder = tmp%10;
		
		//insert remainder
		if(!p){
			p = new ListNode(remainder);
			head = p;
		}
		else{
			p->next = new ListNode(remainder);
			p = p->next;
		}
	}
	
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		if(!l1)
			return l2;
		if(!l2)
			return l1;
			
		int carry, remainder, tmp;
		ListNode*head, *p, *p1, *p2;
		p = head = NULL;
		carry = 0;
		for(p1 = l1, p2 = l2; p1 && p2; p1 = p1->next, p2 = p2->next){
			compute(p1->val, p2->val, carry, remainder, p, head);
		}
		while(p1){
			compute(p1->val, 0, carry, remainder, p, head);
			p1 = p1->next;
		}
		while(p2){
			compute(p2->val, 0, carry, remainder, p, head);
			p2 = p2->next;
		}
		if(carry){
			compute(0, 0, carry, remainder, p, head);
		}
		
		return head;
    }
};