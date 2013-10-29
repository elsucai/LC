class Solution {
public:
	void push_one_solution(vector<vector<string> > &ret, vector<int> &rows, int e){
		string one;
		int val;
		vector<string> tmp;
		for(int row = 0; row <= e; row++){
			one = "";
			val = rows[row];
			for(int col = 0; col <= e; col++){
				if(col == val)
					one += "Q";
				else
					one += ".";
			}
			tmp.push_back(one);
		}
		ret.push_back(tmp);
	}
	
	void pick_next_valid(vector<int> &rows, int s, int e, vector<bool> &col_flag, unordered_set<int> &sum, unordered_set<int> &diff){
		int x;
		if(rows[s] != -1){
			// unset markers
			col_flag[rows[s]] = false;
			sum.erase(s+rows[s]);
			diff.erase(s-rows[s]);
		}
		for(x = 1+rows[s]; x <= e; x++){
			if(col_flag[x] || sum.find(x+s) != sum.end() || diff.find(s-x) != diff.end())
				continue;
			// found the next valid x
			col_flag[x] = true;
			sum.insert(s+x);
			diff.insert(s-x);
			rows[s] = x;
			return;
		}
		rows[s] = -1;
	}

	void helper(vector<vector<string> > &ret, vector<int> &rows, int s, int e, vector<bool> &col_flag, unordered_set<int> &sum, unordered_set<int> &diff){
		if(s > e){
			push_one_solution(ret, rows, e);
			return;
		}
		while(1){
			pick_next_valid(rows, s, e, col_flag, sum, diff);
			if(rows[s] != -1){
				// next valid value exists
				helper(ret, rows, s+1, e, col_flag, sum, diff);
			}
			else
				return;
		}
	}
	
    vector<vector<string> > solveNQueens(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<vector<string> > ret;
		if(n == 0)
			return ret;
		vector<bool> col_flag(n, false);
		unordered_set<int> sum;
		unordered_set<int> diff;
		vector<int> rows(n, -1);
		helper(ret, rows, 0, n-1, col_flag, sum, diff);
		return ret;
    }
};