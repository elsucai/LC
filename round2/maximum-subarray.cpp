class Solution {
public:
    int maxSubArray(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
        int maxsum = INT_MIN;
        int d = 0;
        for(int i = 0; i < n; i++){
            d = max(A[i], A[i]+ d);
            maxsum = max(maxsum, d);
        }
        
        return maxsum;
    }
};
