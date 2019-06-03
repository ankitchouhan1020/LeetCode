class Solution {
 public:
  vector<vector<string>> findLadders(string beginWord, string endWord,
                                     vector<string>& wordList) {
    unordered_set<string> set(wordList.begin(), wordList.end());

    if (!set.count(endWord)) return {};

    const int n = beginWord.length();

    vector<vector<string>> ans;

    unordered_set<string> queue1{beginWord};
    unordered_set<string> queue2{endWord};
    unordered_map<string, vector<string>> children;

    bool isFound = false;
    bool isBackward = false;

    while (!queue1.empty() && !queue2.empty() && !isFound) {
      if (queue1.size() > queue2.size()) {
        swap(queue1, queue2);
        isBackward = !isBackward;
      }
      for (const string& word : queue1) set.erase(word);
      for (const string& word : queue2) set.erase(word);
      unordered_set<string> queue;
      for (const string& word : queue1) {
        string curr = word;
        for (int i = 0; i < n; i++) {
          char c = curr[i];
          for (int j = 'a'; j <= 'z'; j++) {
            curr[i] = j;
            const string* parent = &word;
            const string* child = &curr;
            if (isBackward) swap(parent, child);
            if (queue2.count(curr)) {
              isFound = true;
              children[*parent].push_back(*child);
            } else if (set.count(curr) && !isFound) {
              queue.insert(curr);
              children[*parent].push_back(*child);
            }
          }
          curr[i] = c;
        }
      }
      swap(queue, queue1);
    }

    if (isFound) {
      vector<string> path{beginWord};
      dfs(beginWord, endWord, children, path, ans);
    }

    return ans;
  }

 private:
  void dfs(string& word, string& endWord,
           unordered_map<string, vector<string>>& children,
           vector<string>& path, vector<vector<string>>& ans) {
    if (word == endWord) {
      ans.push_back(path);
      return;
    }
    if (!children.count(word)) return;

    for (string& child : children[word]) {
      path.push_back(child);
      dfs(child, endWord, children, path, ans);
      path.pop_back();
    }
  }
};