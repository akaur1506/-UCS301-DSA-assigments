// #include <iostream>
// using namespace std;

// class Queue {
// private:
//     int front, rear, size;
//     int* arr;

// public:
//     Queue(int s) {
//         size = s;
//         arr = new int[size];
//         front = -1;
//         rear = -1;
//     }

//     ~Queue() {
//         delete[] arr;
//     }

//     bool isEmpty() {
//         return (front == -1 || front > rear);
//     }

//     bool isFull() {
//         return (rear == size - 1);
//     }

//     void enqueue(int item) {
//         if (isFull()) {
//             cout << "Queue is Full! Cannot enqueue.\n";
//             return;
//         }
//         if (front == -1) {
//             front = 0;
//         }
//         rear++;
//         arr[rear] = item;
//         cout << "Enqueued: " << item << endl;
//     }

//     void dequeue() {
//         if (isEmpty()) {
//             cout << "Queue is Empty! Cannot dequeue.\n";
//             return;
//         }
//         cout << "Dequeued: " << arr[front] << endl;
//         front++;
//         if (front > rear) {
//             // Reset queue
//             front = rear = -1;
//         }
//     }

//     void peek() {
//         if (isEmpty()) {
//             cout << "Queue is Empty! No element to peek.\n";
//             return;
//         }
//         cout << "Front element: " << arr[front] << endl;
//     }

//     void display() {
//         if (isEmpty()) {
//             cout << "Queue is Empty!\n";
//             return;
//         }
//         cout << "Queue elements: ";
//         for (int i = front; i <= rear; i++) {
//             cout << arr[i] << " ";
//         }
//         cout << endl;
//     }
// };

// int main() {
//     int size;
//     cout << "Enter the size of the queue: ";
//     cin >> size;

//     Queue q(size);
//     int choice, item;

//     while (true) {
//         cout << "\n--- Queue Operations ---\n";
//         cout << "1. Enqueue\n";
//         cout << "2. Dequeue\n";
//         cout << "3. Peek\n";
//         cout << "4. Check if Empty\n";
//         cout << "5. Check if Full\n";
//         cout << "6. Display Queue\n";
//         cout << "7. Exit\n";
//         cout << "Enter your choice (1-7): ";
//         cin >> choice;

//         switch (choice) {
//             case 1:
//                 cout << "Enter item to enqueue: ";
//                 cin >> item;
//                 q.enqueue(item);
//                 break;
//             case 2:
//                 q.dequeue();
//                 break;
//             case 3:
//                 q.peek();
//                 break;
//             case 4:
//                 if (q.isEmpty())
//                     cout << "Queue is Empty.\n";
//                 else
//                     cout << "Queue is not Empty.\n";
//                 break;
//             case 5:
//                 if (q.isFull())
//                     cout << "Queue is Full.\n";
//                 else
//                     cout << "Queue is not Full.\n";
//                 break;
//             case 6:
//                 q.display();
//                 break;
//             case 7:
//                 cout << "Exiting program...\n";
//                 return 0;
//             default:
//                 cout << "Invalid choice! Please try again.\n";
//         }
//     }

//     return 0;
// }
// 2nd question 
// #include <iostream>
// using namespace std;

// class CircularQueue {
// private:
//     int front, rear, size;
//     int* arr;

// public:
//     CircularQueue(int s) {
//         size = s;
//         arr = new int[size];
//         front = -1;
//         rear = -1;
//     }

//     ~CircularQueue() {
//         delete[] arr;
//     }

//     bool isEmpty() {
//         return (front == -1);
//     }

//     bool isFull() {
//         return ((rear + 1) % size == front);
//     }

//     void enqueue(int item) {
//         if (isFull()) {
//             cout << "Queue is Full! Cannot enqueue.\n";
//             return;
//         }

//         if (isEmpty()) {
//             front = rear = 0;
//         } else {
//             rear = (rear + 1) % size;
//         }

//         arr[rear] = item;
//         cout << "Enqueued: " << item << endl;
//     }

//     void dequeue() {
//         if (isEmpty()) {
//             cout << "Queue is Empty! Cannot dequeue.\n";
//             return;
//         }

//         cout << "Dequeued: " << arr[front] << endl;

//         if (front == rear) {
//             // Queue becomes empty
//             front = rear = -1;
//         } else {
//             front = (front + 1) % size;
//         }
//     }

//     void peek() {
//         if (isEmpty()) {
//             cout << "Queue is Empty! No element to peek.\n";
//         } else {
//             cout << "Front element: " << arr[front] << endl;
//         }
//     }

//     void display() {
//         if (isEmpty()) {
//             cout << "Queue is Empty!\n";
//             return;
//         }

//         cout << "Queue elements: ";
//         int i = front;
//         while (true) {
//             cout << arr[i] << " ";
//             if (i == rear)
//                 break;
//             i = (i + 1) % size;
//         }
//         cout << endl;
//     }
// };

// int main() {
//     int size;
//     cout << "Enter the size of the circular queue: ";
//     cin >> size;

//     CircularQueue q(size);
//     int choice, item;

//     while (true) {
//         cout << "\n--- Circular Queue Operations ---\n";
//         cout << "1. Enqueue\n";
//         cout << "2. Dequeue\n";
//         cout << "3. Peek\n";
//         cout << "4. Check if Empty\n";
//         cout << "5. Check if Full\n";
//         cout << "6. Display Queue\n";
//         cout << "7. Exit\n";
//         cout << "Enter your choice (1-7): ";
//         cin >> choice;

//         switch (choice) {
//             case 1:
//                 cout << "Enter item to enqueue: ";
//                 cin >> item;
//                 q.enqueue(item);
//                 break;
//             case 2:
//                 q.dequeue();
//                 break;
//             case 3:
//                 q.peek();
//                 break;
//             case 4:
//                 if (q.isEmpty())
//                     cout << "Queue is Empty.\n";
//                 else
//                     cout << "Queue is not Empty.\n";
//                 break;
//             case 5:
//                 if (q.isFull())
//                     cout << "Queue is Full.\n";
//                 else
//                     cout << "Queue is not Full.\n";
//                 break;
//             case 6:
//                 q.display();
//                 break;
//             case 7:
//                 cout << "Exiting program...\n";
//                 return 0;
//             default:
//                 cout << "Invalid choice! Please try again.\n";
//         }
//     }

//     return 0;
// }
// 3rd question 
// #include <iostream>
// #include <queue>
// using namespace std;

// void interleaveQueue(queue<int>& q) {
//     int n = q.size();
//     if (n % 2 != 0) {
//         cout << "Queue has odd number of elements, cannot interleave properly.\n";
//         return;
//     }

//     int half = n / 2;
//     queue<int> firstHalf;

    
//     for (int i = 0; i < half; i++) {
//         firstHalf.push(q.front());
//         q.pop();
//     }

    
//     while (!firstHalf.empty()) {
//         q.push(firstHalf.front());
//         firstHalf.pop();

//         q.push(q.front());
//         q.pop();
//     }
// }

// int main() {
//     queue<int> q;
//     int n, x;

//     cout << "Enter number of elements: ";
//     cin >> n;

//     cout << "Enter elements: ";
//     for (int i = 0; i < n; i++) {
//         cin >> x;
//         q.push(x);
//     }

//     interleaveQueue(q);

//     cout << "Interleaved Queue: ";
//     while (!q.empty()) {
//         cout << q.front() << " ";
//         q.pop();
//     }
//     cout << endl;

//     return 0;
// }
// 4th question 
// #include <iostream>
// #include <queue>
// #include <unordered_map>
// using namespace std;

// void firstNonRepeating(string str) {
//     unordered_map<char, int> freq;
//     queue<char> q;

//     for (char ch : str) {
//         if (ch == ' ') continue;  
//         freq[ch]++;             
//         q.push(ch);               

        
//         while (!q.empty() && freq[q.front()] > 1) {
//             q.pop();
//         }

        
//         if (q.empty())
//             cout << "-1 ";
//         else
//             cout << q.front() << " ";
//     }
//     cout << endl;
// }

// int main() {
//     string input;
//     cout << "Enter a string: ";
//     getline(cin, input);

//     cout << "First non-repeating characters at each step: ";
//     firstNonRepeating(input);

//     return 0;
// }
//question 5
// stack using two queues 
// #include <iostream>
// #include <queue>
// using namespace std;

// class StackUsingTwoQueues {
//     queue<int> q1, q2;

// public:
//     void push(int x) {
//         q2.push(x);
//         while (!q1.empty()) {
//             q2.push(q1.front());
//             q1.pop();
//         }
//         swap(q1, q2);
//     }

//     void pop() {
//         if (q1.empty()) {
//             cout << "Stack Underflow\n";
//             return;
//         }
//         cout << "Popped: " << q1.front() << endl;
//         q1.pop();
//     }

//     void top() {
//         if (q1.empty()) {
//             cout << "Stack is Empty\n";
//             return;
//         }
//         cout << "Top element: " << q1.front() << endl;
//     }

//     bool empty() {
//         return q1.empty();
//     }

//     void display() {
//         if (q1.empty()) {
//             cout << "Stack is Empty\n";
//             return;
//         }
//         cout << "Stack elements (top to bottom): ";
//         queue<int> temp = q1;
//         while (!temp.empty()) {
//             cout << temp.front() << " ";
//             temp.pop();
//         }
//         cout << endl;
//     }
// };

// int main() {
//     StackUsingTwoQueues s;
//     int choice, val;

//     while (true) {
//         cout << "\n--- Stack using Two Queues ---\n";
//         cout << "1. Push\n2. Pop\n3. Top\n4. Display\n5. Exit\n";
//         cout << "Enter your choice: ";
//         cin >> choice;

//         switch (choice) {
//             case 1:
//                 cout << "Enter value to push: ";
//                 cin >> val;
//                 s.push(val);
//                 break;
//             case 2:
//                 s.pop();
//                 break;
//             case 3:
//                 s.top();
//                 break;
//             case 4:
//                 s.display();
//                 break;
//             case 5:
//                 return 0;
//             default:
//                 cout << "Invalid choice!\n";
//         }
//     }
// }
//stack using one queue 
#include <iostream>
#include <queue>
using namespace std;

class StackUsingOneQueue {
    queue<int> q;

public:
    void push(int x) {
        int size = q.size();
        q.push(x);
        // Move all previous elements behind new element
        for (int i = 0; i < size; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    void pop() {
        if (q.empty()) {
            cout << "Stack Underflow\n";
            return;
        }
        cout << "Popped: " << q.front() << endl;
        q.pop();
    }

    void top() {
        if (q.empty()) {
            cout << "Stack is Empty\n";
            return;
        }
        cout << "Top element: " << q.front() << endl;
    }

    void display() {
        if (q.empty()) {
            cout << "Stack is Empty\n";
            return;
        }
        cout << "Stack elements (top to bottom): ";
        queue<int> temp = q;
        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }

    bool empty() {
        return q.empty();
    }
};

int main() {
    StackUsingOneQueue s;
    int choice, val;

    while (true) {
        cout << "\n--- Stack using One Queue ---\n";
        cout << "1. Push\n2. Pop\n3. Top\n4. Display\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> val;
                s.push(val);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                s.top();
                break;
            case 4:
                s.display();
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice!\n";
        }
    }
}

