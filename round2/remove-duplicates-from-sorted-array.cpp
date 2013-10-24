class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(n <= 1)
            return n;
        int s, e;
        for(s = e = 1; e < n; ){
            if(A[e] != A[e-1]){
                A[s] = A[e];
                s++;
                e++;
            }
            else{
                e++;
            }
        }
        
        return s;
    }
};