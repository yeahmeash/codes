#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* next;
};

void linkedListTraversal(Node* ptr)
{
    while (ptr != NULL)
    {
        cout << "Element: " << ptr->data << endl;
        ptr = ptr->next;
    }
}

// Case 1: Deleting the first element from the linked list
Node* deleteFirst(Node* head){
    Node* ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

// Case 2: Deleting the element at a given index from the linked list
Node* deleteAtIndex(Node* head, int index){
    Node* p = head;
    Node* q = head->next;
    for (int i = 0; i < index-1; i++)
    {
        p = p->next;
        q = q->next;
    }
    
    p->next = q->next;
    free(q);
    return head;
}

// Case 3: Deleting the last element
Node* deleteAtLast(Node* head){
    Node* p = head;
    Node* q = head->next;
    while(q->next !=NULL)
    {
        p = p->next;
        q = q->next;
    }
    
    p->next = NULL;
    free(q);
    return head;
}

// Case 4: Deleting the element with a given value from the linked list
Node* deleteWithValue(Node* head, int value){
    Node* p = head;
    Node* q = head->next;
    while(q->data!=value && q->next!= NULL)
    {
        p = p->next;
        q = q->next;
    }
    
    if(q->data == value){
        p->next = q->next;
        free(q);
    }
    return head;
}

int main()
{
    Node* head = nullptr;
    Node* second = nullptr;
    Node* third = nullptr;
    Node* fourth = nullptr;

    // Allocate memory for nodes in the linked list in Heap
    head = new Node();
    second = new Node();
    third = new Node();
    fourth = new Node();

    // Link first and second nodes
    head->data = 4;
    head->next = second;

    // Link second and third nodes
    second->data = 3;
    second->next = third;

    // Link third and fourth nodes
    third->data = 8;
    third->next = fourth;

    // Terminate the list at the third node
    fourth->data = 1;
    fourth->next = nullptr;

    cout << "Linked list before deletion" << endl;
    linkedListTraversal(head);

    // head = deleteFirst(head); // For deleting first element of the linked list
    // head = deleteAtIndex(head, 2);
    head = deleteAtLast(head);
    cout << "Linked list after deletion" << endl;
    linkedListTraversal(head);

    return 0;
}

// java

public class Main {
    static class Node {
        int data;
        Node next;

        Node(int data) {
            this.data = data;
            this.next = null;
        }
    }

    static void linkedListTraversal(Node head) {
        while (head != null) {
            System.out.println("Element: " + head.data);
            head = head.next;
        }
    }

    // Case 1: Deleting the first element from the linked list
    static Node deleteFirst(Node head) {
        Node ptr = head;
        head = head.next;
        ptr.next = null;
        return head;
    }

    // Case 2: Deleting the element at a given index from the linked list
    static Node deleteAtIndex(Node head, int index) {
        Node p = head;
        Node q = head.next;
        for (int i = 0; i < index - 1; i++) {
            p = p.next;
            q = q.next;
        }

        p.next = q.next;
        q.next = null;
        return head;
    }

    // Case 3: Deleting the last element
    static Node deleteAtLast(Node head) {
        Node p = head;
        Node q = head.next;
        while (q.next != null) {
            p = p.next;
            q = q.next;
        }

        p.next = null;
        q.next = null;
        return head;
    }

    // Case 4: Deleting the element with a given value from the linked list
    static Node deleteWithValue(Node head, int value) {
        Node p = head;
        Node q = head.next;
        while (q != null && q.data != value) {
            p = p.next;
            q = q.next;
        }

        if (q != null && q.data == value) {
            p.next = q.next;
            q.next = null;
        }
        return head;
    }

    public static void main(String[] args) {
        Node head = new Node(4);
        Node second = new Node(3);
        Node third = new Node(8);
        Node fourth = new Node(1);

        // Link first and second nodes
        head.next = second;

        // Link second and third nodes
        second.next = third;

        // Link third and fourth nodes
        third.next = fourth;

        System.out.println("Linked list before deletion");
        linkedListTraversal(head);

        // head = deleteFirst(head); // For deleting first element of the linked list
        // head = deleteAtIndex(head, 2);
        head = deleteAtLast(head);
        System.out.println("Linked list after deletion");
        linkedListTraversal(head);
    }
}
