#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* createList() {
	ListNode head(-1);
	ListNode* cur = &head;
	int x;
	while (cin >> x) {
		ListNode* temp = new ListNode(x);
		cur -> next = temp;
		cur = cur -> next;
	}
	return head.next;
}

void printList(ListNode* head) {
	ListNode* p = head;
	while (p) {
		cout << p -> val << '\t';
		p = p -> next;
	}
	cout << '\n';
}
int main()
{
	ListNode* head = createList();
	printList(head);
	return 0;
}
