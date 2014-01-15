class Solution {
public:
	
	bool found(char *s, char* needle){
		for(; *needle != '\0' && *s == *needle; s++, needle++)
			;
		if(*needle == '\0')
			return true;
		return false;
	}

    char *strStr(char *haystack, char *needle) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
		if(!needle || !haystack)
			return NULL;
		if(*needle == '\0')
			return haystack;
		char* s, *e, *ptr;
		for(ptr = needle, s = e = haystack; *ptr !='\0' && *e != '\0'; ){
			ptr++;
			e++;
		}
		if(*ptr != '\0')
			return NULL;
		e--;

		for(; *e != '\0'; s++, e++){
			if(found(s, needle))
				return s;
		}
		return NULL;
	}
};
