class Solution {
public:
	bool helper(int A[], int s, int e, int target){
		int m;
		if(s > e)
			return false;
		m = s +(e-s)/2;
		if(A[m] == target)
			return true;
		if(A[m] > A[s]){
			if(A[s] <= target && target <= A[m])
				return helper(A, s, m-1, target);
			return helper(A, m+1, e, target);
		}
		else if(A[m] < A[s]){
			if(A[m] <= target && target <= A[e])
				return helper(A, m+1, e, target);
			return helper(A, s, m-1, target);
		}
		else{
			if(helper(A, s, m-1, target))
				return true;
			return helper(A, m+1, e, target);
		}
	}

    bool search(int A[], int n, int target) {
		return helper(A, 0, n-1, target);		
    }
};
