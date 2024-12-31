#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    
    Node(int val) {
        data = val;
        next = NULL;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    void insertAtBeginning(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int data) {
        Node* newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void insertAtPosition(int data, int k) {
        if (k <= 0) {
            cout << "Invalid position." << endl;
            return;
        }
        if (k == 1) {
            insertAtBeginning(data);
            return;
        }

        Node* newNode = new Node(data);
        Node* temp = head;
        for (int i = 1; i < k - 1 && temp != NULL; i++) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Position out of bounds." << endl;
            delete newNode;  // Clean up the allocated memory
        } else {
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    void display() {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    LinkedList list;
    
    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(5);
    list.insertAtEnd(7);
    list.insertAtEnd(4);

    cout << "Original List: ";
    list.display();

    int value = 8;
    int k = 4;
    list.insertAtPosition(value, k);
    cout << "After inserting " << value << " at position " << k << ": ";
    list.display();

    int newValue = 10;
    list.insertAtBeginning(newValue);
    cout << "After inserting " << newValue << " at the beginning: ";
    list.display();

    return 0;
}
