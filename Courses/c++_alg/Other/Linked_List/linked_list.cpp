#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* next;

    Node(int value) {
        this->value = value;
        next = nullptr;
    }

    void setnext(Node* next) {
        this->next = next;
    }
};

class LinkedList {
private:
    Node* head;
    Node* tail;
    int length;

public:
    LinkedList(int value) {
        head = new Node(value);
        tail = head;  
        length = 1;
    }

    void append(int value) {
        Node* nextNode = new Node(value);
        if (length != 0) {
            tail->setnext(nextNode);  
            tail = nextNode;          
            length++;
        } else {
            head = nextNode;
            tail = nextNode;
        }
    }

    void printList() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->value << " -> ";
            current = current->next;
        }
        cout << "nullptr" << endl;
    }

    void delete_last() {
        if (length == 0) {
            cout << "List is empty" << endl;
            return;
        }

        if (length == 1) {
            delete tail;
            head = nullptr;
            tail = nullptr;
            length--;
            return;
        }

        Node* element = head;
        while (element->next != tail) {
            element = element->next;
        }

        delete tail;
        tail = element;
        tail->next = nullptr;
        length--;
    }

    void prepend(int value) {
        Node* newNode = new Node(value);
        if (length == 0) {
            head = newNode;
            tail = newNode;
        } else {
        newNode->next = head;
        head = newNode;
        }

        length++;
    }

    void delete_first() {
        if (length == 0) return;
        if (length == 1) {
            head = nullptr;
            tail = nullptr;
            length--;
        } else {
            Node* element = head;
            head = element->next;
            delete element;
            length--;
        }
    }

    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextnode = current->next;
            delete current;
            current = nextnode;
        }
        head = nullptr;
        tail = nullptr;
    }   

};

int main() {
    LinkedList* mylist = new LinkedList(54); 

    mylist->append(100);
    mylist->append(200);

    cout << "My linked list: ";
    mylist->printList();
    mylist->delete_last();
    mylist->printList();

    delete mylist; 

    return 0;
}





