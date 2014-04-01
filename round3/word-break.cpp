class Solution {
	public:
		bool wordBreak(string s, unordered_set<string> &dict) {
			int n = s.size();
			if(s.empty())
				return false;
			vector<bool> D(n+1, false);
			D[n] = true;
			for(int start = n-1; start >= 0; start--){
				for(int end = start; end <= n-1; end++){
					if(dict.find(s.substr(start, end-start+1)) != dict.end() && D[end+1]){
						D[start] = true;
						break;
					}
				}
			}
			return D[0];
		}
};
