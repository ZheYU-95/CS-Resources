// 美团面试一：两个递增链表，
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL){}
    ListNode() : val(), next(NULL){}
};

int main() {
    int n1, n2;
    cin >> n1 >> n2;

    ListNode *preHead1 = new ListNode(-1);
    ListNode *head1 = preHead1;
    for (int i = 0; i < n1; ++i) {
        int x;
        cin >> x;
        // ListNode tmp = ListNode(x);   // 
        // head1->next = &tmp;
        head1->next = new ListNode(x);
        head1 = head1->next;
    }

    ListNode *preHead2 = new ListNode(-1);
    ListNode *head2 = preHead2;
    for (int i = 0; i < n2; ++i) {
        int x;
        cin >> x;
        head2->next = new ListNode(x);
        head2 = head2->next;
    }

    ListNode *preHead = new ListNode(-1);
    ListNode *head = preHead;
    preHead1 = preHead1->next;
    preHead2 = preHead2->next;
    while (preHead1 && preHead2) {
        if(preHead1->val > preHead2->val) swap(preHead1, preHead2);
        head->next = preHead1;
        preHead1 = preHead1->next;
        head = head->next;
    }
    head->next = preHead1 ? preHead1 : preHead2;

    while (preHead->next) {
        cout << preHead->next->val << " ";
        ListNode *tmp = preHead->next;
        delete preHead;
        preHead = tmp;
    }
    delete preHead1, preHead2;
    return 0;
}