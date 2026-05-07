#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* makeList(vector<int> vals) {
        ListNode dummy(0);
        ListNode* cur = &dummy;
        for (int v : vals) {
            cur->next = new ListNode(v);
            cur = cur->next;
        }
        return dummy.next;
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);
        ListNode* cur = &dummy;

        while (list1 && list2) {
            if (list1->val <= list2->val) {
                cur->next = list1;
                list1 = list1->next;
            } else {
                cur->next = list2;
                list2 = list2->next;
            }
            cur = cur->next;
        }

        cur->next = list1 ? list1 : list2;  // attach remaining nodes

        return dummy.next;
    }
};

int main() {
    Solution solution;
    ListNode* list1 = solution.makeList({3, 4});
    ListNode* list2 = solution.makeList({1, 5, 10});
    ListNode* list3 = solution.mergeTwoLists(list1, list2);
    while (list3) {
        cout << list3->val << ", ";
        list3 = list3->next;
    }
    cout << endl;
    return 0;
}