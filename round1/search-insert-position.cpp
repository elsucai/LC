class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
    	if(n <= 0)
			return 0;
		int s,e,m;
		for(s = 0, e = n-1; s <= e; ){
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