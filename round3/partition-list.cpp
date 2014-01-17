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
		if(!head || !head->next)
			return head;
		ListNode* lh, *rh, *pl, *pr, *cur;
		lh = new ListNode(0);
		rh = new ListNode(0);
		pl = lh;
		pr = rh;
		int val;
		for(cur = head; cur; cur = cur->next){
			val = cur->val;
			if(val < x){
				pl->next = cur;
				pl = cur;
			}
			else{
				pr->next = cur;
				pr = cur;
			}
		}
		pl->next = rh->next;
		pr->next = NULL;
		return lh->next;
    }
};
