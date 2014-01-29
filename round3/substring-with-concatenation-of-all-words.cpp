class Solution {
public:
	bool isvalid(unordered_map<string, int> &hm, unordered_map<string, int> &local, string &s, int ws, int len, int x){
		string sub;
		local.clear();
		for(int i = x; i <= x+len-ws; i += ws){
			sub = s.substr(i, ws);
			if(hm.find(sub) == hm.end())
				return false;
			if(local[sub]++);
			if(local[sub] > hm[sub])
				return false;
		}
		return true;
	}

    vector<int> findSubstring(string S, vector<string> &L) {
		vector<int> ret;
		unordered_map<string, int> hm;
		unordered_map<string, int> local;
		if(L.empty())
			return ret;
		int ws = L[0].size();
		int len = ws*L.size();
		int s = 0;
		int e = S.size()-len;

		for(int i = 0; i < L.size(); i++)
			hm[L[i]]++;

		for(int i = s; i <= e; i++){
			if(isvalid(hm, local, S, ws, len, i))
				ret.push_back(i);
		}
		return ret;
    }
};
