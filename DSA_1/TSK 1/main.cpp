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

    void printMul(int k=3) {
        Node* current = head;
        int index = 0;
        while (current != NULL) {
            if (index % k == 0) {
                cout << current->data << " ";
            }
            current = current->next;
            index++;
        }
    }
};

int main() {
    LinkedList list;

    list.insert(12);
    list.insert(15);
    list.insert(18);
    list.insert(17);
    list.insert(19);
    list.insert(20);
    list.insert(22);


    list.printMul();

    return 0;
}
