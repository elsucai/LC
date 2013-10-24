class Solution {
public:
    void helper(int &cnt, int n, int found_rows, int ld, int col, int rd){
		// http://www.cl.cam.ac.uk/~mr10/backtrk.pdf
		if(found_rows == n){
			cnt++;
			return;
		}
		int mask = (1<<n)-1;	// n 1's in mask
		int valid, bit;
		// bit 1 int col means this col has been occupied
		// bit 1 in ld / rd means in current row, these positions are being attacked
		
		// for current row, check which columns are valid
		valid = ~(ld | col | rd) & mask;
		while(valid){
			// extract bit 1 one at a time, and call recursively
			bit = valid & -valid;
			valid ^= bit;	// clear least significant bit from valid
			helper(cnt, n, found_rows+1, (ld | bit)<<1, col | bit, (rd | bit)>>1);
		}
	}

    int totalNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		
		int cnt = 0;
		helper(cnt, n, 0, 0, 0, 0);
		return cnt;
    }
};