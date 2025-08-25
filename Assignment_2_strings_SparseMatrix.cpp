#include<iostream>
#include<string>
#include <cctype>
#include<algorithm>
using namespace std;

int main(){
    //Concatenating two strings
    string s1 = "My name is ";
    string s2 = "Ashmeen Kaur";
    cout<<"The concatenated string is : "<<s1 + s2;

    //Reversing a String
    int i = 0;
    cout<<"The reverse of the string is : ";
    for(i=s2.length()-1;i>=0;i--){
        cout<<s2[i];
    }
    cout<<endl;

    //Deleting all vowels
    char z;
    for(i=0;i<s1.length();i++){
        z = tolower(s1[i]);
        if(z=='a' || z == 'e'|| z== 'i' ||z == 'o' || z == 'u'){
            s1.erase(i,1);
            i--;
        }
    }
    cout<<"The string after deleting all vowels is : "<<s1<<endl;

    //sorting the strings in alphabetical order
    int n;
    cout<<"Enter the no. of strings : ";
    cin>>n;
    string arr[n];
    cout<<"Enter the elements of the array: ";
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    cout<<"The sorted array is : "<<endl;
    for(i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }

    //converting a string from uppercase to lowercase
    string up = "ABCDEF";
    for(i=0;i<up.length();i++){
        up[i] = tolower(up[i]);
    }
    cout<<"The conversion from uppercase to lowercase (of ABCDEF) : "<<up<<endl;

    //reducing the space required for diagonal matrix
    int no;
    cout << "Enter the number of diagonal elements: ";
    cin >> no;
    int a[no];
    for(i = 0; i < no; i++){
        cin >> a[i];
    }
    cout << "Diagonal Matrix is:" << endl;
    int j;
    for(i = 0; i < no; i++){
        for(j = 0; j < no; j++){
            if(i == j)
                cout << a[i] << " ";
            else
                cout << 0 << " ";
        }
        cout << endl;
    }
// Tri diagonal Matric
   cout << "Enter the size of the tri-diagonal matrix: ";
   int tsize;
   cin >> tsize;

// 1D array to store all elements: lower(n-1), main(n), upper(n-1)
   int tri[3*tsize - 2];
   cout << "Enter elements of tri-diagonal matrix (row-wise: lower, main, upper):\n";

// Input lower diagonal (n-1)
   for(int i = 0; i < tsize-1; i++)
           cin >> tri[i];

// Input main diagonal (n)
   for(int i = tsize-1; i < 2*tsize-1; i++)
           cin >> tri[i];

// Input upper diagonal (n-1)
   for(int i = 2*tsize-1; i < 3*tsize-2; i++)
           cin >> tri[i];

   cout << "Tri-Diagonal Matrix:" << endl;
   for(int i = 0; i < tsize; i++){
       for(int j = 0; j < tsize; j++){
               if(i-j == 1) {            // lower diagonal
                    cout << tri[i-1] << " ";
               }
               else if(i == j) {         // main diagonal
                    cout << tri[tsize-1 + i] << " ";
               }
               else if(j-i == 1) {       // upper diagonal
                    cout << tri[2*tsize-1 + i] << " ";
               }
               else {
                    cout << 0 << " ";
               }
       }
    cout << endl;
    }

    //Lower Triangular matrix
    cout<<"Enter the size of lower-triangular matrix: ";
    int lsize;
    cin>>lsize;
    int lower[lsize*(lsize+1)/2]; // space-saving
    cout<<"Enter elements of lower-triangular matrix row-wise: ";
    for(i=0;i<lsize*(lsize+1)/2;i++)
        cin>>lower[i];

    cout<<"Lower-Triangular Matrix:"<<endl;
    int index = 0;
    for(i=0;i<lsize;i++){
        for(j=0;j<lsize;j++){
            if(i>=j)
                cout<<lower[index++]<<" ";
            else
                cout<<"0 ";
        }
        cout<<endl;
    }

    //Upper triangular matrix
    cout<<"Enter the size of upper-triangular matrix: ";
    int usize;
    cin>>usize;
    int upper[usize*(usize+1)/2]; // space-saving
    cout<<"Enter elements of upper-triangular matrix row-wise: ";
    for(i=0;i<usize*(usize+1)/2;i++)
        cin>>upper[i];

    cout<<"Upper-Triangular Matrix:"<<endl;
    index = 0;
    for(i=0;i<usize;i++){
        for(j=0;j<usize;j++){
            if(j>=i)
                cout<<upper[index++]<<" ";
            else
                cout<<"0 ";
        }
        cout<<endl;
    }

    //Symmetric matrix
    cout<<"Enter the size of symmetric matrix: ";
    int ssize;
    cin>>ssize;
    int sym[ssize*(ssize+1)/2];
    cout<<"Enter elements of symmetric matrix (row-wise lower triangular): ";
    for(i=0;i<ssize*(ssize+1)/2;i++)
        cin>>sym[i];

    cout<<"Symmetric Matrix:"<<endl;
    index=0;
    for(i=0;i<ssize;i++){
        for(j=0;j<ssize;j++){
            if(i>=j)
                cout<<sym[index++]<<" ";
            else
                cout<<sym[j*(j+1)/2 + i]<<" "; // mirror element
        }
        cout<<endl;
    }

//SPARSE MATRIX OPERATIONS (Triplet Form)
    int r, c, t;
    cout << "Enter rows, columns and number of non-zero elements of sparse matrix: ";
    cin >> r >> c >> t;

    int triplet[t][3];
    cout << "Enter triplets (row column value):" << endl;
    for (i = 0; i < t; i++)
        for (j = 0; j < 3; j++)
            cin >> triplet[i][j];

// a. Transpose
   cout << "Transpose of sparse matrix:" << endl;
   for (i = 0; i < t; i++)
       cout << triplet[i][1] << " " << triplet[i][0] << " " << triplet[i][2] << endl;

// b. Addition
   int t2;
   cout << "Enter number of non-zero elements for second sparse matrix: ";
   cin >> t2;

   int triplet2[t2][3];
   cout << "Enter triplets for second matrix:" << endl;
   for (i = 0; i < t2; i++)
       for (j = 0; j < 3; j++)
           cin >> triplet2[i][j];

// Create an array to store the sum triplets
   int sumTriplets[t + t2][3];
   int k = 0;

// Copy first matrix
   for (i = 0; i < t; i++) {
       sumTriplets[k][0] = triplet[i][0];
       sumTriplets[k][1] = triplet[i][1];
       sumTriplets[k][2] = triplet[i][2];
       k++;
   }

// Add second matrix
   for (i = 0; i < t2; i++) {
       bool found = false;
       for (j = 0; j < k; j++) {
           if (triplet2[i][0] == sumTriplets[j][0] && triplet2[i][1] == sumTriplets[j][1]) {
              sumTriplets[j][2] += triplet2[i][2];
              found = true;
              break;
           }
       }
       if (!found) {
           sumTriplets[k][0] = triplet2[i][0];
           sumTriplets[k][1] = triplet2[i][1];
           sumTriplets[k][2] = triplet2[i][2];
           k++;
       }
   }

   cout << "Addition of two sparse matrices (triplet form):" << endl;
   for (i = 0; i < k; i++)
       cout << sumTriplets[i][0] << " " << sumTriplets[i][1] << " " << sumTriplets[i][2] << endl;

// c. Multiplication
   int prodTriplets[t * t2][3]; // Maximum possible products
   int p = 0;

   cout << "Multiplication of two sparse matrices (triplet form):" << endl;
   for (i = 0; i < t; i++) {
       for (j = 0; j < t2; j++) {
           if (triplet[i][1] == triplet2[j][0]) {
              // Check if this (row,col) already exists in prodTriplets
              bool found = false;
              for (int m = 0; m < p; m++) {
                  if (prodTriplets[m][0] == triplet[i][0] && prodTriplets[m][1] == triplet2[j][1]) {
                     prodTriplets[m][2] += triplet[i][2] * triplet2[j][2];
                     found = true;
                     break;
                  }
              }
               if (!found) {
                  prodTriplets[p][0] = triplet[i][0];
                  prodTriplets[p][1] = triplet2[j][1];
                  prodTriplets[p][2] = triplet[i][2] * triplet2[j][2];
                  p++;
               }
              }
       }
   }

   for (i = 0; i < p; i++)
       cout << prodTriplets[i][0] << " " << prodTriplets[i][1] << " " << prodTriplets[i][2] << endl;

//--------------- COUNT INVERSIONS IN AN ARRAY ----------------
    int size;
    cout << "Enter the size of the array for inversion count: ";
    cin >> size;
    double arrr[size];
    cout << "Enter the elements of the array: ";
    for(i = 0; i < size; i++)
        cin >> arrr[i];

    int inversions = 0;
    for(i = 0; i < size-1; i++){
        for(int j = i+1; j < size; j++){
            if(arrr[i] > arrr[j])
                inversions++;
        }
    }

    cout << "Number of inversions in the array: " << inversions << endl;
    int len;
    cout << "Enter the length of the array to count distinct elements: ";
    cin >> len;
    int arr2[len];
    cout << "Enter the elements of the array: ";
    for(i = 0; i < len; i++)
          cin >> arr2[i];

    int distinctCount = 0;
    for(i = 0; i < len; i++){
        bool isDistinct = true;
        for(int j = 0; j < i; j++){
            if(arr2[i] == arr2[j]){
                isDistinct = false;
                break;
            }
        }
        if(isDistinct)
            distinctCount++;
        }

    cout << "Total number of distinct elements: " << distinctCount << endl;
        return 0;
}
