class Solution {
public:
    int search(int A[], int n, int target) {
		int i, j;
		i = 0;
		j = n-1;
		int m;
		while(i <= j){
			m = i + (j - i)/2;
			if(A[m] == target)
				return m;
			// check m's place
			if(A[m] >= A[i]){
				// m lies in left half
				if(target >= A[i] && target < A[m]){
					j = m-1;
				}
				else
					i = m+1;
			}
			else{
				if(target > A[m] && target <= A[j]){
					i = m+1;
				}
				else
					j = m-1;
			}
		}
		return -1;
    }
};
