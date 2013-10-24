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
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		if(!l1)
			return l2;
		if(!l2)
			return l1;
			
		ListNode* head, *pre, *p1, *p2;
		p1 = l1;
		p2 = l2;
		if(l1->val < l2->val){
			head = pre = l1;
			p1 = p1->next;
		}
		else{
			head = pre = l2;
			p2 = p2->next;
		}
		
		while(p1 && p2){
			if(p1->val < p2->val){
				pre->next = p1;
				pre = pre->next;
				p1 = p1->next;
			}
			else{
				pre->next = p2;
				pre = pre->next;
				p2 = p2->next;
			}
		}
		if(p1)
			pre->next = p1;
		if(p2)
			pre->next = p2;
		
		return head;
    }
};