/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
		if(!head)
			return head;

		unordered_map<RandomListNode*, RandomListNode*> hm;
		RandomListNode *newhead, *p, *q, *pn, *qn, *pr, *qr;
		newhead = p = q = pn = qn = pr = qr = NULL;
	
		newhead = new RandomListNode(head->label);
		hm[head] = newhead;
		
		for(p = head; p != NULL; p = p->next){
			// creat a copy of p
			if(hm.find(p) == hm.end()){
				q = new RandomListNode(p->label);
				hm[p] = q;
			}
			else
				q = hm[p];
			
			// fill next
			if(p->next){
				// create next
				pn = p->next;
				if(hm.find(pn) == hm.end()){
					qn = new RandomListNode(pn->label);
					hm[pn] = qn;
				}
				else
					qn = hm[pn];
				
				q->next = qn;
			}
			
			// fill random
			if(p->random){
				// create next
				pr = p->random;
				if(hm.find(pr) == hm.end()){
					qr = new RandomListNode(pr->label);
					hm[pr] = qr;
				}
				else
					qr = hm[pr];
				
				q->random = qr;
			}
		}
		
		return newhead;
    }
};
