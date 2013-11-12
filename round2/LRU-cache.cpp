struct KVT{
	int key;
	int value;
	long long time;
	KVT(int k, int v, long long t): key(k), value(v), time(t) {}
};

class LRUCache{
public:
	static long long time;
	int size;
    unordered_map<int, KVT*> hm;
	vector<KVT*> elements;
	
	static bool comp(KVT* a, KVT* b){
		if(a->time > b->time)
			return true;
		return false;
	}

	LRUCache(int capacity) {
        size = capacity;
        time = 0;
    }
    
    int get(int key) {
		KVT* ret;
        if(hm.find(key) != hm.end()){
			ret = hm[key];
			
			time++;
			ret->time = time;
//			make_heap(elements.begin(), elements.end(), comp);

			return ret->value;
		}
		return -1;
    }
    
    void set(int key, int value) {
        KVT* tmp;
		time++;

		if(-1 != get(key)){
			hm[key]->value = value;
			hm[key]->time = time;
		//	make_heap(elements.begin(), elements.end(), comp);
		}
		//insert a new key
		else if(elements.size() < size){
			tmp = new KVT(key, value, time);
			hm[key] = tmp;
			elements.push_back(tmp);
			push_heap(elements.begin(), elements.end(), comp);
		}
		else{
			//need to remove
			make_heap(elements.begin(), elements.end(), comp);
			tmp = elements.front();
			hm.erase(tmp->key);
			hm[key] = tmp;
			
			tmp->key = key;
			tmp->value = value;
			tmp->time = time;
		}
    }
};

long long LRUCache::time = 0;
