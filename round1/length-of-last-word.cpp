class Solution {
public:
    int lengthOfLastWord(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

		if(!s || *s == '\0')
			return 0;

		const char* ptr;
		for(ptr = s; *ptr != '\0'; ptr++)
			;
		ptr--;

		// now ptr points to the last char
		
		// find the end of last word, if it exists
		while(ptr >= s && *ptr == ' ')
			ptr--;
		if(ptr < s)
			return 0; // no such word
		const char* end = ptr;
		
		// find the start of the word
		while(ptr >= s && *ptr != ' ')
			ptr--;

		if(ptr < s)
			return end-s+1;
		return end-ptr;
    }
};
