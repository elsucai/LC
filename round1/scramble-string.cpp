class Solution {
public:

    bool helper(string &s1, int s1_s, int s1_e, string &s2, int s2_s, int s2_e, unordered_map<char, int> &hm){
		if(s1_e - s1_s != s2_e - s2_s)
			return false;
		if(s1_e == s1_s)
			return s1[s1_s] == s2[s2_s];
		
		bool rec;
		hm.clear();
		
		for(int i = s1_s; i <= s1_e; i++){
			if(hm.find(s1[i]) == hm.end())
				hm[s1[i]] = 1;
			else
				hm[s1[i]]++;
		}
		for(int i = s2_s; i <= s2_e; i++){
			if(hm.find(s2[i]) == hm.end() || hm[s2[i]] == 0)
				return false;
			hm[s2[i]]--;
		}
		
		int size = s1_e - s1_s + 1;
		for(int i = 0; i < size-1; i++){
			rec = helper(s1, s1_s, s1_s+i, s2, s2_s, s2_s+i, hm) && helper(s1, s1_s+i+1, s1_e, s2, s2_s+i+1, s2_e, hm);
			if(rec)
				return true;
			rec = helper(s1, s1_s, s1_s+i, s2, s2_e-i, s2_e, hm) && helper(s1, s1_s+i+1, s1_e, s2, s2_s, s2_e-i-1, hm);
			if(rec)
				return true;
		}
		return false;
	}
	
    bool isScramble(string s1, string s2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		unordered_map<char, int> hm;
		if(s1.size() != s2.size())
			return false;
		int size = s1.size();
		return helper(s1, 0, size-1, s2, 0, size-1, hm);
    }
};