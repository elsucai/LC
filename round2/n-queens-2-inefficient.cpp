class Solution {
public:
	
	bool fill_cur(vector<int> &row, vector<bool> &col, unordered_set<int> &sum, unordered_set<int> &diff, int &cnt, int cur, int lastrow){
		int val = row[cur];
		int start = 0;
		if(val != -1){
			//need to clear current value
			start = val+1;
			col[val] = false;
			sum.erase(cur+val);
			diff.erase(cur-val);
		}
		for(; start <= lastrow; start++){
			if(!col[start] && sum.find(cur+start) == sum.end() && diff.find(cur-start) == diff.end()){
				row[cur] = start;
				col[start] = true;
				sum.insert(cur+start);
				diff.insert(cur-start);
				return true;
			}
		}
		row[cur] = -1;
		return false;
	}

	void helper(vector<int> &row, vector<bool> &col, unordered_set<int> &sum, unordered_set<int> &diff, int &cnt, int cur, int lastrow){
		if(cur > lastrow){
			cnt++;
			return;
		}
		
		while(fill_cur(row, col, sum, diff, cnt, cur, lastrow)){
			helper(row, col, sum, diff, cnt, cur+1, lastrow);
		}
	}

    int totalNQueens(int n) {
		if(n <= 1)
			return n;
		vector<int> row(n, -1);
		vector<bool> col(n, false);
		unordered_set<int> sum;
		unordered_set<int> diff;

		int cnt = 0;
		helper(row, col, sum, diff, cnt, 0, n-1);
		return cnt;
    }
};