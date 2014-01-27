class Solution {
public:
    int searchInsert(int A[], int n, int target) {
		if(n <= 0)
			return 0;
		int s = 0;
		int e = n-1;
		int m;
		while(s <= e){
			m = s + (e-s)/2;
			if(A[m] == target)
				return m;
			if(A[m] < target)
				s = m+1;
			else
				e = m-1;
		}
		return s;
    }
};
