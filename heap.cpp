#include <iostream>
#include <vector>
using namespace std;

void heapifyMax(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapifyMax(arr, n, largest);
    }
}

void heapifyMin(vector<int>& arr, int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;
    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        heapifyMin(arr, n, smallest);
    }
}

void heapsortIncreasing(vector<int>& arr) {
    int n = arr.size();
    for (int i = n/2 - 1; i >= 0; i--)
        heapifyMax(arr, n, i);

    for (int i = n - 1; i >= 1; i--) {
        swap(arr[0], arr[i]);
        heapifyMax(arr, i, 0);
    }
}

void heapsortDecreasing(vector<int>& arr) {
    int n = arr.size();
    for (int i = n/2 - 1; i >= 0; i--)
        heapifyMin(arr, n, i);

    for (int i = n - 1; i >= 1; i--) {
        swap(arr[0], arr[i]);
        heapifyMin(arr, i, 0);
    }
}

class PriorityQueue {
private:
    vector<int> heap;

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }

    void siftUp(int i) {
        while (i != 0 && heap[parent(i)] < heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    void siftDown(int i) {
        int n = heap.size();
        int largest = i;
        int l = left(i);
        int r = right(i);

        if (l < n && heap[l] > heap[largest])
            largest = l;
        if (r < n && heap[r] > heap[largest])
            largest = r;

        if (largest != i) {
            swap(heap[i], heap[largest]);
            siftDown(largest);
        }
    }

public:
    void insert(int key) {
        heap.push_back(key);
        siftUp(heap.size() - 1);
    }

    int peek() {
        if (heap.empty()) return -1;
        return heap[0];
    }

    int extractMax() {
        if (heap.empty()) return -1;
        int maxVal = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        siftDown(0);
        return maxVal;
    }

    void display() {
        for (int x : heap) cout << x << " ";
        cout << endl;
    }
};

int main() {
    vector<int> arr = {4, 10, 3, 5, 1};

    cout << "Original array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    vector<int> inc = arr;
    heapsortIncreasing(inc);
    cout << "Sorted Increasing (Heapsort): ";
    for (int x : inc) cout << x << " ";
    cout << endl;

    vector<int> dec = arr;
    heapsortDecreasing(dec);
    cout << "Sorted Decreasing (Heapsort): ";
    for (int x : dec) cout << x << " ";
    cout << endl;

    PriorityQueue pq;
    pq.insert(10);
    pq.insert(4);
    pq.insert(15);
    pq.insert(7);

    cout << "\nPriority Queue heap: ";
    pq.display();

    cout << "Max element: " << pq.peek() << endl;
    cout << "Extracting max: " << pq.extractMax() << endl;

    cout << "Priority Queue after extraction: ";
    pq.display();

    return 0;
}
