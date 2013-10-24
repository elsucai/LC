class Solution {
public:
    vector<vector<int> > generate(int numRows)  {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		vector<vector<int> > ret;
		vector<int> row;
		vector<int> *tmp;
		if(numRows <= 0)
			return ret;
			
		row.push_back(1);
		ret.push_back(row);
		if(numRows == 1)
			return ret;
		
		row.clear();
		row.push_back(1);
		row.push_back(1);
		ret.push_back(row);
		if(numRows == 2)	
			return ret;
		
		int end;
		for(int i = 3; i <= numRows; i++){
			tmp = &(ret[ret.size()-1]);
			row.clear();
			row.push_back(1);
			for(int j = 0; j <= (*tmp).size()/2 - 1; j++){
				row.push_back((*tmp)[j]+(*tmp)[j+1]);
			}
			if(i % 2 == 0){
				// even
				end = row.size()-1;
			}
			else{
				end = row.size()-2;
			}
			for(int k = end; k >= 0; k--){
				row.push_back(row[k]);
			}
			ret.push_back(row);
		}
		return ret;
	}
};