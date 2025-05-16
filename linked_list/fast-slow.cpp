#include "includes.h"

// ListNode Structure
typedef struct ListNode {
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr) {};
    ListNode(int x): val(x), next(nullptr) {};
    ListNode(int x, ListNode* next): val(0), next(next) {};
} ListNode;


 bool hasCycle(ListNode *head) {
        if (head == nullptr) return false;

        // Intialize a fast pointer and a slow pointer staggered by 1
        ListNode* slow = head;
        ListNode* fast = head->next;


        // The fast pointer will move at double the speed, so if there is a loop
        //  it will eventually be at the same node as the slow pointer
        while (fast != nullptr && fast->next != nullptr) {
            if (slow == fast) {
                return true;
            }

            fast = fast->next->next;
            slow = slow->next;


        }
        // If the fast pointer reaches the end of the ll there cannot be a cycle
        return false;

    }