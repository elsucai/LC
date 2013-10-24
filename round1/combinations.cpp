class Solution {
public:
	// return all combinations of n choose k
	
	void insert(vector<vector<int>>& ret, bool* flag, int end){
		if(!flag || end < 1)
			return;
		vector<int> tmp;

		for(int i = 1; i <= end; i++){
			if(flag[i]){
				tmp.push_back(i);
			}
		}
		ret.push_back(tmp);
	}

	void helper(vector<vector<int>>& ret, bool* flag, int start, int end, int r){
		if(r == 0){
			insert(ret, flag, end);
			return;
		}
		if(r < 0 || start > end)
			return;

		// include current element
		flag[start] = true;
		helper(ret, flag, start+1, end, r-1);
		// not include current element
		flag[start] = false;
		helper(ret, flag, start+1, end, r);
	}

    vector<vector<int> > combine(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		vector<vector<int>> ret;
		if(n < k || n <= 0)
			return ret;
		
		bool* flag = new bool[n+1];
		for(int i = 0; i <= n; i++)
			flag[i] = false;

		helper(ret, flag, 1, n, k);

		delete[] flag;
    }
};
