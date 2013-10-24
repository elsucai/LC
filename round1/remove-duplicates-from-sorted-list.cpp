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
    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

		if(!head || head->next == NULL)
			return head;

		//at least 2 elements in the list
		
		ListNode* s = head->next;
		ListNode* e = head->next;
		ListNode* pre_s = head;
		ListNode* pre_e = head;

		for(; e != NULL; e = e->next, pre_e = pre_e->next){
			if(e->val != pre_e->val){
				s->val = e->val;
				s = s->next;
				pre_s = pre_s->next;
			}
		}

		pre_s -> next = NULL;
		return head;
    }
};
