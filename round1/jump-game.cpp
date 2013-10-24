class Solution {
public:
    bool canJump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		if(n <= 0)
			return false;
		if(n == 1)
			return true;

		vector<bool> D (n, false);
		D[n-1] = true;
		int closest_true = n-1;
		
		for(int i = n-2; i >= 0; i--){
			if(i + A[i] >= closest_true){
				D[i] = true;
				closest_true = i;
			}
		}
		
		return D[0];
    }
};
