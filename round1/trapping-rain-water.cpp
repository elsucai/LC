class Solution {
public:
    int trap(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n <= 2)
			return 0;
		vector<int> leftmax(n, 0);
		leftmax[0] = A[0];
		
		vector<int> rightmax(n, 0);
		rightmax[n-1] = A[n-1];
		
		int i;
		for(i = 1; i < n; i++)
			leftmax[i] = max(leftmax[i-1], A[i]);
		for(i = n-2; i >= 0; i--)
			rightmax[i] = max(rightmax[i+1], A[i]);
		
		int sum = 0;
		
		for(i = 0; i < n; i++){
			sum += min(leftmax[i], rightmax[i]) - A[i];
		}
	
		return sum;
    }
};