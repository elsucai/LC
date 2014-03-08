class Solution {
	public:
		bool isMatch(const char *s, const char *p) {
			bool star = false;
			const char *str, *ptr;
			for (str = s, ptr = p; *str != '\0';) {
				switch (*ptr) {
					case '?':
					    str++;
					    ptr++;
						break;
					case '*':
						star = true;
						s = str, p = ptr;
						while (*p == '*') p++;  //skip continuous '*'
						if (*p == '\0')
							return true;
						ptr = p;
						break;
					default:
						if (*str != *ptr) {
							if (!star)
								return false;
							s++;
							str = s;
							ptr = p;
						}
						else{
						    str++;
						    ptr++;
						}
				} 
			}
			while (*ptr == '*')
				ptr++;
			return (*ptr == '\0');
		}
};
