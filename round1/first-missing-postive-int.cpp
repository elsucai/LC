class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		/* if extra non-constant space is allowed
		* we can allocate an array of size n
		* note: the maximum possible first missing
		* positive int is n+1, an array of size n is enough (used as a hash table)
		* for elements x in A, put x to arr[x-1] if 1 <= x <= n
		* loop through arr[] to find first missing number
		
		* now , use A as arr
		*/
		
		for(int i = 0; i < n; ){
			if(A[i] <= n && A[i] >= 1 && A[A[i]-1] != A[i])
				swap(A[i], A[A[i]-1]);
			else
				i++;
		}
		
		//check
		for(int i = 0; i < n; i++){
			if(A[i] != i+1)
				return i+1;
		}
		return n+1;
    }
};