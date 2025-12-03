#include <iostream>
using namespace std;

struct DNode {
    int data;
    DNode* prev;
    DNode* next;
};

class DoublyLinkedList {
public:
    DNode* head;

    DoublyLinkedList() {
        head = NULL;
    }

    void insertFirst(int value) {
        DNode* temp = new DNode{ value, NULL, head };
        if (head)
            head->prev = temp;
        head = temp;
    }

    void insertLast(int value) {
        DNode* temp = new DNode{ value, NULL, NULL };
        if (!head) {
            head = temp;
            return;
        }
        DNode* t = head;
        while (t->next)
            t = t->next;
        t->next = temp;
        temp->prev = t;
    }

    void insertAfter(int key, int value) {
        DNode* t = head;
        while (t && t->data != key)
            t = t->next;
        if (!t) return;
        DNode* temp = new DNode{ value, t, t->next };
        if (t->next)
            t->next->prev = temp;
        t->next = temp;
    }

    void insertBefore(int key, int value) {
        if (!head) return;
        if (head->data == key) {
            insertFirst(value);
            return;
        }
        DNode* t = head;
        while (t && t->data != key)
            t = t->next;
        if (!t) return;
        DNode* temp = new DNode{ value, t->prev, t };
        t->prev->next = temp;
        t->prev = temp;
    }

    void deleteNode(int key) {
        if (!head) return;
        DNode* t = head;
        while (t && t->data != key)
            t = t->next;
        if (!t) return;
        if (t->prev)
            t->prev->next = t->next;
        else
            head = t->next;
        if (t->next)
            t->next->prev = t->prev;
        delete t;
    }

    bool search(int key) {
        DNode* t = head;
        while (t) {
            if (t->data == key) return true;
            t = t->next;
        }
        return false;
    }

    void display() {
        DNode* t = head;
        while (t) {
            cout << t->data << " ";
            t = t->next;
        }
        cout << endl;
    }

    int size() {
        int count = 0;
        DNode* t = head;
        while (t) {
            count++;
            t = t->next;
        }
        return count;
    }

    bool isPalindrome() {
        if (!head) return true;
        DNode* left = head;
        DNode* right = head;
        while (right->next)
            right = right->next;
        while (left != right && right->next != left) {
            if (left->data != right->data)
                return false;
            left = left->next;
            right = right->prev;
        }
        return true;
    }
};

struct CNode {
    int data;
    CNode* next;
};

class CircularLinkedList {
public:
    CNode* head;

    CircularLinkedList() {
        head = NULL;
    }

    void insertFirst(int value) {
        CNode* temp = new CNode{ value, NULL };
        if (!head) {
            head = temp;
            temp->next = head;
            return;
        }
        CNode* t = head;
        while (t->next != head)
            t = t->next;
        t->next = temp;
        temp->next = head;
        head = temp;
    }

    void insertLast(int value) {
        CNode* temp = new CNode{ value, NULL };
        if (!head) {
            head = temp;
            temp->next = head;
            return;
        }
        CNode* t = head;
        while (t->next != head)
            t = t->next;
        t->next = temp;
        temp->next = head;
    }

    void insertAfter(int key, int value) {
        if (!head) return;
        CNode* t = head;
        do {
            if (t->data == key) {
                CNode* temp = new CNode{ value, t->next };
                t->next = temp;
                return;
            }
            t = t->next;
        } while (t != head);
    }

    void deleteNode(int key) {
        if (!head) return;
        CNode* curr = head;
        CNode* prev = NULL;
        do {
            if (curr->data == key) {
                if (curr == head) {
                    CNode* t = head;
                    while (t->next != head)
                        t = t->next;
                    head = head->next;
                    t->next = head;
                } else {
                    prev->next = curr->next;
                }
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        } while (curr != head);
    }

    bool search(int key) {
        if (!head) return false;
        CNode* t = head;
        do {
            if (t->data == key) return true;
            t = t->next;
        } while (t != head);
        return false;
    }

    void displayWithHeadRepeated() {
        if (!head) return;
        CNode* t = head;
        do {
            cout << t->data << " ";
            t = t->next;
        } while (t != head);
        cout << head->data << endl;
    }

    int size() {
        if (!head) return 0;
        int count = 0;
        CNode* t = head;
        do {
            count++;
            t = t->next;
        } while (t != head);
        return count;
    }
};

bool isCircular(CNode* head) {
    if (!head) return true;
    CNode* t = head->next;
    while (t && t != head)
        t = t->next;
    return t == head;
}

int main() {
    DoublyLinkedList dll;
    CircularLinkedList cll;

    dll.insertFirst(30);
    dll.insertLast(50);
    dll.insertAfter(30, 40);
    dll.insertBefore(50, 45);

    cout << "Doubly Linked List: ";
    dll.display();

    dll.deleteNode(40);
    cout << "After Deletion: ";
    dll.display();

    cout << "Search 45: " << (dll.search(45) ? "Found" : "Not Found") << endl;
    cout << "DLL Size: " << dll.size() << endl;

    dll.insertLast(30);
    cout << "DLL Palindrome: " << (dll.isPalindrome() ? "Yes" : "No") << endl;

    cll.insertFirst(100);
    cll.insertLast(200);
    cll.insertLast(300);
    cll.insertAfter(200, 250);

    cout << "Circular Linked List: ";
    cll.displayWithHeadRepeated();

    cll.deleteNode(250);

    cout << "After Deletion: ";
    cll.displayWithHeadRepeated();

    cout << "Search 300: " << (cll.search(300) ? "Found" : "Not Found") << endl;
    cout << "CLL Size: " << cll.size() << endl;

    cout << "Is Circular: " << (isCircular(cll.head) ? "Yes" : "No") << endl;

    return 0;
}
