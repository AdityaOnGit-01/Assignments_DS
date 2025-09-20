#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 2, 3, 4, 1, 5};
    int n = 7;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                for (int k = j; k < n - 1; k++) arr[k] = arr[k + 1];
                n--;
                j--; // adjust index
            }
        }
    }

    cout << "Unique elements: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n";
    return 0;
}
