class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
		
		int carry = 1;
		int i, sum;
		for(i = digits.size()-1; i >= 0; i--){
			sum = digits[i]+carry;
			digits[i] = sum%10;
			carry = sum/10;
		}
		if(carry == 1){
			digits.insert(digits.begin(), 1);
		}
		return digits;
    }
};
