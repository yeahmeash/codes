Approach: We have discussed a solution here where we used recursion to reach to the least significant number in the lists, but due to the involvement of the stack, the space complexity of the solution becomes O(N)
Here the target is to do the sum inplace, and return the modified sum list.

The idea is to first reverse both the linked list, so new head of the list points to least significant number and we can start adding as described here and instead of creating a new list, we modify the existing one and return the head of modified list.

Following are the steps: 

Reverse List L1.
Reverse List L2.
Add the nodes of both the lists iteratively.
Reverse the resultant list and return its head.
Below is the implementation of the above approac

// C++ implementation of the approach
#include <iostream>
using namespace std;

class LinkedList;

// Node class for the linked list
class Node {
	int data;
	Node* next;

	friend LinkedList;

public:
	Node();
	Node(int x);
};

Node::Node()
{
	data = 0;
	next = NULL;
}

// Function to initialise
// a node with value x
Node::Node(int x)
{
	data = x;
	next = NULL;
}

// Linkedlist class with helper functions
class LinkedList {
public:
	Node* head;

	LinkedList();

	void insert(int x);
	void reverse();
	void traverse();

	void sum(LinkedList*);
};

LinkedList::LinkedList()
{
	head = NULL;
}

// Function to insert a node at
// the head of the list
void LinkedList::insert(int x)
{
	Node* node = new Node();
	node->data = x;

	if (head == NULL)
		head = node;
	else {
		node->next = head;
		head = node;
	}
}

// Function to reverse the linked list
void LinkedList::reverse()
{
	Node *prev = NULL, *curr = head;

	while (curr) {
		Node* temp = curr->next;
		curr->next = prev;
		prev = curr;
		curr = temp;
	}
	head = prev;
}

// Function to traverse and print the list
void LinkedList::traverse()
{

	Node* temp = head;

	while (temp) {
		cout << temp->data << " -> ";
		temp = temp->next;
	}
	cout << "NULL";
}

// Function to add two numbers
// represented as linked lists
void LinkedList::sum(LinkedList* l2)
{
	reverse();
	l2->reverse();

	Node *start1 = head, *start2 = l2->head;

	Node* prev = NULL;
	int carry = 0;

	// While both lists exist
	while (start1 && start2) {

		// Current sum
		int temp = start1->data + start2->data + carry;

		// Handle carry
		start1->data = temp % 10;
		carry = temp / 10;
		prev = start1;

		// Get to next nodes
		start1 = start1->next;
		start2 = start2->next;
	}

	// If there are remaining digits
	// in any one of the lists
	if (start1 || start2) {

		if (start2)
			prev->next = start2;

		start1 = prev->next;

		// While first list has digits remaining
		while (start1) {
			int temp = start1->data + carry;
			start1->data = temp % 10;
			carry = temp / 10;
			prev = start1;
			start1 = start1->next;
		}
	}

	// If a new node needs to be
	// created due to carry
	if (carry > 0) {
		prev->next = new Node(carry);
	}

	// Reverse the resultant list
	reverse();
}

// Driver code
int main()
{

	// Create first list
	LinkedList* l1 = new LinkedList();
	l1->insert(3);
	l1->insert(6);
	l1->insert(5);

	// Create second list
	LinkedList* l2 = new LinkedList();
	l2->insert(2);
	l2->insert(4);
	l2->insert(8);

	// Add the lists
	l1->sum(l2);

	// Print the resultant list
	l1->traverse();

	return 0;
}
