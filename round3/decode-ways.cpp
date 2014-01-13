class Solution {
public:
    int numDecodings(string s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
		if(s.empty())
			return 0;
		int n = s.size();
		vector<int> D(n+1, 0);
		D[n] = 1;
		if(s[n-1] == '0')
			D[n-1] = 0;
		else
			D[n-1] = 1;
		for(int i = n-2; i >= 0; i--){
			// pick 1 digit
			if(s[i] != '0')
				D[i] += D[i+1];
			if(s[i] != '1' && s[i] != '2')
				continue;
			if(s[i] == '2' && s[i+1] <= '9' && s[i+1] >= '7')
				continue;
			D[i] += D[i+2];
		}
		return D[0];
    }
};
