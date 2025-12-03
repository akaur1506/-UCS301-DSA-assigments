#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
public:
    Node* head;

    LinkedList() { head = NULL; }

    void insertBeginning(int value) {
        Node* temp = new Node{value, head};
        head = temp;
    }

    void insertEnd(int value) {
        Node* temp = new Node{value, NULL};
        if (!head) { head = temp; return; }
        Node* curr = head;
        while (curr->next) curr = curr->next;
        curr->next = temp;
    }

    void insertBefore(int target, int value) {
        if (!head) return;
        if (head->data == target) { insertBeginning(value); return; }
        Node* curr = head;
        while (curr->next && curr->next->data != target)
            curr = curr->next;
        if (curr->next) {
            Node* temp = new Node{value, curr->next};
            curr->next = temp;
        }
    }

    void insertAfter(int target, int value) {
        Node* curr = head;
        while (curr && curr->data != target)
            curr = curr->next;
        if (curr) {
            Node* temp = new Node{value, curr->next};
            curr->next = temp;
        }
    }

    void deleteBeginning() {
        if (!head) return;
        Node* t = head;
        head = head->next;
        delete t;
    }

    void deleteEnd() {
        if (!head) return;
        if (!head->next) { delete head; head = NULL; return; }
        Node* curr = head;
        while (curr->next->next)
            curr = curr->next;
        delete curr->next;
        curr->next = NULL;
    }

    void deleteSpecific(int value) {
        if (!head) return;
        if (head->data == value) { deleteBeginning(); return; }
        Node* curr = head;
        while (curr->next && curr->next->data != value)
            curr = curr->next;
        if (curr->next) {
            Node* t = curr->next;
            curr->next = curr->next->next;
            delete t;
        }
    }

    int search(int value) {
        Node* curr = head;
        int pos = 1;
        while (curr) {
            if (curr->data == value) return pos;
            curr = curr->next; pos++;
        }
        return -1;
    }

    void display() {
        Node* curr = head;
        while (curr) {
            cout << curr->data;
            if (curr->next) cout << "->";
            curr = curr->next;
        }
        cout << endl;
    }

    int countOccurrences(int key) {
        int count = 0;
        Node* curr = head;
        while (curr) {
            if (curr->data == key) count++;
            curr = curr->next;
        }
        return count;
    }

    void deleteAllOccurrences(int key) {
        while (head && head->data == key)
            deleteBeginning();
        Node* curr = head;
        while (curr && curr->next) {
            if (curr->next->data == key) {
                Node* t = curr->next;
                curr->next = curr->next->next;
                delete t;
            } else curr = curr->next;
        }
    }

    int findMiddle() {
        if (!head) return -1;
        Node* slow = head;
        Node* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow->data;
    }

    void reverse() {
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }
};

int main() {
    LinkedList list;
    int choice, value, target;

    while (true) {
        cout << "\n1.Insert Beginning\n2.Insert End\n3.Insert Before\n4.Insert After\n5.Delete Beginning\n6.Delete End\n7.Delete Specific\n8.Search\n9.Display\n10.Count & Delete Occurrences\n11.Find Middle\n12.Reverse\n13.Exit\n";
        cin >> choice;

        if (choice == 1) { cin >> value; list.insertBeginning(value); }
        else if (choice == 2) { cin >> value; list.insertEnd(value); }
        else if (choice == 3) { cin >> value >> target; list.insertBefore(target, value); }
        else if (choice == 4) { cin >> value >> target; list.insertAfter(target, value); }
        else if (choice == 5) list.deleteBeginning();
        else if (choice == 6) list.deleteEnd();
        else if (choice == 7) { cin >> value; list.deleteSpecific(value); }
        else if (choice == 8) { cin >> value; cout << list.search(value) << endl; }
        else if (choice == 9) list.display();
        else if (choice == 10) {
            cin >> value;
            cout << list.countOccurrences(value) << endl;
            list.deleteAllOccurrences(value);
        }
        else if (choice == 11) cout << list.findMiddle() << endl;
        else if (choice == 12) list.reverse();
        else if (choice == 13) break;
    }

    return 0;
}
