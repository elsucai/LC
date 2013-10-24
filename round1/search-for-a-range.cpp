class Solution {
public:

	int findleftmost(int A[], int n, int target, bool is_leftmost){
		if(n <= 0)
			return -1;
		int s = 0;
		int e = n-1;
		int m;
		int candidate;
		int cur_val;
		
		candidate = is_leftmost ? n : -1;
		while(s <= e){
			m = s + (e - s)/2;
			cur_val = A[m];
			if(cur_val == target){
				if(is_leftmost){
					if(candidate > m)
						candidate = m;
					e = m-1;
				}
				else{
					if(candidate < m)
						candidate = m;
					s = m+1;
				}
			}
			else if(cur_val < target){
				s = m+1;
			}
			else
				e = m-1;
		}
		
		if(candidate == -1 || candidate == n)
			return -1;
		return candidate;
	}
	
	
    vector<int> searchRange(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		
		vector<int> ret;
		if(n <= 0){
			ret.push_back(-1);
			ret.push_back(-1);
			return ret;
		}
		
		int left = findleftmost(A, n, target, true);
		int right = findleftmost(A, n, target, false);
		ret.push_back(left);
		ret.push_back(right);
		
		return ret;
    }
};