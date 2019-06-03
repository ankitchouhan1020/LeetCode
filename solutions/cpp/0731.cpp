class MyCalendarTwo {
 public:
  MyCalendarTwo() {}

  bool book(int start, int end) {
    for (auto& [first, second] : overlaps)
      if (max(start, first) < min(end, second)) return false;

    for (auto& [first, second] : booked) {
      int s = max(start, first);
      int e = min(end, second);
      if (s < e) overlaps.emplace_back(s, e);
    }

    booked.emplace_back(start, end);
    return true;
  }

 private:
  vector<pair<int, int>> booked;
  vector<pair<int, int>> overlaps;
};
