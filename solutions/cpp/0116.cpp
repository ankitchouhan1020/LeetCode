class Solution {
 public:
  Node* connect(Node* root) {
    Node* node = root;

    while (node && node->left) {
      Node* next = node->left;
      while (node) {
        node->left->next = node->right;
        node->right->next = node->next ? node->next->left : NULL;
        node = node->next;
      }
      node = next;
    }

    return root;
  }
};