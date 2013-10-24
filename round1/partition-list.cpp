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
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

		if(!head)
			return NULL;
		ListNode* less, *greater, *p1, *p2, *p;
		p = head;
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
		p1->next = greater->next;
		p2->next = NULL;

		return less->next;
    }
};
