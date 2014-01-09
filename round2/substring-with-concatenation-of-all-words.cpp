class Solution {
public:
	bool valid(string &str, unordered_map<string, int> &hm, unordered_map<string, int> &local, int wsize, int len, int s){
		int i;
		string cur;
		local.clear();
		for(i = s; i <= s+len-wsize; i += wsize){
			cur = str.substr(i, wsize);
			if(hm.find(cur) == hm.end())
				return false;
			local[cur]++;
			if(local[cur] > hm[cur])
				return false;
		}
		return true;
	}


    vector<int> findSubstring(string S, vector<string> &L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		vector<int> ret;
		int len = L.size() * L[0].size();
		if(S.size() < len)
			return ret;

		unordered_map<string, int> hm;
		unordered_map<string, int> local;
		
		for(int i = 0; i < L.size(); i++)
			hm[L[i]]++;

		int s;
		for(s = 0; s <= S.size()-len; s++){
			if(valid(S, hm, local, L[0].size(), len, s))
				ret.push_back(s);
		}
		return ret;
    }
};
