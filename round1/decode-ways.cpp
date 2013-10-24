class Solution {
public:

    int numDecodings(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		
		if(s.empty())
			return 0;
		int size = s.size();
		int ret;

		int* D = new int[size+1];
		for(int i = 0; i <= size; i++)
			D[i] = 1;

		// D[i] is the number of decoding ways
		// for string begins at i, till the end
		for(int i = size-1; i >= 0; i--){
			//self
			if(s[i] == '0')
				D[i] = 0;
			else{
				D[i] = D[i+1];
			}

			//s[i]+s[i+1]
			if(i+1 < size){
				if(s[i] == '1' || (s[i] == '2' && s[i+1] <= '6'))
					D[i] += D[i+2];
			}
		}

		return D[0];
    }
};
