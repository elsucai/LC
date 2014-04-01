class Solution {
	public:
		void generate_path(string &s, vector<bool> &D, vector<string> &ret, unordered_map<int, unordered_set<int> > &valid, vector<string> &one, int start, int end){
			if(start > end){
				string x = "";
				for(int i = 0; i < one.size(); i++){
					x += one[i]+" ";
				}
				x.pop_back();
				ret.push_back(x);
				return;
			}
			if(!D[start])
				return;
			unordered_set<int>::iterator it;
			for(it = valid[start].begin(); it != valid[start].end(); it++){
				one.push_back(s.substr(start, 1 - start + *it));
				generate_path(s, D, ret, valid, one, 1 + *it, end);
				one.pop_back();
			}
		}

		vector<string> wordBreak(string s, unordered_set<string> &dict) {
			int n = s.size();
			vector<string> ret;
			unordered_map<int, unordered_set<int> > valid;
			if(s.empty())
				return ret;
			vector<bool> D(n+1, false);
			D[n] = true;
			for(int start = n-1; start >= 0; start--){
				for(int end = start; end <= n-1; end++){
					if(dict.find(s.substr(start, end-start+1)) != dict.end() && D[end+1]){
						D[start] = true;
						if(valid.find(start) == valid.end())
							valid[start] = unordered_set<int>();
						valid[start].insert(end);
					}
				}
			}
			vector<string> one;
			generate_path(s, D, ret, valid, one, 0, n-1);
			return ret;
		}
};
