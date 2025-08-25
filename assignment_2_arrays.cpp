#include<iostream>
using namespace std;

//Functions for Question 1
// Binary Search
int binarySearch(int arr[], int size, int target) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = (low + high)/ 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1; 
    }
    return -1;
}

// Linear Search
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target)
            return i;
    }
    return -1;
}

//Function for question 3
int findMissingNumber(int arr[], int size) {
    int low = 0;
    int high = size - 1;
    int first = arr[0];

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] - first != mid) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    return first + low;
}
int main(){
//QUESTION 1
    int data[] = {2, 4, 6, 8, 10, 12, 14, 16};
    int size = sizeof(data) / sizeof(data[0]);
    int target = 10;

    // Binary Search
    int binaryResult = binarySearch(data, size, target);
    if (binaryResult != -1)
        cout << "Binary Search: Element found at index " << binaryResult << endl;
    else
        cout << "Binary Search: Element not found." << endl;

    // Linear Search
    int linearResult = linearSearch(data, size, target);
    if (linearResult != -1)
        cout << "Linear Search: Element found at index " << linearResult << endl;
    else
        cout << "Linear Search: Element not found" << endl;

//QUESTION 2
    int arr[7]= {64, 34, 25, 12, 22, 11, 90};
    int i,j,temp;
    for(i=0; i<size-1; i++){
        for(j=0; j<size-i-1; j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    for(i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }


//QUESTION 3
    int brr[] = {1, 2, 3, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    int missing = findMissingNumber(arr, size);
    cout << "Missing number: " << missing << endl;
    return 0;
}