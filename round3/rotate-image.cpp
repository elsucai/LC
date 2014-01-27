class Solution {
	public:
		void rotate(vector<vector<int> > &matrix) {
			if(matrix.empty() || matrix[0].empty())
				return;
			int rs, re, cs, ce;
			rs = cs = 0;
			re = matrix.size()-1;
			ce = matrix[0].size()-1;
			int ai, aj, bi, bj, ci, cj, di, dj;

			int step;
			while(rs < re){
				ai = bi = rs;
				ci = di = re;
				aj = dj = cs;
				bj = cj = ce;
				for(step = 0; step < re - rs; step++){
					swap(matrix[ai][aj+step], matrix[bi+step][bj]);
					swap(matrix[ai][aj+step], matrix[ci][cj-step]);
					swap(matrix[ai][aj+step], matrix[di-step][dj]);
				}
				rs++;
				re--;
				cs++;
				ce--;
			}
		}
};
