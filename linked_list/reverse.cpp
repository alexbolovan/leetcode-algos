#include "includes.h"

// ListNode Structure
typedef struct ListNode {
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr) {};
    ListNode(int x): val(x), next(nullptr) {};
    ListNode(int x, ListNode* next): val(0), next(next) {};
} ListNode;


ListNode* reverseList(ListNode *head) {
    // Check to see if the head actually contains anything
    if (head == nullptr) {
        return head;
    }

    /*
       You will need init three pointers for reversing. We will keep track of all these nodes in the loop below
        => Curr           
        => Next 
        => Prev   
    */
    ListNode* curr = head;
    ListNode* next = head;
    ListNode* prev = head;

    /*
    We will track the steps for the first iter. At the start we have
    prev    curr & next -> nextNode
    */

    while (curr != nullptr) {
        // Move next up so we can copy curr to it
        // prev   curr -> next -> nextNode
        next = curr->next;

        // Temporarily (i.e. this will be undone) point curr bacwards
        // prev <- curr   next -> nextNode
        curr->next = prev;

        // At this point prev is now reverse 
        // <- {curr | prev} next 
        prev = curr;

        // Move curr up to repeat the process
        // <- prev  {curr | next} -> nextNode
        curr = next;
        
    }

    return prev;

}


