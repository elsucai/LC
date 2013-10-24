class Solution {
public:
    int maxSubArray(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

		int gmax = INT_MIN;
		int dp = 0;

		for(int i = 0; i < n; i++){
			dp = max(A[i], dp+A[i]);
			if(gmax < dp)
				gmax = dp;
		}
		return gmax;
    }
};
