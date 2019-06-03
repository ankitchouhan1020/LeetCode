class MyLinkedList {
 public:
  MyLinkedList() : len(0) { head = new ListNode(0); }

  int get(int index) {
    if (index < 0 || index >= len) return -1;
    ListNode* curr = head->next;
    for (int i = 0; i < index; i++) curr = curr->next;
    return curr->val;
  }

  void addAtHead(int val) {
    ListNode* curr = head->next;
    head->next = new ListNode(val);
    head->next->next = curr;
    len++;
  }

  void addAtTail(int val) {
    ListNode* curr = head;
    while (curr->next) curr = curr->next;
    curr->next = new ListNode(val);
    len++;
  }

  void addAtIndex(int index, int val) {
    if (index > len) return;
    ListNode* curr = head;
    for (int i = 0; i < index; i++) curr = curr->next;
    ListNode* temp = curr->next;
    curr->next = new ListNode(val);
    curr->next->next = temp;
    len++;
  }

  void deleteAtIndex(int index) {
    if (index < 0 || index >= len) return;
    ListNode* curr = head;
    for (int i = 0; i < index; i++) curr = curr->next;
    ListNode* temp = curr->next;
    curr->next = temp->next;
    len--;
    delete temp;
  }

 private:
  struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
  };

  int len;
  ListNode* head;
};
