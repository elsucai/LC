class Solution {
public:
	void revert(string &str, int s, int e){
		while(s < e){
			swap(str[s], str[e]);
			s++;
			e--;
		}
	}
	
    string getPermutation(int n, int k) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
       
		int r = 1;
		int i, j;
		
		int s = 0;
		int e = n-1;
		int round;
		string ret = "";
		for(i = 1; i <= n; i++){
			ret += "0";
			ret[i-1] = '0'+i;
		}
		
		while(1){
			r = 1;
			for(i = 1; i <= n;){
				if(k < r){
					break;
				}
				i++;
				r *= i;
			}
			
			r /= i;
			i--;
			
			round = k/r;
			k = k%r;
			
			s = e = n-i-1;
			if(s < 0){
				revert(ret, 0, n-1);
				return ret;
			}
			
			e += (round-1);
			
			if(k == 0){
				swap(ret[s], ret[e]);
				sort(ret.begin()+s+1, ret.end());
				revert(ret, s+1, n-1);
				return ret;
			}
			e++;
			swap(ret[s], ret[e]);
			sort(ret.begin()+s+1, ret.end());		
		}
	}
};