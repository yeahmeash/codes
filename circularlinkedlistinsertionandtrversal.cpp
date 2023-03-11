#include <iostream>

struct Node
{
    int data;
    Node *next;
};

void linkedListTraversal(Node *head)
{
    Node *ptr = head;
    do
    {
        std::cout << "Element is " << ptr->data << std::endl;
        ptr = ptr->next;
    } while (ptr != head);
}

Node *insertAtFirst(Node *head, int data)
{
    Node *ptr = new Node();
    ptr->data = data;

    Node *p = head->next;
    while (p->next != head)
    {
        p = p->next;
    }
    // At this point p points to the last node of this circular linked list

    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
}

int main()
{

    Node *head = NULL;
    Node *second = NULL;
    Node *third = NULL;
    Node *fourth = NULL;

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
    third->data = 6;
    third->next = fourth;

    // Terminate the list at the third node
    fourth->data = 1;
    fourth->next = head;

    std::cout << "Circular linked list before insertion" << std::endl;
    linkedListTraversal(head);

    head = insertAtFirst(head, 8);
    std::cout << "Circular linked list after insertion" << std::endl;
    linkedListTraversal(head);

    return 0;
}
//java

class Node {
    int data;
    Node next;
}

public class Main {
    public static void linkedListTraversal(Node head) {
        Node ptr = head;
        do {
            System.out.println("Element is " + ptr.data);
            ptr = ptr.next;
        } while (ptr != head);
    }

    public static Node insertAtFirst(Node head, int data) {
        Node ptr = new Node();
        ptr.data = data;

        Node p = head.next;
        while (p.next != head) {
            p = p.next;
        }

        p.next = ptr;
        ptr.next = head;
        head = ptr;
        return head;
    }

    public static void main(String[] args) {
        Node head = new Node();
        Node second = new Node();
        Node third = new Node();
        Node fourth = new Node();

        // Link first and second nodes
        head.data = 4;
        head.next = second;

        // Link second and third nodes
        second.data = 3;
        second.next = third;

        // Link third and fourth nodes
        third.data = 6;
        third.next = fourth;

        // Terminate the list at the third node
        fourth.data = 1;
        fourth.next = head;
    }
}

