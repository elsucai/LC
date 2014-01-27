class Solution {
public:
    int search(int A[], int n, int target) {
		int s, e, m;
		s = 0;
		e = n-1;
		while(s <= e){
			m = s + (e-s)/2;
			if(A[m] == target)
				return m;
			if(A[s] <= A[m]){
				if(A[s] <= target && target <= A[m]){
					e = m-1;
				}
				else{
					s = m+1;
				}
			}
			else{
				if(A[m] <= target && target <= A[e]){
					s = m+1;
				}
				else
					e = m-1;
			}
		}
		return -1;
    }
};
