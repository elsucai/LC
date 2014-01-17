class Solution {
public:
	void helper(int &cnt, int col, int la, int ra, cur, n){
		if(cur == n){
			cnt++;
			return;
		}
		int attack = col|la|ra;
		int valid = ~attack & ((1<<n)-1);
		while(valid){
			int lsb = valid & -valid;
			valid = valid^lsb;
			helper(cnt, col|lsb, (la|lsb)>>1, (ra|lsb)<<1, cur+1, n);
		}
	}

    int totalNQueens(int n) {
		if(n <= 1)
			return n;
		int cnt = 0;
		helper(cnt, 0, 0, 0, 0, n);
		return cnt;
    }
};
