class Solution {
public:

	bool helper(char* h, char* n){
		while(*n != '\0'){
			if(*h != *n)
				return false;
			h++;
			n++;
		}
		return true;
	}

    char *strStr(char *haystack, char *needle) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
	
		assert(haystack);
		assert(needle);
		int m = strlen(haystack);
		int n = strlen(needle);

		if(*needle == '\0')
			return haystack;
		if(m < n)
			return NULL;

		int far = m-n;
		bool found = false;
		for(int i = 0; i <= far; i++){
			if(*(haystack+i) == *needle){
				found = helper(haystack+i, needle);
				if(found)
					return haystack+i;
			}
		}
		return NULL;
    }
};
