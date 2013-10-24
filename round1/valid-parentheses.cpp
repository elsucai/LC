class Solution {
public:
    bool isValid(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

		if(s.empty())
			return true;
		
		stack<char> ST;
		
		for(int i = 0; i < s.size(); i++){
			if(s[i] == '(' || s[i] == '[' || s[i] == '{')
				ST.push(s[i]);
			else{
				if(ST.empty())
					return false;
				char c = ST.top();
				switch(s[i]){
					case ')':
						if(c != '(')
							return false;
						ST.pop();
						break;
					case ']':
						if(c != '[')
							return false;
						ST.pop();
						break;
					case '}':
						if(c != '{')
							return false;
						ST.pop();
						break;
					default:
						ST.pop();
						break;
				}
			}
		}

		return (ST.empty());
    }
};
