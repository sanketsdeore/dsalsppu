#include <iostream>
using namespace std;

void minHeap (int arr[], int i) {
    int parent = (i - 1) / 2;
    int curr = i;
    while (parent >= 0 && arr [parent] > arr [curr]) {
        swap (arr [parent], arr [curr]);
        curr = parent;
        parent = (curr - 1) / 2;
    }
}

void maxHeap (int arr[], int i) {
    int parent = (i - 1) / 2;
    int curr = i;
    while (parent >= 0 && arr [parent] < arr [curr]) {
        swap (arr [parent], arr [curr]);
        curr = parent;
        parent = (curr - 1) / 2;
    }
}

int main() {
    int n, j;
    
    cout << "\nEnter no. of students: ";
    cin >> n;
    
    int arr [n];
    
    for (j = 0; j < n; j ++) {
        cout << "\nMarks of student " << j + 1 << ": ";
        cin >> arr [j];
    }
    
    cout << "\nList of Marks: ";
    for (j = 0; j < n; j ++) {
        cout << arr [j] << " ";
    }
    
    for (j = 1; j < n; j ++) {
        minHeap (arr, j);
    }
    
    cout << "\nList of Marks after Heapifying (Min): ";
    for (j = 0; j < n; j ++) {
        cout << arr [j] << " ";
    }
    
    cout << "\nMinimum Marks: " << arr [0];
    
    for (j = 1; j < n; j ++) {
        maxHeap(arr, j);
    }
    
    cout << "\nList of Marks after Heapifying (Max): ";
    for (j = 0; j < n; j ++) {
        cout << arr [j] << " ";
    }
    
    cout << "\nMaximum Marks: " << arr [0];
}
