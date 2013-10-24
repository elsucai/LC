class Solution {
public:

	void insert(vector< vector<int> > &ret, vector<int> &candidates, int* chosen, int end){
		vector<int> tmp;
		for(int i = 0; i <= end; i++){
			for(int j = 1; j <= chosen[i]; j++)
				tmp.push_back(candidates[i]);
		}
		ret.push_back(tmp);
	}
	
	void helper(vector< vector<int> > &ret, vector<int> &candidates, int* chosen, int* freq, int start, int end, int target){
		if(target == 0){
			// insert results
			insert(ret, candidates, chosen, start-1);
			return;
		}
		if(target < 0)
			return;
		if(start > end)
			return;

		//choose current element
		for(int i = freq[start]; i >= 0; i--){
			chosen[start] = i;
			helper(ret, candidates, chosen, freq, start+1, end, target-candidates[start]*i);
		}
	}

    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		vector< vector<int> > ret;
		if(target <= 0 || candidates.empty())
			return ret;
		int size = candidates.size();
		int* chosen = new int[size];
		int* freq = new int[size];
		
		sort(candidates.begin(), candidates.end());
		for(int i = 0; i < size; i++){
			chosen[i] = 0;
			freq[i] = target/candidates[i];
		}


		helper(ret, candidates, chosen, freq, 0, size-1, target);

		delete[] chosen;
		delete[] freq;
    }
};
