class Solution {
public:

	int minCut(string s) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function

		if(s.empty())
			return 0;

		int size = s.size();
		int i, j;
		vector<vector<bool> > is_palindrome(size, vector<bool>(size, false));

		for(i = 0; i < size; i++)
			is_palindrome[i][i] = true;

		for(i = size-2; i >= 0; i--){	
			is_palindrome[i][i+1] = (s[i] == s[i+1]);
			for(j = i+2; j < size; j++){
				is_palindrome[i][j] = is_palindrome[i+1][j-1] && (s[i] == s[j]);
			}
		}

		vector<int> D(size+1, 0);
		D[size] = -1;
		// D[i] is the minimum number of cuts to make the string
		// s[i:] a groups of palindrome substringsfor(int i = size-2; i >= 0; i--){
		
		int min = INT_MAX;
		int cur_min;
		for(int i = size-1; i >= 0; i--){
			min = INT_MAX;
			for(int j = i; j < size; j++){
				if(min == 0)
					break;
				if(is_palindrome[i][j]){
					cur_min = 1 + D[j+1];
					if(min > cur_min)
						min = cur_min;
				}
			}
			D[i] = min;
		}

		// return D[0]
		return D[0];
	}
};
