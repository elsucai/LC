class Solution {
public:
	
	char* match(char* str, char* sub){
		char* s = str;
		char* t = sub;
		while(*s != '\0' && *t != '\0' && *s == *t){
			s++;
			t++;
		}
		
		if(*t == '\0')
			return str;
		return NULL;
	}

    char *strStr(char *haystack, char *needle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
    
		if(*needle == '\0'){
			return haystack;
		}
		char* p, *end;
		char* ret = NULL;

		for(end = haystack, p = needle; *p != '\0' && *end != '\0'; p++, end++)
			;
		if(*end == '\0' && *p != '\0')
			return NULL;
		end--;


		for(p = haystack; *p != '\0' && *end != '\0'; p++, end++){
			if(*p == *needle){
				ret = match(p, needle);
				if(ret != NULL)
					return ret;
			}
		}
    }
};
