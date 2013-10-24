class Solution {
public:

	vector<vector<int> > helper(vector<int> &num, int s, int e){
		vector<vector<int> > ret;
		vector<vector<int> > sub;
		vector<int> tmp;
		if(s > e)
			return ret;
		if(s == e){
			tmp.clear();
			tmp.push_back(num[s]);
			ret.push_back(tmp);
			return ret;
		}
		
		sub = helper(num, s+1, e);
		int d = e-s;
		int val = num[s];
		
		for(int i = 0; i < sub.size(); i++){
			for(int j = 0; j <= d; j++){
				tmp = sub[i];
				tmp.insert(tmp.begin()+j, val);
				ret.push_back(tmp);
			}
		}
		return ret;
	}

    vector<vector<int> > permute(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
	// return permute [1,n), for each element in the returned vector
	// insert num[0] to all possible positions

		vector<vector<int> > ret;
		if(num.empty())
			return ret;
		if(num.size() == 1){
			ret.push_back(num);
			return ret;
		}
		
		return helper(num, 0, num.size()-1);
    }
};
