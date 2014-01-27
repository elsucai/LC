class Solution {
public:
    int romanToInt(string s) {
		unordered_map<char, int> hm;
		hm['I'] = 1;
		hm['V'] = 5;
		hm['X'] = 10;
		hm['L'] = 50;
		hm['C'] = 100;
		hm['D'] = 500;
		hm['M'] = 1000;

		if(s.empty())
			return 0;
		int sum = hm[s[s.size()-1]];
		for(int i = s.size()-2; i >= 0; i--){
			if(hm[s[i]] < hm[s[i+1]])
				sum -= hm[s[i]];
			else
				sum += hm[s[i]];
		}
		return sum;
    }
};
