class Solution {
 public:
  vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> ans;
    vector<vector<int>> graph(numCourses);
    vector<int> visited(numCourses, 0);

    for (vector<int>& prerequisite : prerequisites)
      graph[prerequisite[0]].push_back(prerequisite[1]);

    for (int i = 0; i < numCourses; i++)
      if (dfs(graph, visited, i, ans)) return {};

    return ans;
  }

 private:
  bool dfs(vector<vector<int>>& graph, vector<int>& visited, int curr,
           vector<int>& ans) {
    if (visited[curr] == 1) return true;
    if (visited[curr] == 2) return false;

    visited[curr] = 1;

    for (int neighbor : graph[curr])
      if (dfs(graph, visited, neighbor, ans)) return true;

    visited[curr] = 2;
    ans.push_back(curr);

    return false;
  }
};