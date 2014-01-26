class Solution {
public:
    int removeElement(int A[], int n, int elem) {
		int s, e;
		for(s = 0, e = n-1; s <= e; ){
			if(A[s] != elem)
				s++;
			else{
				for(; e >= s && A[e] == elem; e--)
					;
				if(e < s)
					return s;
				swap(A[s], A[e]);
				s++;
			}
		}
		return s;
    }
};
