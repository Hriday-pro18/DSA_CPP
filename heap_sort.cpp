#include <iostream>
using namespace std;

// Max Heap for Ascending Order
void maxHeapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

// Min Heap for Descending Order
void minHeapify(int arr[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}

// Heap Sort Ascending
void ascending(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        maxHeapify(arr, i, 0);
    }
}

// Heap Sort Descending
void descending(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        minHeapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        minHeapify(arr, i, 0);
    }
}

int main() {
    int arr[] = {40, 10, 30, 50, 20};
    int n = 5;

    int a[5], b[5];

    // Copy original array
    for (int i = 0; i < n; i++) {
        a[i] = arr[i];
        b[i] = arr[i];
    }

    ascending(a, n);
    descending(b, n);

    cout << "Ascending Order: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    cout << "\nDescending Order: ";
    for (int i = 0; i < n; i++)
        cout << b[i] << " ";

    return 0;
}
