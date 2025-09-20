#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 2, 3, 4, 1, 5};
    int n = 7, distinct = 0;
    for (int i = 0; i < n; i++) {
        bool seen = false;
        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j]) { seen = true; break; }
        }
        if (!seen) distinct++;
    }
    cout << "Total distinct: " << distinct << "\n";
    return 0;
}
