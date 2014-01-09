class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
		vector<vector<int> >ret(n, vector<int>(n, 0));
		int rs, re, cs, ce;
		rs = cs = 0;
		re = ce = n-1;
		int val = 1;
		
		int i, j;
		while(rs <= re && cs <= ce){
			// special case
			if(rs == re || cs == ce){
				for(i = rs; i <= re; i++){
					for(j = cs; j <= ce; j++){
						ret[i][j] = val++;
					}
				}
				return ret;
			}
			// fill edges
			for(j = cs; j <= ce; j++)
				ret[rs][j] = val++;
			for(i = rs+1; i <= re; i++)
				ret[i][ce] = val++;
			for(j = ce-1; j >= cs; j--)
				ret[re][j] = val++;
			for(i = re-1; i > rs; i--)
				ret[i][cs] = val++;

			rs++;
			re--;
			cs++;
			ce--;
		}
		return ret;
    }
};
