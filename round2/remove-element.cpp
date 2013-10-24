class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int i,j;
		for(i = 0, j = n-1; i <= j; ){
			while(i <= j && A[i] != elem)
				i++;
			while(j >= i && A[j] == elem)
				j--;
			
			if(i < j){
				swap(A[i], A[j]);
				i++;
				j--;
			}
			else
				return i;
		}
		return i;
    }
};