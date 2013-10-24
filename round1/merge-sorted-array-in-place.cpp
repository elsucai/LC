class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		// merge sorted array B to A, in place
		// A is sorted too, and has enough space
		
		if(n == 0)
			return;
		
		int end = m + n - 1;
		int i = m - 1;
		int j = n - 1;
		
		while(i >= 0 && j >= 0){
			if(A[i] > B[j]){
				A[end--] = A[i--];
			}
			else{
				A[end--] = B[j--];
			}
		}
		while(j >= 0){
			A[end--] = B[j--];
		}
    }
};