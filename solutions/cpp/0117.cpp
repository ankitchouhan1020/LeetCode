class Solution {
 public:
  Node* connect(Node* root) {
    Node* node = root;
    Node* curr = new Node(NULL);
    Node* prev = curr;

    while (node) {
      while (node) {
        curr->next = node->left;
        if (curr->next) curr = curr->next;
        curr->next = node->right;
        if (curr->next) curr = curr->next;
        node = node->next;
      }
      node = prev->next;
      curr = prev;
    }

    return root;
  }
};