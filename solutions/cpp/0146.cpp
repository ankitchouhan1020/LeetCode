class LRUCache {
 public:
  LRUCache(int capacity) : capacity(capacity) {}

  int get(int key) {
    if (!map.count(key)) return -1;
    cache.splice(cache.begin(), cache, map[key]);
    return map[key]->second;
  }

  void put(int key, int value) {
    if (map.count(key)) {
      map[key]->second = value;
      cache.splice(cache.begin(), cache, map[key]);
      return;
    }

    if (cache.size() == capacity) {
      pair<int, int>& node = cache.back();
      map.erase(node.first);
      cache.pop_back();
    }

    cache.emplace_front(key, value);
    map[key] = cache.begin();
  }

 private:
  int capacity;
  list<pair<int, int>> cache;
  unordered_map<int, list<pair<int, int>>::iterator> map;
};