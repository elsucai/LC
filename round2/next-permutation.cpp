class Solution {
public:
	void revert(vector<int> &num, int s, int e){
		while(s < e){
			swap(num[s], num[e]);
			s++;
			e--;
		}
	}
	
	int find_target(vector<int> &num, int s, int e, int val){
		// binary search, num[s--e] is non increasing order
		// find last element that is greater than val
		int m, candidate;
		candidate = -1;
		while(s <= e){
			m = s + (e - s)/2;
			if(num[m] > val){
				candidate = m;
				s = m+1;
			}
			else{
				e = m-1;
			}
		}
		/*
		if(candidate == -1){
			candidate = e;
		}
		*/
		return candidate;
	}
	
    void nextPermutation(vector<int> &num) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
		int size = num.size();
		if(size <= 1)
			return;
		int replace;
		for(replace = size-2; replace >= 0; replace--){
			if(num[replace] < num[replace+1])
				break;
		}
		if(replace < 0){
			revert(num, 0, size-1);
			return;
		}
		
		int target = find_target(num, replace+1, size-1, num[replace]);
		swap(num[target], num[replace]);
		revert(num, replace+1, size-1);
    }
};