/*
A linked list is a linear data structure in which each element is a "node object",
and the nodes are connected through “references”.
A reference records the memory address of the next node, through which the next node can be accessed from the current node.
*/
#include <iostream>
using namespace std;

/*As shown in the following code, a linked list node "ListNode" contains not only a value but also an additional reference (pointer).
Therefore, linked lists occupy more memory space than arrays when storing the same amount of data.*/

// Linked List Node Structure
struct ListNode {     // Defining the name
    int val;                // Node value. "Every 'ListNode' has an int named 'val'"
    ListNode* next;  // Pointer to next node. "Every 'ListNode' has a pointer to another 'ListNode'", also callled as self-referential pointer
    ListNode(int x) : val(x), next(nullptr) {} // Constructor
    // "When I create a new ListNode with a value, set val = x and next = nullptr."
};

/* Visual Representation
struct ListNode {
    int val;                       ← stores the value (e.g. 5)
    ListNode* next;          ← stores address of next node (or null)
    ListNode(int x)           ← shortcut to set both at once
        : val(x), next(nullptr) {}
};
*/

/* --> 4.2.1 Common Linked List Operations
1. Initializing a Linked List
* Building alinkedlist involves two steps:
* first, initializing each nodeobject;
* second, constructing the reference relationships between nodes.
Once initialization is complete,
we can traverse all nodes starting from the head node of the linked list through the reference 'next'
*/

int main(){

    // Initialize Linked List:  1 -> 3 -> 2 -> 5 -> 4
    // Initialize each node
    ListNode* n0 = new ListNode(1);
    ListNode* n1 = new ListNode(3);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(5);
    ListNode* n4 = new ListNode(4);
    // Build references between nodes
    n0 -> next = n1;
    n1 -> next = n2;
    n2 -> next = n3;
    n3 -> next = n4;

    return 0;
}

