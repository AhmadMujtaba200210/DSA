#include<iostream>
using namespace std;

class Node {

public:
    int data;
    Node* next;
    Node(int d) :data(d), next(NULL) {}
    int getData() {
        return data;
    }
};

class LinkedList {

    Node* head;
    Node* tail;

public:
    LinkedList() :head(NULL), tail(NULL) {}
    Node* find(Node* Temp) {
        Node* temp1 = head;
        while (temp1->next != Temp)
        {
            temp1 = temp1->next;
        }

        return temp1;
    }
    void push_front(int data) {
        if (head == NULL) {
            Node* n = new Node(data);
            head = tail = n;
        }
        else {
            Node* n = new Node(data);
            n->next = head;
            head = n;
        }
    }

    void push_back(int data) {
        Node* n = new Node(data);
        Node* temp = tail;
        if (head == NULL) {
            tail = head = n;
            return;
        }

        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = n;
        tail = n;
    }
    void show() {
        cout << "Head:" << head->getData() << endl;
        cout << "Tail:" << tail->getData() << endl;
    }
    void insert(int data, int pos) {
        Node* n = new Node(data);
        Node* temp = head;
        for (int i = 0; i < pos - 1; i++) {
            temp = temp->next;
        }
        n->next = temp->next;
        temp->next = n;
    }
    void del_front() {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void del_back() {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        Node* temp2 = find(temp);

        tail = temp2;
        tail->next = NULL;
        delete temp;
    }

    void del_pos(int pos) {
        Node* temp = head;
        Node* temp1 = head;
        Node* temp2 = head;
        for (int i = 0; i < pos - 1; i++) {
            temp = temp->next;
        }
        for (int i = 0; i < pos + 1; i++) {
            temp1 = temp1->next;
        }
        for (int i = 0; i < pos; i++) {
            temp2 = temp2->next;
        }

        temp->next = temp1;
        delete temp2;
    }

    void sortList() {
        struct Node* current = head, * index = NULL;
        int temp;

        if (head == NULL) {
            return;
        }
        else {
            while (current != NULL) {
                index = current->next;

                while (index != NULL) {
                    if (current->data > index->data) {
                        temp = current->data;
                        current->data = index->data;
                        index->data = temp;
                    }
                    index = index->next;
                }
                current = current->next;
            }
        }
    }
    void print() {
        Node* printLL = head;
        while (printLL != NULL) {
            cout << printLL->getData() << "=>";
            printLL = printLL->next;
        }
        cout << "NULL\n";
    }
};

int main() {

    LinkedList l;
    for (int i = 0; i < 10; i++) {
        int n = rand() % 10;
        l.push_front(n);
    }
    // l.push_front(4);
    // l.push_front(5);
    // l.push_back(6);
    // l.insert(2,1);
    // // l.del_back();
    // //l.del_front();
    // l.del_pos(1);
    cout << "Before Sorting:" << endl;
    l.print();
    l.show();
    cout << "After Sorting:" << endl;
    l.sortList();
    l.print();
    l.show();
}