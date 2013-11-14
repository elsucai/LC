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
    ListNode *insertionSortList(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(!head || !head->next)
			return head;
		ListNode *p, *pre, *cur;
		pre = head;
		cur = head->next;
		while(cur){
			for(p = head; p->next->val < cur->val; p = p->next)
				;
			if(head->val > cur->val){
				pre->next = cur->next;
				cur->next = head;
				head = cur;
			}
			else if(p != pre){
				pre->next = cur->next;
				cur->next = p->next;
				p->next = cur;
			}
			else{
				pre = cur;
			}
			cur = pre->next;
		}
		return head;
    }
};