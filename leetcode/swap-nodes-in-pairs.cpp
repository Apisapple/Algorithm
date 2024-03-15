#include <algorithm>

using namespace std;

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
  ListNode *swapPairs(ListNode *head) {
    if (head == NULL || head->next == NULL) {
      return head;
    }

    ListNode *currentNode = head;
    ListNode *newNode = head->next;

    while (currentNode != NULL && currentNode->next != NULL) {
      ListNode *temp = currentNode->next;
      currentNode->next = currentNode->next->next;
      temp->next = currentNode;
      currentNode = currentNode->next;

      if (currentNode != NULL && currentNode->next != NULL) {
        temp->next->next = currentNode->next;
      }
    }

    return newNode;
  }
};