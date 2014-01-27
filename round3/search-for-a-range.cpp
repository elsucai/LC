class Solution {
public:
	int find_index(int A[], int s, int e, int target, bool leftmost){
		int m, candidate;
		candidate = -1;
		while(s <= e){
			m = s + (e-s)/2;
			if(A[m] == target){
				candidate = m;
				if(leftmost)
					e = m-1;
				else
					s = m+1;
			}
			else if(A[m] < target){
				s = m+1;
			}
			else
				e = m-1;
		}
		return candidate;
	}

    vector<int> searchRange(int A[], int n, int target) {
		vector<int> ret(2, -1);
		if(n <= 0)
			return ret;
		ret[0] = find_index(A, 0, n-1, target, true);
		if(ret[0] == -1)
			return ret;
		ret[1] = find_index(A, 0, n-1, target, false);
		return ret;
    }
};
