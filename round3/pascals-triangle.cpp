class Solution {
public:
	void insert_row(vector<vector<int> > &ret){
		int n = ret.back().size();
		int stop_index = n/2;
		int next_n = n+1;
		vector<int> row(next_n, 1);
		for(int i = 1; i <= stop_index; i++){
			row[i] = ret.back()[i-1]+ret.back()[i];
		}
		// now fill the right half -- symmetric
		for(int i = stop_index+1; i < next_n-1; i++){
			row[i] = row[next_n-1-i];
		}
		ret.push_back(row);
	}

    vector<vector<int> > generate(int numRows) {
		vector<vector<int> > ret;
		if(numRows <= 0)
			return ret;
		ret.push_back(vector<int>(1, 1));
		if(numRows == 1)
			return ret;
		ret.push_back(vector<int>(2, 1));
		if(numRows == 2)
			return ret;

		// n >= 3
		for(int i = 3; i <= numRows; i++)
			insert_row(ret);
		return ret;
    }
};
