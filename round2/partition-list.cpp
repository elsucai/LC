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
    ListNode *partition(ListNode *head, int x) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(!head)
			return head;
			
		ListNode* less, *greater, *p1, *p2, *p;
		less = new ListNode(0);
		greater = new ListNode(0);
		p1 = less;
		p2 = greater;
		
		for(p = head; p != NULL; p = p->next){
			if(p->val < x){
				p1->next = p;
				p1 = p;
			}
			else{
				p2->next = p;
				p2 = p;
			}
		}
		if(!less->next)
			return greater->next;
		if(!greater->next)
			return less->next;
			
		p1->next = greater->next;
		p2->next = NULL;
		
		return less->next;
    }
};