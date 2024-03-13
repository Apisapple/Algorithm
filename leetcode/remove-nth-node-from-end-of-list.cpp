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
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    int total_length = getTotalLength(head);

    if (total_length == n) {
      ListNode *answer = head->next;
      delete head;

      return answer;
    }

    ListNode *current_head = head;
    for (int i = 0; i < total_length; ++i) {
      if (i == total_length - n - 1) {
        ListNode *delete_head = current_head->next;
        current_head->next = current_head->next->next;
        delete delete_head;

        break;
      }

      current_head = current_head->next;
    }

    return head;
  }

  int getTotalLength(ListNode *head) {
    ListNode *current_head = head;
    int dept = 0;

    while (current_head) {
      ++dept;
      current_head = current_head->next;
    }

    return dept;
  }
};