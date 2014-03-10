class Solution {
public:
	void reverse(string &s, int i, int j){
		if(i > j)
			return;
		for(; i < j; i++, j--){
			swap(s[i], s[j]);
		}
	}
    
	void reverseWords(string &s) {
		int i, j;
		int len = s.size();
		for(i = 0; i < len && s[i] == ' '; i++)
			;
		i--;
		s.erase(0, i+1);
		if(s.empty())
			return;
		len = s.size();
		for(j = len-1; j >= 0 && s[j] == ' '; j--)
			;
		j++;
		s.erase(j, len-j);
		if(s.empty())
			return;
		for(i = j = 1; j < len; ){
			if(s[j] == ' ' && s[i-1] == ' '){
				j++;
				continue;
			}
			s[i++] = s[j++];
		}

		s = s.substr(0, i);
		len = s.size();
		for(i = 0; i < len; ){
			for(j = i; j < len && s[j] != ' '; j++)
				;
			j--;
			reverse(s, i, j);
			i = j+2;
		}
		reverse(s, 0, len-1);
	}
/*
    void reverseWords(string &s) {
		int i = 0;
		int len = s.size();
		int j;
		
		// clean string
		string clean = "";
		string tmp;

		for(i = 0; i < len; ){
			// move i to first non-space char
			while(i < len && s[i] == ' ')
				i++;
			if(i >= len)
				break;
			for(j = i; j < len && s[j] != ' '; j++)
				;
			j--;
			tmp = s.substr(i, j-i+1);
			reverse(tmp, 0, j-i);
			clean += tmp;
			clean += " ";

			i = j+1;
		}
		if(!clean.empty())
			clean = clean.substr(0, clean.size()-1);
		reverse(clean, 0, clean.size()-1);
		s = clean;
    }
	*/
};
