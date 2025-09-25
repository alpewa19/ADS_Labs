# include <iostream>
# include <algorithm>
using namespace std;
struct Node {
  int val;
  Node *next;

  Node() {
    val = 0;
    next = NULL;
  }
};
int findMaxSum(int n, Node *head) {
  if (n <= 0 || head == NULL) return 0;
  int best = head->val;
  int cur  = head->val;
  for (Node* p = head->next; p != NULL; p = p->next) {
    cur  = max(p->val, cur + p->val);
    best = max(best, cur);
  }
  return best;
}
int main() {
  int n;
  cin >> n;

  Node *head, *tail;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    Node *cur = new Node();
    cur->val = x;

    if (i == 1) {
      head = tail = cur;
    } else {
      tail->next = cur;
      tail = cur;
    }
  }
  cout << findMaxSum(n, head) << "\n";
  return 0;
}