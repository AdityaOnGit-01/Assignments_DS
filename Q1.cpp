#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++)
        if (arr[i] == key) return i;
    return -1;
}

int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key) return mid;
        else if (arr[mid] > key) high = mid - 1;
        else low = mid + 1;
    }
    return -1;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = 5, key;
    cout << "Enter element to search: ";
    cin >> key;

    int idx1 = linearSearch(arr, n, key);
    if (idx1 != -1) cout << "Linear Search: Found at index " << idx1 << "\n";
    else cout << "Linear Search: Not Found\n";

    int idx2 = binarySearch(arr, n, key);
    if (idx2 != -1) cout << "Binary Search: Found at index " << idx2 << "\n";
    else cout << "Binary Search: Not Found\n";
    return 0;
}

