class Solution {
public:
    int uniquePaths(int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

    	// compute (m+n-2 choose n-1)
		if(n > m)
			swap(m,n);

		long long ret = 1;
        int x = m+n-2;
		for(int i = 1; i <= n-1; i++){
			ret *= x--;
			ret /= i;
		}
		return ret;
    }
};
