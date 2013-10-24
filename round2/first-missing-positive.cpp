class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
        for(int i = 0; i < n; i++){
            while(A[i] <= n && A[i] >= 1 && A[i] != i+1 && A[i] != A[A[i]-1]){
                swap(A[i], A[A[i]-1]);
            }
        }
        
        for(int i = 0; i < n; i++){
            if(A[i] != i+1)
                return i+1;
        }
        
        return n+1;
    }
};
