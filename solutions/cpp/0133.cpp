class Solution {
 public:
  Node* cloneGraph(Node* node) {
    if (!node) return NULL;
    if (map.count(node)) return map[node];

    map[node] = new Node(node->val, {});
    for (Node* neighbor : node->neighbors)
      map[node]->neighbors.push_back(cloneGraph(neighbor));

    return map[node];
  }

 private:
  unordered_map<Node*, Node*> map;
};