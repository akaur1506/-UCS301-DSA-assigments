#include <iostream>
using namespace std;

//QUESTION 1 FUNCTIONS
void createArray(int arr[], int &n) {
    cout<<"Enter number of elements: ";
    cin>>n;
    cout<<"Enter the elements of array:";
    for (int i = 0; i < n; i++) {
        cin>>arr[i];
    }
    cout<<"Array created successfully.\n";
}

void displayArray(int arr[], int n) {
    if (n == 0) {
        cout<<"Array is empty!\n";
        return;
    }
    cout<<"Array elements: ";
    for (int i = 0; i < n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void insertElement(int arr[], int &n) {
    if (n == 0) {
        cout<<"The array is empty"<<endl;
        return;
    }
    int pos, val;
    cout<<"Enter position at which you want to insert : ";
    cin>>pos;
    cout<<"Enter value to insert: ";
    cin>>val;
    if (pos >= 0 && pos <= n) {
        for (int i = n; i > pos; i--) {
            arr[i] = arr[i - 1];
        }
        arr[pos] = val;
        n++;
        cout<<"Element inserted successfully.\n";
    } 
    else {
        cout<<"Invalid position!\n";
    }
}

void deleteElement(int arr[], int &n) {
    if (n == 0) {
        cout << "The array is empty"<< endl;
        return;
    }
    int val;
    cout << "Enter value to delete: ";
    cin >> val;
    int pos = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == val) {
            pos = i;
            break;
        }
    }
    if (pos != -1) {
        for (int i = pos; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }
        n--;
        cout << "Element deleted successfully.\n";
    } else {
        cout << "Element not found in array.\n";
    }
}

void linearSearch(int arr[], int &n) {
    if (n == 0) {
        cout << "Array is empty\n";
        return;
    }
    int val;
    cout << "Enter value to search: ";
    cin >> val;
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (arr[i] == val) {
            cout << "Element found at index " << i << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "Element not found.\n";
    }
}


int main() {

//QUESTION 1
    int arr[100]; 
    int n = 0;    
    int choice;

    while (true) {
        cout << "\n--- MENU ---\n";
        cout << "1. CREATE\n";
        cout << "2. DISPLAY\n";
        cout << "3. INSERT\n";
        cout << "4. DELETE\n";
        cout << "5. LINEAR SEARCH\n";
        cout << "6. EXIT\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: createArray(arr, n); break;
            case 2: displayArray(arr, n); break;
            case 3: insertElement(arr, n); break;
            case 4: deleteElement(arr, n); break;
            case 5: linearSearch(arr, n); break;
            case 6: cout << "Exiting program\n"; return 0;
            default: cout << "Invalid choice\n";
        }
    }

//QUESTION 2
    int arr[100], n;

    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Removing duplicates
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; ) {
            if (arr[i] == arr[j]) {
               
                for (int k = j; k < n - 1; k++) {
                    arr[k] = arr[k + 1];
                }
                n--; 
            } else {
                j++;
            }
        }
    }

    cout << "Array after removing duplicates:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

//QUESTION 3
// ANS--> 10000

//QUESTION 4 ( a part)
    int arr[100], n;

    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    
    int start = 0, end = n - 1;
    while (start < end) {
       
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
    }

   
    cout << "Reversed array:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

//QUESTION 4 (b part)
    int A[10][10], B[10][10], C[10][10];
    int m, n, p, q;

    cout << "Enter rows and columns of Matrix A: ";
    cin >> m >> n;

    cout << "Enter rows and columns of Matrix B: ";
    cin >> p >> q;

    if (n != p) {
        cout << "Matrix multiplication not possible (columns of A != rows of B)." << endl;
        return 0;
    }

    cout << "Enter elements of Matrix A:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    cout << "Enter elements of Matrix B:\n";
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < q; j++) {
            cin >> B[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < q; j++) {
            C[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < q; j++) {
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    cout << "Resultant Matrix (A * B):\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < q; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

//QUESTION 4 (c part)
    int A[10][10], transpose[10][10];
    int rows, cols;

    cout << "Enter number of rows and columns: ";
    cin >> rows >> cols;

    cout << "Enter elements of the matrix:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> A[i][j];
        }
    }

    //Doing transpose
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transpose[j][i] = A[i][j];
        }
    }

    cout << "Transpose of the matrix:\n";
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            cout << transpose[i][j] << " ";
        }
        cout << endl;
    }
    
//QUESTION 5
    int matrix[10][10];
    int rows, cols;

    cout << "Enter number of rows and columns: ";
    cin >> rows >> cols;

    cout << "Enter elements of the matrix:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << "\nSum of each row:\n";
    for (int i = 0; i < rows; i++) {
        int rowSum = 0;
        for (int j = 0; j < cols; j++) {
            rowSum += matrix[i][j];
        }
        cout << "Row " << i + 1 << ": " << rowSum << endl;
    }

    cout << "\nSum of each column:\n";
    for (int j = 0; j < cols; j++) {
        int colSum = 0;
        for (int i = 0; i < rows; i++) {
            colSum += matrix[i][j];
        }
        cout << "Column " << j + 1 << ": " << colSum << endl;
    }
    return 0;
}

