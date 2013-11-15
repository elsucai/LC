struct KV{
	int key;
	int value;
	KV(int k, int v): key(k), value(v) {}
};

class LRUCache{
public:
	int size;
    unordered_map<int, list<KV>::iterator> hm;
	list<KV> elements;
	
	LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
		int ret;
		list<KV>::iterator it;
        if(hm.find(key) != hm.end()){
			it = hm[key];
			ret = it->value;
			elements.splice(elements.begin(), elements, it);
			hm[key] = elements.begin();

			return ret;
		}
		return -1;
    }
    
    void set(int key, int value) {
		list<KV>::iterator it;
		
		if(-1 != get(key)){
			it = hm[key];
			it->value = value;
			elements.splice(elements.begin(), elements, it);
			hm[key] = elements.begin();
		}
		//insert a new key
		else if(elements.size() < size){
			elements.push_front(KV(key, value));
			hm[key] = elements.begin();
		}
		else{
			//need to remove
			hm.erase(elements.back().key);
			elements.pop_back();
			elements.push_front(KV(key, value));
			hm[key] = elements.begin();
		}
    }
};
