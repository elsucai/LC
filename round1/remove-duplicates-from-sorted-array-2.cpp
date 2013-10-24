class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
      
		// at most twice
		
		if(n <= 1)
            return n;
        int s, e, len;
        len = 1;
		int d = 1;
        for(s = e = 1; e < n; e++){
            if(A[e] != A[e-1]){
                A[s] = A[e];
				d = 1;
                len++;
                s++;
            }
			else{
				if(d < 2){
					A[s] = A[e];
					d++;
					len++;
					s++;
				}
			}
        }
        return len;
        
    }
};
