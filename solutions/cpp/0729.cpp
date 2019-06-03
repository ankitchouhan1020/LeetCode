class MyCalendar {
 public:
  MyCalendar() {}

  bool book(int start, int end) {
    auto it = map.upper_bound(start);

    if (it != map.end() && it->first < end) return false;
    if (it != map.begin() && (--it)->second > start) return false;

    map[start] = end;

    return true;
  }

 private:
  std::map<int, int> map;
};