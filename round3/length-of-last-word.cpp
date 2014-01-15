class Solution {
public:
    int lengthOfLastWord(const char *s) {
		if(!s || *s == '\0')
			return 0;
		int size = 0; 
		for(const char *ptr = s; *ptr != '\0'; ptr++)
			size++;

		int e, cnt;
		for(e = size-1; e >= 0 && s[e] == ' '; e--)
			;
		if(e < 0)
			return 0;
		for(cnt = 0; e >= 0 && s[e] != ' '; e--, cnt++)
			;
		return cnt;
    }
};
