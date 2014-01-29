class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
		vector<int> ret;
		if(matrix.empty() || matrix[0].empty())
			return ret;
		int m = matrix.size();
		int n = matrix[0].size();
		int rs, re, cs, ce, i, j;
		rs = cs = 0;
		re = m-1;
		ce = n-1;

		while(rs < re && cs < ce){
			for(j = cs; j <= ce; j++)
				ret.push_back(matrix[rs][j]);
			for(i = rs+1; i <= re; i++)
				ret.push_back(matrix[i][ce]);
			for(j = ce-1; j >= cs; j--)
				ret.push_back(matrix[re][j]);
			for(i = re-1; i >= rs+1; i--)
				ret.push_back(matrix[i][cs]);
			rs++;
			re--;
			cs++;
			ce--;
		}
		for(i = rs; i <= re; i++){
			for(j = cs; j <= ce; j++)
				ret.push_back(matrix[i][j]);
		}
		return ret;
    }
};
