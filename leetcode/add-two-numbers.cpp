#include <iostream>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *tempNode = new ListNode();
    ListNode *headNode = tempNode;
    int total = 0;

    while (l1 != NULL || l2 != NULL || total) {
      if (l1 != NULL) {
        total += l1->val;
        l1 = l1->next;
      }

      if (l2 != NULL) {
        total += l2->val;
        l2 = l2->next;
      }

      tempNode->next = new ListNode(total % 10);
      total /= 10;
      tempNode = tempNode->next;
    }

    return headNode->next;
  }
};