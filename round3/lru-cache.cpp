struct KV{
	int key;
	int val;
	KV(int a, int b):key(a), val(b){}
};

class LRUCache{
public:
	list<KV> cache;
	int size;
	unordered_map<int, list<KV>::iterator> hm;

	LRUCache(int capacity) {
       size = capacity;
    }
    
    int get(int key) {
		if(hm.find(key) == hm.end()){
			return -1;
		}
		else{
			cache.splice(cache.begin(), cache, hm[key]);
			hm[key] = cache.begin();
			return hm[key]->val;
		}
    }
    
    void set(int key, int value) {
		if(hm.find(key) != hm.end()){
			// update value and location
			hm[key]->val = value;
			cache.splice(cache.begin(), cache, hm[key]);
			hm[key] = cache.begin();
			return;
		}

		// need to insert
		cache.insert(cache.begin(), KV(key, value));
		hm[key] = cache.begin();
		if(cache.size() > size){
			// delete
			hm.erase(cache.back().key);
			cache.pop_back();
		}
    }
};
