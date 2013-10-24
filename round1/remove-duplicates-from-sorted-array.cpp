class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n <= 1)
            return n;
        int s, e, len;
        len = 1;
        for(s = e = 1; e < n; e++){
            if(A[e] != A[e-1]){
                A[s] = A[e];
                len++;
                s++;
            }
        }
        return len;
        
    }
};
