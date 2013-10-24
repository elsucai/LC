class Solution {
public:
		
	void get_allconcats(unordered_set<string> &allconcats, vector<string> &L, int s, int e){
		string concat = "";
		int i;
		if(s > e){
			for(i = 0; i < L.size(); i++)
				concat += L[i];
			allconcats.insert(concat);
			return;
		}
		
		for(i = 0; i < L.size(); i++){
			swap(L[0], L[i]);
			get_allconcats(allconcats, L, s+1, e);
			swap(L[0], L[i]);
		}
	}

    		
    vector<int> findSubstring(string S, vector<string> &L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

		vector<int> ret;
		if(L.empty()){
			for(int i = 0; i < S.size(); i++)
				ret.push_back(i);
			return ret;
		}

		int size, s, e;
		s = 0;
		e = L.size()-1;

		unordered_set<string> allconcats;
		get_allconcats(allconcats, L, 0, e);
		
		size = L.size() * L[0].size();
		for(s = 0, e = s + size - 1; e <= S.size(); s++, e++){
			if(allconcats.find(S.substr(s, size)) != allconcats.end())
				ret.push_back(s);
		}
		return ret;
    }
};
