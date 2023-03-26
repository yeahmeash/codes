// video code in java


 package linkedlist;

class Node {
  Node next;
  int data;
}

class Linked {
  /*
   * It rearrange the Linked list inplace 
   */
  public Node rearrangeLinkedListInPlace(Node head) {
    if(head == null || head.next == null || head.next.next == null) {
      return head;
    }
    
    Node middleNode = getMiddleNode(head);
    Node nextList = middleNode.next;
    middleNode.next = null;
    
    Node reversedList = reverse(nextList);
    Node firstList = head;
    
    Node finalList = new Node();
    Node node = finalList;
    
    while(firstList != null || reversedList != null) {
      
      if(firstList != null) {
        node.next = firstList;
        node = node.next;
        firstList = firstList.next;
      }
      
      if(reversedList != null) {
        node.next = reversedList;
        node = node.next;
        reversedList = reversedList.next;
      }
    }
    
    return finalList.next;
  }
  
  public Node getMiddleNode(Node node) {
    Node slow, fast;
    
    slow = fast = node;
    
    while(fast.next != null && fast.next.next != null) {
      slow = slow.next;
      fast = fast.next.next;
    }
    
    return slow;
  }
  
  public Node reverse(Node node) {
    if(node == null || node.next == null) {
      return node;
    }
    
    Node prev, next;
    prev = next = null;
    
    while(node != null) {
      next = node.next;
      node.next = prev;
      prev = node;
      node = next;
    }
    
    return prev;
  }
  
  /*
   * getNewNode() method to generate a new node
   */
  public Node getNewNode(int key) {
    Node a = new Node();
    a.next = null;
    a.data = key;
    return a;
  }

  /*
   * insert method is used to insert the element in Linked List
   */
  public Node insert(int key, Node node) {

    if (node == null)
      return getNewNode(key);
    else
      node.next = insert(key, node.next);

    return node;
  }

  /*
   * It'll print the complete linked list
   */
  public void printList(Node node) {
    if (node == null) {
      return;
    }

    System.out.print(node.data + " ");
    printList(node.next);
  }
}

public class LinkedListApp {
  public static void main(String[] args) {
    Linked a = new Linked();
    
    Node head = null;
    
    head = a.insert(1, head);
    head = a.insert(2, head);
    head = a.insert(3, head);
    head = a.insert(4, head);
    head = a.insert(5, head);
    head = a.insert(6, head);
    
    Node zigZagList = a.rearrangeLinkedListInPlace(head);
    a.printList(zigZagList);
    
  }
}
// c++
// C++ program to rearrange a linked list in-place
#include <bits/stdc++.h>
using namespace std;

// Linkedlist Node structure
struct Node {
	int data;
	struct Node* next;
};

// Function to create newNode in a linkedlist
Node* newNode(int key)
{
	Node* temp = new Node;
	temp->data = key;
	temp->next = NULL;
	return temp;
}

// Function to reverse the linked list
void reverselist(Node** head)
{
	// Initialize prev and current pointers
	Node *prev = NULL, *curr = *head, *next;

	while (curr) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	*head = prev;
}

// Function to print the linked list
void printlist(Node* head)
{
	while (head != NULL) {
		cout << head->data << " ";
		if (head->next)
			cout << "-> ";
		head = head->next;
	}
	cout << endl;
}

// Function to rearrange a linked list
void rearrange(Node** head)
{
	// 1) Find the middle point using tortoise and hare
	// method
	Node *slow = *head, *fast = slow->next;
	while (fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
	}
	// 2) Split the linked list in two halves
	// head1, head of first half 1 -> 2
	// head2, head of second half 3 -> 4
	Node* head1 = *head;
	Node* head2 = slow->next;
	slow->next = NULL;
	// 3) Reverse the second half, i.e., 4 -> 3
	reverselist(&head2);
	// 4) Merge alternate nodes
	*head = newNode(0); // Assign dummy Node
	// curr is the pointer to this dummy Node, which will
	// be used to form the new list
	Node* curr = *head;
	while (head1 || head2) {
		// First add the element from list
		if (head1) {
			curr->next = head1;
			curr = curr->next;
			head1 = head1->next;
		}
		// Then add the element from the second list
		if (head2) {
			curr->next = head2;
			curr = curr->next;
			head2 = head2->next;
		}
	}
	// Assign the head of the new list to head pointer
	*head = (*head)->next;
}

// Driver program
int main()
{
	Node* head = newNode(1);
	head->next = newNode(2);
	head->next->next = newNode(3);
	head->next->next->next = newNode(4);
	head->next->next->next->next = newNode(5);

	printlist(head); // Print original list
	rearrange(&head); // Modify the list
	printlist(head); // Print modified list
	return 0;
}

// This code is contributed by Aditya Kumar (adityakumar129)
