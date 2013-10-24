/*
#include <iostream>
#include <vector>

using namespace std;

*/

class Solution {
public:
	int find(vector<int> &num, int val, int s, int e){
		//num is in decreasing order
		//find the last occurance of val
		int m, candidate;
		candidate = -1;
		while(s <= e){
			m = s + (e - s)/2;
			if(num[m] == val){
				candidate = max(candidate, m);
				s = m+1;
			}
			else if(num[m] < val){
				e = m-1;
			}
			else
				s = m+1;
		}
		
		if(candidate == -1)
			candidate = e;
	}

    void nextPermutation(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(num.empty() || num.size() == 1)
			return;
	

		int i, j;
		int size = num.size();
		for(i = size-2; i >= 0; i--){
			if(num[i] < num[i+1])
				break;
		}
		if(i < 0){
			//reverse
			i = 0;
			j = size-1;
			while(i < j){
				swap(num[i], num[j]);
				i++;
				j--;
			}
		}
		else{
			// i is the one
			int last = find(num, 1+num[i], i+1, size-1);
			// last must be valid
			swap(num[i], num[last]);
			int x, y;
			for(x = i+1, y = size-1; x < y;){
				swap(num[x], num[y]);
				x++;
				y--;
			}
		}
    }
};

/*
int main(){
	vector<int> v;
	v.push_back(2);
	v.push_back(3);
	v.push_back(1);

	Solution s;
	s.nextPermutation(v);
	for(int i = 0; i < v.size(); i++)
		cout<<v[i]<<endl;
	return 0;
}
*/
