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

    void insert(int data) {
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

    void deleteAtBeginning() {
        if (head == NULL) {
            cout << "List is empty." << endl;
        } else {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void deleteAtEnd() {
        if (head == NULL) {
            cout << "List is empty." << endl;
        } else if (head->next == NULL) {
            delete head;
            head = NULL;
        } else {
            Node* temp = head;
            while (temp->next->next != NULL) {
                temp = temp->next;
            }
            delete temp->next;
            temp->next = NULL;
        }
    }

    void deleteAtPosition(int k) {
        if (head == NULL || k <= 0) {
            cout << "Invalid position or list is empty." << endl;
        } else if (k == 1) {
            deleteAtBeginning();
        } else {
            Node* temp = head;
            for (int i = 1; i < k - 1 && temp != NULL; i++) {
                temp = temp->next;
            }
            if (temp == NULL || temp->next == NULL) {
                cout << "Position out of bounds." << endl;
            } else {
                Node* nodeToDelete = temp->next;
                temp->next = temp->next->next;
                delete nodeToDelete;
            }
        }
    }

    void display() {
        if (head == NULL) {
            cout << "List is empty." << endl;
        } else {
            Node* temp = head;
            while (temp != NULL) {
                cout << temp->data << " -> ";
                temp = temp->next;
            }
            cout << "NULL" << endl;
        }
    }
};

int main() {
    LinkedList list;
    
    list.insert(1);
    list.insert(2);
    list.insert(5);
    list.insert(7);
    list.insert(4);

    cout << "Original List: ";
    list.display();

    list.deleteAtBeginning();
    cout << "After deleting at beginning: ";
    list.display();

    list.deleteAtEnd();
    cout << "After deleting at end: ";
    list.display();

    int k = 3;
    list.deleteAtPosition(k);
    cout << "After deleting at position " << k << ": ";
    list.display();

    return 0;
}
