class Solution {
public:
	bool helper(int A[], int target, int s, int e){
		int m;
		while(s <= e){
			m = s + (e - s)/2;
			if(A[m] == target)
				return true;
			if(A[s] < A[m]){
				if(A[s] <= target && target < A[m]){
					e = m-1;
				}
				else
					s = m+1;
			}
			else if(A[s] > A[m]){
				if(A[m] < target && target <= A[e]){
					s = m+1;
				}
				else{
					e = m-1;
				}
			}
			else{
				// A[s] == A[m]
				// hard to say which part A[m] belongs to
				return helper(A, target, s, m-1) || helper(A, target, m+1, e);
			}
		}
		return false;
	}
	
    bool search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		if(n <= 0)
			return false;
		return helper(A, target, 0, n-1);
    }
};