class Solution {
public:
	void helper(vector<vector<int> > &ret, vector<int> &one, vector<int> &a, vector<int> &freq, int s, int e){
		if(s > e){
			ret.push_back(one);
			return;
		}
		for(int i = 1; i <= freq[s]; i++)
			one.push_back(a[s]);
		for(int i = 1; i <= freq[s]; i++){
			helper(ret, one, a, freq, s+1, e);
			one.pop_back();
		}
		helper(ret, one, a, freq, s+1, e);
	}

    vector<vector<int> > subsetsWithDup(vector<int> &S) {
		vector<vector<int> > ret;
		vector<int> one;
		map<int, int> hm;
		map<int, int>::iterator it;
		for(int i = 0; i < S.size(); i++)
			hm[S[i]]++;
		vector<int> a;
		vector<int> freq;
		for(it = hm.begin(); it != hm.end(); it++){
			a.push_back(it->first);
			freq.push_back(it->second);
		}

		helper(ret, one, a, freq, 0, a.size()-1);
		return ret;
    }
};
