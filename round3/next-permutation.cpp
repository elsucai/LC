class Solution {
public:
	void reverse(vector<int> &num, int s, int e){
		while(s < e){
			swap(num[s], num[e]);
			s++;
			e--;
		}
	}

	int find_last_occur_greater_than_x(vector<int> &num, int s, int e, int key){
		int candidate = -1;
		int m;
		while(s <= e){
			m = s+(e-s)/2;
			if(num[m] > key){
				candidate = m;
				s = m+1;
			}
			else
				e = m-1;
		}
		return candidate;
	}

    void nextPermutation(vector<int> &num) {
		int i;
		if(num.size() <= 1)
			return;
		for(i = num.size()-2; i >= 0; i--){
			if(num[i] < num[i+1])
				break;
		}
		if(i < 0){
			// reverse whole array, then return
			reverse(num, 0, num.size()-1);
			return;
		}

		int index = find_last_occur_greater_than_x(num, i+1, num.size()-1, num[i]);
		swap(num[i], num[index]);
		reverse(num, i+1, num.size()-1);
    }
};
