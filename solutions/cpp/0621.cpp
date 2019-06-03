class Solution {
 public:
  int leastInterval(vector<char>& tasks, int n) {
    vector<int> map(26);
    for (char task : tasks) map[task - 'A']++;
    sort(map.begin(), map.end());

    int i = 25;

    while (i >= 0 && map[i] == map[25]) i--;

    return max((int)tasks.size(), (map[25] - 1) * (n + 1) + 25 - i);
  }
};