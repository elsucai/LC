class Solution {
	public:
		bool is_valid(string &s, int x){
			if(s[x] <= '9' && s[x] >= '0')
				return true;
			if(s[x] <= 'z' && s[x] >= 'a')
				return true;
			if(s[x] <= 'Z' && s[x] >= 'A'){
				s[x] -= ('A' - 'a');
				return true;
			}
			return false;
		}

		bool isPalindrome(string s) {
			if(s.size() <= 1)
				return true;
			int i = 0;
			int j = s.size()-1;
			while(true){
				// move i to next valid char
				while(i < j && !is_valid(s, i))
					i++;
				// move j to previous valid char
				while(j > i && !is_valid(s, j))
					j--;
				if(j <= i)
					return true;
				if(s[i] != s[j])
					return false;
				i++;
				j--;
			}
		}
};
