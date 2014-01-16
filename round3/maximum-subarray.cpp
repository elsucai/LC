class Solution {
public:
    int maxSubArray(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
		if(n == 0)
			return 0;
		if(n == 1)
			return A[0];
		int i, global_max, pre_max;
		pre_max = global_max = A[0];
		for(i = 1; i < n; i++){
			pre_max = max(A[i], A[i]+pre_max);
			global_max = max(global_max, pre_max);
		}
		return global_max;
    }
};
