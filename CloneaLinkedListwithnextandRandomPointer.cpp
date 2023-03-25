// C++ code to implement the approach

#include <bits/stdc++.h>
using namespace std;



struct Node {
	int data;
	Node *next, *random;
	Node(int x) {
		data = x;
		next = random = NULL;
	}
};

Node* cloneLinkedList(Node* head) {
	if (head == NULL) {
		return NULL;
	}
	
	// Step 1: Create new nodes and insert them next to the original nodes
	Node* curr = head;
	while (curr != NULL) {
		Node* newNode = new Node(curr->data);
		newNode->next = curr->next;
		curr->next = newNode;
		curr = newNode->next;
	}
	
	// Step 2: Set the random pointers of the new nodes
	curr = head;
	while (curr != NULL) {
		if (curr->random != NULL) {
			curr->next->random = curr->random->next;
		}
		curr = curr->next->next;
	}
	
	// Step 3: Separate the new nodes from the original nodes
	curr = head;
	Node* clonedHead = head->next;
	Node* clonedCurr = clonedHead;
	while (clonedCurr->next != NULL) {
		curr->next = curr->next->next;
		clonedCurr->next = clonedCurr->next->next;
		curr = curr->next;
		clonedCurr = clonedCurr->next;
	}
	curr->next = NULL;
	clonedCurr->next = NULL;
	
	return clonedHead;
}


// Function to print the linked list
void printList(Node* head)
{
	cout << head->data << "("
		<< head->random->data << ")";
	head = head->next;
	while (head != NULL) {
		cout << " -> " << head->data << "("
			<< head->random->data << ")";
		head = head->next;
	}
	cout << endl;
}

// Driver code
int main()
{
	// Creating a linked list with random pointer
	Node* head = new Node(1);
	head->next = new Node(2);
	head->next->next = new Node(3);
	head->next->next->next = new Node(4);
	head->next->next->next->next
		= new Node(5);
	head->random = head->next->next;
	head->next->random = head;
	head->next->next->random
		= head->next->next->next->next;
	head->next->next->next->random
		= head->next->next;
	head->next->next->next->next->random
		= head->next;
	
	// Print the original list
	cout << "The original linked list:\n";
	printList(head);
	
	// Function call
	Node* sol = cloneLinkedList(head);
	
	cout << "The cloned linked list:\n";
	printList(sol);
	
	return 0;
}
