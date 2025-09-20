#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 5, 6, 7};
    int n = 6;
    int total = (n + 1) * (n + 2) / 2; // sum of first (n+1) numbers
    int sum = 0;
    for (int i = 0; i < n; i++) sum += arr[i];
    cout << "Missing number: " << (total - sum) << "\n";
    return 0;
}
