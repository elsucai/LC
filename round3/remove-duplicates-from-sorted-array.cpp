class Solution {
public:
    int removeDuplicates(int A[], int n) {
		if(n <= 1)
			return n;
		int s, e;
		for(s = e = 1; e < n; ){
			for(; e < n && A[e] == A[e-1]; e++)
				;
			if(e == n)
				return s;
			A[s] = A[e];
			s++;
			e++;
		}
		return s;
    }
};
