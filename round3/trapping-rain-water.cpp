class Solution {
public:
    int trap(int A[], int n) {
        vector<int> lm(n+2, 0);
        vector<int> rm(n+2, 0);
		for(int i = 1; i <= n; i++)
			lm[i] = max(A[i-1], lm[i-1]);
		for(int i = n; i >= 1; i--)
			rm[i] = max(A[i-1], rm[i+1]);

		int sum = 0;
		for(int i = 1; i <= n; i++){
			sum += min(lm[i], rm[i]) - A[i-1];
		}
		return sum;
    }
};
