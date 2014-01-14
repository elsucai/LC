class Solution {
public:
	bool is_operand(string s){
		if(s.size() != 1)
			return false;
		char c = s[0];
		return (c == '+' || c == '-' || c == '*' || c == '/');
	}

    int evalRPN(vector<string> &tokens) {
		if(tokens.empty())
			return 0;
		stack<int> s;
		int i, a, b;
		for(i = 0; i < tokens.size(); i++){
			if(is_operand(tokens[i])){
				if(s.size() < 2)
					return 0;
				b = s.top();
				s.pop();
				a = s.top();
				s.pop();
				switch(tokens[i][0]){
					case '+':
						s.push(a+b);
						break;
					case '-':
						s.push(a-b);
						break;
					case '*':
						s.push(a*b);
						break;
					case '/':
						s.push(a/b);
						break;
					default:
						return 0;
				}
			}
			else{
				s.push(stoi(tokens[i]));
			}
		}
		if(s.size() != 1)
			return 0;
		return s.top();
    }
};
