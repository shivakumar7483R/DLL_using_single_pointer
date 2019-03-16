Doubly Linked List Implementation Using Single Pointer.

Normal Doubly Linked List requires memory of two address fields to store the addresses of previous and next nodes but using single ponter we can implement Doubly Linked List by storing XOR of addresses of previous and next nodes in single pointer.

struct dll{
	int data;
	struct dll *diff; // To store XOR of addresses of previous and next nodes.
};

To find next node:- XOR of current diff value and address of previous node.

ADT Operation of Doubly Linked List Using Single Pointer.
1. Add element to linked list at last
2. display elements in linked list from front
3. remove element in linked list from  front
