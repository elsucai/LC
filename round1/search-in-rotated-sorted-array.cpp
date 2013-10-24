class Solution {
public:
    int search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

		if(n <= 0)
			return -1;
		int s = 0;
		int e = n-1;
		int m;
		while(s <= e){
			m = s + (e - s)/2;
			if(A[m] == target)
				return m;
			if(A[s] <= A[m]){
				if(target >= A[s] && target < A[m])
					e = m-1;
				else
					s = m+1;
			}
			else{
				if(A[m] < target && target <= A[e])
					s = m+1;
				else
					e = m-1;
			}
		}
		return -1;
    }
};