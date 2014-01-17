class Solution {
public:
	void push_solution(vector<vector<string> > &ret, vector<int> &row){
		int n = row.size();
		vector<string> one;
		string line = "";
		for(int i = 0; i < n; i++)
			line += ".";
		for(int i = 0; i < n; i++)
			one.push_back(line);

		for(int i = 0; i < n; i++){
			one[i][row[i]] = 'Q';
		}
		ret.push_back(one);
	}

	bool find_next(vector<int> &row, vector<bool> &col_free, unordered_set<int> &sum, unordered_set<int> &diff, int s){
		int start = 0;
		int val;
		if(row[s] != -1){
			// clear this row first
			val = row[s];
			row[s] = -1;
			start = val+1;
			col_free[val] = true;
			sum.erase(s+val);
			diff.erase(s-val);
		}
		for(; start < row.size(); start++){
			if(col_free[start] && sum.find(s+start) == sum.end() && diff.find(s-start) == diff.end()){
				row[s] = start;
				col_free[start] = false;
				sum.insert(s+start);
				diff.insert(s-start);
				return true;
			}
		}
		return false;
	}

	void helper(vector<vector<string> > &ret, vector<int> &row, vector<bool> &col_free, unordered_set<int> &sum, unordered_set<int> &diff, int s, int e){
		if(s > e){
			push_solution(ret, row);
			return;
		}
		
		// fill row[s]
		while(find_next(row, col_free, sum, diff, s))
			helper(ret, row, col_free, sum, diff, s+1, e);
	}

    vector<vector<string> > solveNQueens(int n) {
		vector<vector<string> > ret;
		if(n <= 0)
			return ret;
		vector<int> row(n, -1);
		vector<bool> col_free(n, true);
		unordered_set<int> sum;
		unordered_set<int> diff;

		helper(ret, row, col_free, sum, diff, 0, n-1);
		return ret;
    }
};
