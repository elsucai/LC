class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> ret;
    	if(matrix.empty())
			return ret;
		int rs, re, cs, ce;
		rs = cs = 0;
		re = matrix.size()-1;
		ce = matrix[0].size()-1;
		
		int i,j;
		
		while(rs <= re && cs <= ce){
			if(rs == re || cs == ce){
				for(i = rs; i <= re; i++){
					for(j = cs; j <= ce; j++){
						ret.push_back(matrix[i][j]);
					}
				}
				return ret;
			}
			// print edges
			for(j = cs; j <= ce; j++){
				ret.push_back(matrix[rs][j]);
			}
			for(i = rs+1; i <= re; i++){
				ret.push_back(matrix[i][ce]);
			}
			for(j = ce-1; j >= cs; j--){
				ret.push_back(matrix[re][j]);
			}
			for(i = re-1; i > rs; i--){
				ret.push_back(matrix[i][cs]);
			}
			
			// inner matrix
			rs++;
			re--;
			cs++;
			ce--;
		}
		return ret;
    }
};