// #include <iostream>
// using namespace std;
// void selectionSort(int arr[], int n) {
//     for (int i = 0; i < n - 1; i++) {
//         int minIndex = i;
//         for (int j = i + 1; j < n; j++)
//             if (arr[j] < arr[minIndex])
//                 minIndex = j;
//         swap(arr[i], arr[minIndex]);
//     }
// }

// void insertionSort(int arr[], int n) {
//     for (int i = 1; i < n; i++) {
//         int key = arr[i], j = i - 1;
//         while (j >= 0 && arr[j] > key) {
//             arr[j + 1] = arr[j];
//             j--;
//         }
//         arr[j + 1] = key;
//     }
// }

// void bubbleSort(int arr[], int n) {
//     for (int i = 0; i < n - 1; i++)
//         for (int j = 0; j < n - i - 1; j++)
//             if (arr[j] > arr[j + 1])
//                 swap(arr[j], arr[j + 1]);
// }

// void merge(int arr[], int l, int m, int r) {
//     int n1 = m - l + 1, n2 = r - m;
//     int a[n1], b[n2];
//     for (int i = 0; i < n1; i++) a[i] = arr[l + i];
//     for (int i = 0; i < n2; i++) b[i] = arr[m + 1 + i];
//     int i = 0, j = 0, k = l;
//     while (i < n1 && j < n2)
//         arr[k++] = (a[i] <= b[j]) ? a[i++] : b[j++];
//     while (i < n1) arr[k++] = a[i++];
//     while (j < n2) arr[k++] = b[j++];
// }

// void mergeSort(int arr[], int l, int r) {
//     if (l < r) {
//         int m = (l + r) / 2;
//         mergeSort(arr, l, m);
//         mergeSort(arr, m + 1, r);
//         merge(arr, l, m, r);
//     }
// }

// int partition(int arr[], int low, int high) {
//     int pivot = arr[high], i = low - 1;
//     for (int j = low; j < high; j++)
//         if (arr[j] <= pivot) {
//             i++;
//             swap(arr[i], arr[j]);
//         }
//     swap(arr[i + 1], arr[high]);
//     return i + 1;
// }

// void quickSort(int arr[], int low, int high) {
//     if (low < high) {
//         int p = partition(arr, low, high);
//         quickSort(arr, low, p - 1);
//         quickSort(arr, p + 1, high);
//     }
// }

// void printArray(int arr[], int n) {
//     for (int i = 0; i < n; i++) cout << arr[i] << " ";
//     cout << endl;
// }

// int main() {
//     int arr[50], n, choice;
//     cout<<"Enter the number of elements : ";
//     cin >> n;
//     cout<<"Enter elements : ";
//     for (int i = 0; i < n; i++) cin >> arr[i];
//     cout<<"enter your choice : 1. selection sort \n 2. insertion sort \n 3. bubble sort \n 4. merge sort \n 5. quicksort\n ";
//     cin >> choice;

//     switch (choice) {
//         case 1: selectionSort(arr, n); break;
//         case 2: insertionSort(arr, n); break;
//         case 3: bubbleSort(arr, n); break;
//         case 4: mergeSort(arr, 0, n - 1); break;
//         case 5: quickSort(arr, 0, n - 1); break;
//         default: return 0;
//     }
//     cout<<"The answer is : ";
    
//     printArray(arr, n);
// }
#include <iostream>
using namespace std;

void improvedSelectionSort(int arr[], int n) {
    int left = 0, right = n - 1;
    while (left < right) {
        int minIndex = left, maxIndex = right;
        for (int i = left; i <= right; i++) {
            if (arr[i] < arr[minIndex]) minIndex = i;
            if (arr[i] > arr[maxIndex]) maxIndex = i;
        }

        swap(arr[left], arr[minIndex]);

        if (maxIndex == left) maxIndex = minIndex;

        swap(arr[right], arr[maxIndex]);

        left++;
        right--;
    }
}

int main() {
    int n, arr[50];
    cout<<"Enter the number of elements : ";
    cin >> n;
    cout<<"enter elements : ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    improvedSelectionSort(arr, n);
    cout<<"The solution is : \n";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
}

