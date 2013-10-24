class Solution {
public:
    int numDecodings(string s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.

		if(s.empty())
			return 0;

		int size = s.size();
		vector<int> D(size+1, 0);
		D[size] = 1;
		
		for(int i = size-1; i >= 0; i--){
			// compute D[i]

			if(s[i] == '0'){
				D[i] = 0;
			}
			else{
				// single digit
				D[i] += D[i+1];
				// 2 digits
				if(s[i] == '1'){
					if(i < size-1){
						D[i] += D[i+2];
					}
				}
				else if(s[i] == '2'){
					if(i < size-1 && s[i+1] <= '6' && s[i+1] >= '0'){
						D[i] += D[i+2];
					}
				}
				else
					;
			}
		}

		return D[0];
    }
};
