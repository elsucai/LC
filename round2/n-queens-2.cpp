class Solution {
public:
	void helper(int cur, int n, int &cnt, int col, int lattack, int rattack){
		if(cur >= n){
			cnt++;
			return;
		}
		// lattack: positions being attacked from top left to bottom right diagnal
		// each bit 1 in valid means it is a valid position in current row
		int mask = (1<<n)-1;
		int valid = ~(col|lattack|rattack) & mask;
	//    int valid = (col|lattack|rattack)^mask;

		int lsb;
		while(valid){
			// find which position to choose (lsb), and update attack
			lsb = valid & (-valid);
			//clear that bit
			valid ^= lsb;
			helper(cur+1, n, cnt, col|lsb, (lattack|lsb)>>1, (rattack|lsb)<<1);
		}
	}

    int totalNQueens(int n) {
		if(n <= 1)
			return n;
		// bit 0 means free
		int lattack, rattack, col;
		lattack = rattack = col = 0;
		int cnt = 0;
		helper(0, n, cnt, col, lattack, rattack);	
		return cnt;
    }
};
