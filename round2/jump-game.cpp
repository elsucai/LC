class Solution {
public:
    bool canJump(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.

		if(n <= 1)
			return true;
		int smallest_index_of_true = n-1;
		bool d = false;

		for(int i = n-2; i >= 0; i--){
			if(i+A[i] >= smallest_index_of_true){
				d = true;
				smallest_index_of_true = i;
			}
			else
				d = false;
		}

		return d;
    }
};
