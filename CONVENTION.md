---
title: 'LeetCode Naming Convention'
author: Hsins Peng, Jay Chen
tags: LeetCode
---

# LeetCode Naming Convention

## Fundamental

### Rules

- **Class**: `UpperCamelCase`
- **Function**: `lowerCamelCase`
- **Variable**: `lowerCamelCase`
- **Constant**: `UPPERCASE`
- **Field**: `lowerCamelCase`
- **Database**: `SELECT * FROM name_table`

`constexpr`???

### Examples

```cpp
// Class
class MyClass { ... }

// Function
function myFunction() { ... }

// Variable
int myVariable;

// Constant
#define CONSTANT;

// Database Table
SELECT * FROM my_table
```

## Template

### Rules

- There should only be one public function.
- Declare the variables in the proper scope as slow as possible.

  - Declare `ans` as soon as possible.
  - Since LeetCode is just an online judge system rather than a big project, we don't scatter all variables in different sections. However, we still sort the variables based on the time we first used each variable.

- Code section (there should be one blank line between each sections.)

  - `public`

    1. boundary conditions
    2. initial variables
    3. There may be many kernels, each separating a blank line between kernels, but each kernel itself should not be blank in between.
    4. return

  - `private`

    1. private variables
    2. private function(s)

## Schematic Template

```cpp
class Solution {
 public:
  // There should only be one public function.
  func() {
    // boundary conditions

    // initial variables
    //   get size or length (if needed)
    //   '\n'
    //   other varibles

    // kernel

    // return
  }

 private:
  // private variables

  // private function(s)
  helper() { ... }

  dfs() { ... }
};
```

Example ([873. Length of Longest Fibonacci Subsequence](https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/)):

- w/o comment:

  ```cpp
  class Solution {
   public:
    int lenLongestFibSubseq(vector<int>& A) {
      const int n = A.size();

      int ans = 0;
      unordered_map<int, int> map;
      vector<vector<int>> dp(n, vector<int>(n, 2));

      for (int i = 0; i < n; i++) map[A[i]] = i;

      for (int j = 0; j < n; j++)
        for (int k = j + 1; k < n; k++)
          if (A[k] - A[j] < A[j] && map.count(A[k] - A[j])) {
            int i = map[A[k] - A[j]];
            dp[j][k] = dp[i][j] + 1;
            ans = max(ans, dp[j][k]);
          }

      return ans;
    }
  };
  ```

- w/ comment:

  ```cpp
  class Solution {
   public:
    int lenLongestFibSubseq(vector<int>& A) {
      // Only get the value of size or length
      //   when we use it twice or more times.
      // Add `const`, and separate from next section a blank line.
      const int n = A.size();

      // Declare the variables in the proper scope as slow as possible.
      //   Declare `ans` as soon as possible.
      //   Order: ans -> STL -> dp -> pointers (to be discussed)
      int ans = 0;
      unordered_map<int, int> map;
      vector<vector<int>> dp(n, vector<int>(n, 2));

      for (int i = 0; i < n; i++) map[A[i]] = i; // single line based on clang-format

      for (int j = 0; j < n; j++)
        for (int k = j + 1; k < n; k++)
          if (A[k] - A[j] < A[j] && map.count(A[k] - A[j])) { // use `map.count` not `map.find` pattern
            int i = map[A[k] - A[j]];
            dp[j][k] = dp[i][j] + 1;
            ans = max(ans, dp[j][k]);
          }

      return ans;
    }
  };
  ```

## Boundary Conditions

```cpp
// Linked-List
if (l1 || l2) { ... }
if (!l1 || !l2) { ... }

// String
if (str.empty()) { ... }
if (str.length() <= 2) { ... }

// Vector
if (vec.size() <= 2) { ... }
```

## Return Value

```cpp
return ans;
return {};
```

## Data Structure

```cpp
// C++
unordered_set<string> set;
unordered_map<char, int> map;
vector<int> map; // even if you use array or vector, stick to map
queue<TreeNode*> queue;
deque<TreeNode*> deque;
stack<char> stack;
priority_queue<ListNode*, vector<ListNode*>, compareListNode> pq;
```

```python
# Python
set_ = set() # or wordSet = set() if you like
dict = {}
dict = collections.defaultdict(int)
dict = collections.defaultdict(list)
queue = collections.deque([root])
deque = collections.deque([root])
stack = []
```

## Two Pointers / Sliding Windows

> Always prefer to one character to represent index variables.

> Use `i`, `j`, `k` in the loop, in that order.

```cpp
int i = 0;

for (int num : nums) { ... }
```

```cpp
int j = 0;

for (int i = 0; i < n; i++) { ... }
```

```cpp
int k = 0;

for (int i = 0; i < n; i++)
  for (int j = i; j < n; j++) { ... }
```

```cpp
int l = 0;
int r = nums.size() - 1;
```

## Binary Search

1. Always prefer to _one_ character to represent index variables.
2. Always prefer to use `[l, r)` pattern.

```cpp
int l = 0;
int r = nums.size();  // or nums.size() - 1

while (l < r) {
  int m = l + (r - l) / 2;
  if (f(m)) return m;  // optional
  if (g(m))
    l = m + 1;  // new range [m + 1, r)
  else
    r = m;  // new range [l, m)
}

return l;  // nums[l]
```

## ListNode

```cpp
ListNode dummy(0); // the only variable that declared statically

ListNode* curr;
ListNode* prev;
ListNode* next;

ListNode* slow;
ListNode* fast;

ListNode* head;
ListNode* tail;

ListNode* l1;
ListNode* l2;
```

## 2D Vector / 2 Strings

```cpp
// 2D Vector
const int m = matrix.size();
const int n = matrix[0].size();

// if there're two strings
const int m = str1.length();
const int n = str2.length();

// if there's only a string
const int n = str.length();
```

## Traversing

```cpp
// vector<int> nums;
for (int i = 0; i < nums.size(); i++) { ... }
for (int num : nums) { ... }

// vector<string> words;
for (string& word : words) { ... }

// string str;
for (int i = 0; i < str.length(); i++) { ... }
for (char c : str) { ... }

// unordered_set<int> set;
for (int num : set) { ... }

// unordered_map<char, int> map;
for (auto& [key, value] : map) { ... }

// ListNode* head;
for (ListNode* curr = head; curr; curr = curr->next) { ... }
```

## Pattern

- Find the length of a given linked-list

  ```cpp
  int length = 0; // name `length` rather than `len`
  for (ListNode* curr = head; curr; curr = curr->next) length++;
  ```

  ```python
  length = 0
  curr = head
  while curr:
      length += 1
      curr = curr.next
  ```

- Initialize a dummy ListNode

  ```cpp
  ListNode dummy(0);
  dummy->next = head;
  ListNode* curr = &dummy;
  ```

- DFS

  ```cpp
  class Solution {
   public:
    vector<vector<int>> permute(vector<int>& nums) {
      vector<vector<int>> ans;
      vector<int> path;
      vector<bool> used(nums.size(), false);

      dfs(nums, nums.size(), used, path, ans);

      return ans;
    }

   private:
    void dfs(vector<int>& nums, int target, vector<bool>& used, vector<int>& path,
             vector<vector<int>>& ans) {
      if (target == 0) {
        ans.push_back(path);
        return;
      }

      for (int i = 0; i < nums.size(); i++) {
        if (used[i]) continue;
        used[i] = true;
        path.push_back(nums[i]);
        dfs(nums, target - 1, used, path, ans);
        path.pop_back();
        used[i] = false;
      }
    }
  };
  ```

  ```cpp
  bool dfs(vector<vector<char>>& board, string& word, int i, int j, int pos) {
    if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() ||
        board[i][j] != word[pos] || board[i][j] == '*')
      return false;
  ```

## Others

1. Always prefer to use `str.length()` over `str.size()`.
2. Always use _camelCase_ nomenclature when not listed above.

   ```cpp
   int currNum;
   TreeNode* currNode;
   int maxProfit;
   ```

3. Add a underline (`_`) after a variable.

   - When there's confliction in expression and function:

     ```cpp
     // C++
     min, max, std::min(), std::max()
     ```

     ```python
     # Python
     min_, max_, min(), max()
     ```

   - When there's confliction with default reserved words:

     ```python
     # Python
     set_, set()
     ```

4. When there are two maps/stacks, use `1` and `2` suffixes.

   ```cpp
   unordered_map<char, int> map1;
   unordered_map<char, int> map2;
   ```

5. When we need to count something, use `sum`, `count` and `total`, in that order.
6. Initialize with `0` or `false` **implicitly**.
7. `const` is used iff we get value of `size()` or `length()`.
8. `auto` is used iff when we iterate through a `map` or declare a variable of `ListNode*` (except `NULL`).
9. Use `&` whenever possible except `int` and `char`.
10. Prefer to name variable in a "adjactive + noun" order. For example, `maxLeft` is better than `leftMax`.

## Discussion

[5. Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring/)

```cpp
class Solution {
 public:
  string longestPalindrome(string s) {
    const int length = s.length() * 2 + 3;

    // Manacher's Algorithm
    string T(length, '#');
    T[0] = '$';
    T[length - 1] = '@';
    for (int i = 2; i < length - 2; i += 2) T[i] = s[i / 2 - 1];

    int center = 1;
    int right = 1;
    vector<int> P(length, 0);

    for (int i = 1; i < length - 1; i++) {
      int mirr = 2 * center - i;
      if (i < right) P[i] = min(P[mirr], right - i);
      while (T[i + P[i] + 1] == T[i - P[i] - 1]) P[i]++;
      if (i + P[i] > right) {
        center = i;
        right = i + P[i];
      }
    }

    // find max and the center;
    int max = 0;
    int c = 0;
    for (int i = 0; i < length; i++)
      if (P[i] > max) {
        max = P[i];
        c = i;
      }

    // omit '#' and get the string desired
    string ans(max, '#');
    int i = 0;
    for (int j = c - max + 1; j < c + max; j += 2) {
      ans[i] = T[j];
      i++;
    }

    return ans;
  }
};
```

[6. ZigZag Conversion](https://leetcode.com/problems/zigzag-conversion/)

The position of `ans`?

```cpp
class Solution {
 public:
  string convert(string s, int numRows) {
    vector<vector<char>> rows(numRows);
    int direction = (numRows == 1) - 1;
    int k = 0;

    for (char c : s) {
      rows[k].push_back(c);
      if (k == 0 || k == numRows - 1) direction *= -1;
      k += direction;
    }

    string ans(s);
    k = 0;

    for (int i = 0; i < numRows; i++)
      for (int j = 0; j < rows[i].size(); j++)
        ans[k++] = rows[i][j];

    return ans;
  }
};
```

[24. Swap Nodes in Pairs](https://leetcode.com/problems/swap-nodes-in-pairs/)

Problem 25. has same issue.

```cpp
class Solution {
 public:
  ListNode* swapPairs(ListNode* head) {
    if (!head || !head->next) return head;

    ListNode dummy(0);
    dummy.next = head;
    int length = 0;
    for (auto curr = head; curr; curr = curr->next) length++;

    auto prev = &dummy;
    auto curr = head;

    for (int i = 0; i < length / 2; i++) {
      auto next = curr->next;
      curr->next = next->next;
      next->next = prev->next;
      prev->next = next;
      prev = curr;
      curr = curr->next;
    }

    return dummy.next;
  }
};
```

## Categories:

- DFS: 18, 22, 37, 39, 30
- DP: 44
