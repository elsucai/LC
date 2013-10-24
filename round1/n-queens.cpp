class Solution {
public:

	int find_next(vector<int> &row, vector<bool> &col_free, set<int> &sum, set<int> &diff, int s, int e){
		int i, cursum, curdiff;
		// remove current value row[s] first 
		if(row[s] != -1){
			cursum = row[s] + s;
			curdiff = row[s] - s;
			col_free[row[s]] = true;
			sum.erase(cursum);
			diff.erase(curdiff);
		}
		
		for(i = 1+row[s]; i <= e; i++){
			//test i
			if(col_free[i] && sum.find(i+s) == sum.end() && diff.find(i-s) == diff.end()){
				row[s] = i;
				sum.insert(row[s] + s);
				diff.insert(row[s] - s);
				col_free[row[s]] = false;
				return i;
			}
		}
		row[s] = -1;
		return -1;
	}
	
	void insert_answer(vector<vector<string> > &ret, vector<int> &row){
		string base, tmp;
		base = tmp = "";
		vector<string> r;
		int size = row.size();
		for(int i = 0; i < size; i++)
			base += ".";
		for(int i = 0; i < size; i++){
			tmp = base;
			tmp[row[i]] = 'Q';
			r.push_back(tmp);
		}
		ret.push_back(r);
	}
	
	
	void helper(vector<vector<string> > &ret, vector<int> &row, vector<bool> &col_free, set<int> &sum, set<int> &diff, int s, int e){
		if(s > e){
			insert_answer(ret, row);
			return;
		}
		// set row[s]
		
		int cursum, curdiff, next;
		
		while(find_next(row, col_free, sum, diff, s, e) >= 0)
			helper(ret, row, col_free, sum, diff, s+1, e);
	}
	
	
    vector<vector<string> > solveNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		vector<vector<string> > ret;
		vector<string> tmp;
		if(n == 1){
			tmp.push_back("Q");
			ret.push_back(tmp);
			return ret;
		}
		else if(n <= 3){
			return ret;
		}
		else
			;
		
		vector<int> row(n, -1);
		vector<bool> col_free(n, true);
		set<int> sum;
		set<int> diff;
		
		helper(ret, row, col_free, sum, diff, 0, n-1);
		if(ret.empty()){
			tmp.push_back("");
			ret.push_back(tmp);
		}
		
		return ret;
    }
};