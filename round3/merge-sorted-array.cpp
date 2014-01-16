class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
		if(n == 0)
			return;
		int i, j, e;
		e = m+n-1;
		for(i = m-1, j = n-1; i >= 0 && j >= 0; e--){
			if(A[i] > B[j]){
				A[e] = A[i--];
			}
			else{
				A[e] = B[j--];
			}
		}
		while(j >= 0){
			A[e--] = B[j--];
		}
    }
};
