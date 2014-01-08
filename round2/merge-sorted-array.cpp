class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
		if(n <= 0)
			return;
		int i, j, cur;
		for(cur = m+n-1, i = m-1, j = n-1; i >= 0 && j >= 0; cur--){
			if(A[i] > B[j])
				A[cur] = A[i--];
			else
				A[cur] = B[j--];
		}
		while(j >= 0){
			A[cur--] = B[j--];
		}
    }
};
