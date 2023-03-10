#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
};

void linkedListTraversal(Node* ptr)
{
    while (ptr != nullptr)
    {
        cout << "Element: " << ptr->data << endl;
        ptr = ptr->next;
    }
}

// Case 1
Node* insertAtFirst(Node* head, int data){
    Node* ptr = new Node;
    ptr->data = data;

    ptr->next = head;
    return ptr; 
}

// Case 2
Node* insertAtIndex(Node* head, int data, int index){
    Node* ptr = new Node;
    Node* p = head;
    int i = 0;

    while (i != index-1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

// Case 3
Node* insertAtEnd(Node* head, int data){
    Node* ptr = new Node;
    ptr->data = data;
    Node* p = head;

    while(p->next != nullptr){
        p = p->next;
    }
    p->next = ptr;
    ptr->next = nullptr;
    return head;
}

// Case 4
Node* insertAfterNode(Node* head, Node* prevNode, int data){
    Node* ptr = new Node;
    ptr->data = data;

    ptr->next = prevNode->next;
    prevNode->next = ptr;

    return head;
}


int main(){
    Node* head;
    Node* second;
    Node* third;
    Node* fourth;

    // Allocate memory for nodes in the linked list in Heap
    head = new Node;
    second = new Node;
    third = new Node;
    fourth = new Node;

    // Link first and second nodes
    head->data = 7;
    head->next = second;

    // Link second and third nodes
    second->data = 11;
    second->next = third;

    // Link third and fourth nodes
    third->data = 41;
    third->next = fourth;

    // Terminate the list at the third node
    fourth->data = 66;
    fourth->next = nullptr;

    cout << "Linked list before insertion\n";
    linkedListTraversal(head);
    // head = insertAtFirst(head, 56);
    // head = insertAtIndex(head, 56, 1);
    // head = insertAtEnd(head, 56);
    head = insertAfterNode(head, third, 45);
    cout << "\nLinked list after insertion\n";
    linkedListTraversal(head);

    return 0;
}
public class LinkedList {
    
    private Node head;

    private static class Node {
        int data;
        Node next;

        Node(int data) {
            this.data = data;
            this.next = null;
        }
    }

    // Insert at the beginning
    public void insertAtFirst(int data) {
        Node newNode = new Node(data);
        newNode.next = head;
        head = newNode;
    }

    // Insert at a specified index
    public void insertAtIndex(int data, int index) {
        if (index == 0) {
            insertAtFirst(data);
            return;
        }

        Node newNode = new Node(data);
        Node current = head;
        int i = 0;
        while (current != null && i < index - 1) {
            current = current.next;
            i++;
        }

        if (current == null) {
            System.out.println("Invalid index");
            return;
        }

        newNode.next = current.next;
        current.next = newNode;
    }

    // Insert at the end
    public void insertAtEnd(int data) {
        Node newNode = new Node(data);

        if (head == null) {
            head = newNode;
            return;
        }

        Node current = head;
        while (current.next != null) {
            current = current.next;
        }

        current.next = newNode;
    }

    // Insert after a specified node
    public void insertAfterNode(Node prevNode, int data) {
        if (prevNode == null) {
            System.out.println("Invalid previous node");
            return;
        }

        Node newNode = new Node(data);
        newNode.next = prevNode.next;
        prevNode.next = newNode;
    }

    // Print the linked list
    public void printList() {
        Node current = head;

        while (current != null) {
            System.out.print(current.data + " ");
            current = current.next;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        LinkedList list = new LinkedList();
        list.insertAtEnd(7);
        list.insertAtEnd(11);
        list.insertAtEnd(41);
        list.insertAtEnd(66);

        System.out.println("Linked list before insertion:");
        list.printList();

        list.insertAtFirst(56);
        list.insertAtIndex(56, 1);
        list.insertAtEnd(56);
        list.insertAfterNode(list.head.next.next, 45);

        System.out.println("\nLinked list after insertion:");
        list.printList();
    }
}
