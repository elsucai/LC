class Solution {
public:

	void insert(vector<string> &ret, int* D, int end){
		string s = "";
		for(int i = 0; i <= end; i++){
			if(D[i] == 0)
				s += "(";
			else if(D[i] == 1)
				s += ")";
			else
				s += "#";
		}
		ret.push_back(s);
	}

	void helper(vector<string> &ret, int* D, int s, int e, int left, int right){
		if(s > e){
			if(left == 0 && right == 0)
				insert(ret, D, e);
			return;
		}
		if(left > right || right <= 0)
			return;
		//set s to left
		D[s] = 0;	//left
		helper(ret, D, s+1, e, left-1, right);
		//set s to right
		D[s] = 1;
		helper(ret, D, s+1, e, left, right-1);
		D[s] = -1;
	}


    vector<string> generateParenthesis(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

		vector<string> ret;

		if(n <= 0)
			return ret;   
		int size = 2*n;
		int* D = new int[size];
		for(int i = 0; i < size; i++)
				D[i] = -1;
		helper(ret, D, 0, size-1, n, n);
		delete[] D;

		return ret;
	}
};
