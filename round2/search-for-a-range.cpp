class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
		int s, e, m;
		int left = n;
		int right = -1;
		vector<int> ret;
		
		//search left most
		s = 0;
		e = n-1;
		
		while(s <= e){
			m = s + (e - s)/2;
			if(A[m] == target){
				if(left > m){
					left = m;
					e = m-1;
				}
			}
			else if(A[m] > target)
				e = m-1;
			else
				s = m+1;
		}
		
		//search right most
		s = 0;
		e = n-1;
		
		while(s <= e){
			m = s + (e - s)/2;
			if(A[m] == target){
				if(right < m){
					right = m;
					s = m+1;
				}
			}
			else if(A[m] > target)
				e = m-1;
			else
				s = m+1;
		}
		
		if(left == n){
			ret.push_back(-1);
			ret.push_back(-1);
			return ret;
		}
		ret.push_back(left);
		ret.push_back(right);
		
		return ret;
    }
};