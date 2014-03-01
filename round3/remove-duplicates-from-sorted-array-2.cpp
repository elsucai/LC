class Solution {
public:
    int removeDuplicates(int A[], int n) {
		if(n <= 2)
			return n;
		int s, e;
		for(s = e = 2; e < n; e++){
			if(A[e] != A[s-2])
				A[s++] = A[e];
		}
		return s;
		/*
		int s, e, cnt;

		for(s = e = 1, cnt = 1; e < n; ){
			for(; e < n && A[e] == A[e-1] && cnt == 2; e++)
				;
			if(e == n)
				return s;
			if(A[e] != A[e-1]){
				A[s++] = A[e++];
				cnt = 1;
			}
			else{
				A[s++] = A[e++];
				cnt++;
			}
		}
		return s;
		*/
    }
};
