class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
		int s, e, m;
		s = 0;
		e = n-1;
		while(s <= e){
			m = s + (e - s)/2;
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