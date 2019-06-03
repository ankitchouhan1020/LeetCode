class Solution {
 public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> graph(numCourses);
    vector<int> visited(numCourses, 0);

    for (vector<int>& prerequisite : prerequisites)
      graph[prerequisite[1]].push_back(prerequisite[0]);

    for (int i = 0; i < numCourses; i++)
      if (dfs(graph, visited, i)) return false;

    return true;
  }

 private:
  bool dfs(vector<vector<int>>& graph, vector<int>& visited, int curr) {
    if (visited[curr] == 1) return true;
    if (visited[curr] == 2) return false;

    visited[curr] = 1;

    for (int neighbor : graph[curr])
      if (dfs(graph, visited, neighbor)) return true;

    visited[curr] = 2;

    return false;
  }
};