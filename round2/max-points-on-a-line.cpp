/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
	void insert(unordered_map<float, unordered_map<float, unordered_set<Point*>* >* > &hm, Point* a, Point* b){
		float k, v;
		unordered_map<float, unordered_set<Point*>* >* phm;
		unordered_set<Point*>* phs;

		if(a->x == b->x){
			k = INT_MAX;
			v = a->x;
		}
		else{
			k = (b->y - a->y)/1.0/(b->x - a->x);
			v = (b->x * a->y - a->x * b->y)/1.0/(b->x - a->x);
		}

		if(hm.find(k) == hm.end()){
			phm = new unordered_map<float, unordered_set<Point*>* >();
			hm[k] = phm;
		}

		if((*hm[k]).find(v) == (*hm[k]).end()){
			phs = new unordered_set<Point*>();
			(*hm[k])[v] = phs;
		}
		(*(*hm[k])[v]).insert(a);
		(*(*hm[k])[v]).insert(b);
	}

	int get_largest_bucket(unordered_map<float, unordered_map<float, unordered_set<Point*>* >* > &hm){
		int max = 0;
		unordered_map<float, unordered_map<float, unordered_set<Point*>* >* >::iterator hmit;
		unordered_map<float, unordered_set<Point*>* >::iterator subit;
		int cursize;

		for(hmit = hm.begin(); hmit != hm.end(); hmit++){
			for(subit = (*(hmit->second)).begin(); subit != (*(hmit->second)).end(); subit++){
				cursize = (*(subit->second)).size();
				if(max < cursize)
					max = cursize;
			}
		}
		return max;
	}

    int maxPoints(vector<Point> &points) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.

		int i,j;
		unordered_map<float, unordered_map<float, unordered_set<Point*>* >* > hm;

		if(points.size() <= 2)
			return points.size();
		for(i = 0; i < points.size()-1; i++){
			for(j = i+1; j < points.size(); j++){
				insert(hm, &points[i], &points[j]);
			}
		}

		return get_largest_bucket(hm);
    }
};
