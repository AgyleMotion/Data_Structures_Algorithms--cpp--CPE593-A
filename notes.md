

 * Singly linked list : Data structure that stores elements in a linear order where each element points to the next one.
 * Node : is a self referential structure that contains a pointer to a structure of the same type.
 * Head : a pointer that points to the struct node is declared. The head pointer is initialized to NULL
 * Traversing linked list means visiting each node of a single linked list untill the end is reached.
 * It requires creating a temp node is not null, display its content and move to the next node using temp ->link.
 * Inserting a node at the end: traverse to the end of the node.
 * Update the link part of the end node.
 * Inserting new node at the begining.
 * Inserting a node at certain position.
 * Deleting the first node, Head should points to the second node.
 * There should be a pointer for the first node as we need to free the memory for the node.
 * Deleting the second last node of the list using a pointer.
 * Deleting a node at certain position.
 * Deleting the entire single linked list.
 * 
 * ------------- Array vs Linked List ---------------
 * Cost of accessing an element : Array -> Time complexity : O(1)., Linked list, : Time complexity O(n)
 * Array can have unused memory, Linked list: No unused memory, extra memory for a pointer variable.
 * Cost of inserting an element:
 * Array -> at the begin O(n), at the end o(1) if the array is not full., o(n) if the array is full., at position
 * n, o(n).
 *
 * Linked list : at the beginning, o(1), at the end o(n), at position o(n).
 * - Anything cost related to linked list  o(n) except inserting a node at the begining o(1)
 * - Anything cost related to linked list o(n) except accessing an array element or inserting an array element at the end if not full.
 * Doubly linked list: Linked list in which each node points to the next node and previous node.
 * Advantage does a doubly linked list have over a singly linked list : Faster traversal on both ends


