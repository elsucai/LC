class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
		
		int ret;
		stack<int> s;
		if(tokens.empty())
			return 0;
		int a,b;
		string x;
		for(int i = 0; i < tokens.size(); i++){
			x = tokens[i];
			if(x == "+"){
				if(s.size() < 2)
					return 0;
				b = s.top();
				s.pop();
				a = s.top();
				s.pop();
				s.push(a+b);
			}
			else if(x == "-"){
				if(s.size() < 2)
					return 0;
				b = s.top();
				s.pop();
				a = s.top();
				s.pop();
				s.push(a-b);
			}
			else if(x == "*"){
				if(s.size() < 2)
					return 0;
				b = s.top();
				s.pop();
				a = s.top();
				s.pop();
				s.push(a*b);
			}
			else if(x == "/"){
				if(s.size() < 2)
					return 0;
				b = s.top();
				s.pop();
				a = s.top();
				s.pop();
				s.push(a/b);
			}
			else{
				a = stoi(x);
				s.push(a);
			}
		}
		if(s.size() != 1)
			return 0;
		return s.top();
    }
};
