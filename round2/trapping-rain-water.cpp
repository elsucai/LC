class Solution {
public:
    int trap(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.

		if(n <= 1)
			return 0;
			
		vector<int> leftmax(n+1, -1);
		vector<int> rightmax(n+1, -1);
		
		leftmax[0] = A[0];
		rightmax[n-1] = A[n-1];
		
		for(int i = 1; i < n; i++){
			if(A[i] > leftmax[i-1])
				leftmax[i] = A[i];
			else
				leftmax[i] = leftmax[i-1];
		}
		
		for(int i = n-2; i >= 0; i--){
			if(A[i] > rightmax[i+1])
				rightmax[i] = A[i];
			else
				rightmax[i] = rightmax[i+1];
		}
		
		int sum = 0;
		for(int i = 0; i < n; i++){
			sum += min(leftmax[i], rightmax[i]) - A[i];
		}
		return sum;
    }
};