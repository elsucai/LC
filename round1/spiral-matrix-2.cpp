class Solution {
public:
    void helper(vector<vector<int> > &ret, int rs, int re, int cs, int ce, int s, int e){
		if(rs > re || cs > ce)
			return;
		
		int i, j, val;
		val = s;
		while(rs <= re && cs <= ce){
			if(rs == re){
				ret[rs][cs] = val;
				return;
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
	}
	
	
    vector<vector<int> > generateMatrix(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		vector<vector<int> > ret(n, vector<int>(n, 0));
		if(n <= 0)
			return ret;
		if(n == 1){
			ret[0][0] = 1;
			return ret;
		}
		
		helper(ret, 0, n-1, 0, n-1, 1, n*n);
		return ret;
	}
};