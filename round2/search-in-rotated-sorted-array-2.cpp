class Solution {
public:
	bool helper(int A[], int s, int e, int target){
		if(s > e)
			return false;
		int m = s + (e-s)/2;
		if(A[m] == target)
			return true;
		if(A[m] > A[s]){
			// m must lie in the left half
			if(target >= A[s] && target < A[m])
				return helper(A, s, m-1, target);
			return helper(A, m+1, e, target);
		}
		else if(A[m] < A[e]){
			// m must lie in the right half
			if(target > A[m] && target <= A[e])
				return helper(A, m+1, e, target);
			return helper(A, s, m-1, target);
		}
		else{
			bool l = helper(A, s, m-1, target);
			if(l)
				return l;
			bool r = helper(A, m+1, e, target);
				return r;
		}
	}

    bool search(int A[], int n, int target) {
		return	helper(A, 0, n-1, target);
    }
};
