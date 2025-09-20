#include <iostream>
using namespace std;

class ArrayOps {
    int arr[100], n;
public:
    ArrayOps() { n = 0; }

    void create() {
        cout << "Enter size: ";
        cin >> n;
        cout << "Enter elements: ";
        for (int i = 0; i < n; i++) cin >> arr[i];
    }

    void display() {
        cout << "Array: ";
        for (int i = 0; i < n; i++) cout << arr[i] << " ";
        cout << "\n";
    }

    void insert() {
        int pos, val;
        cout << "Enter position(0-based) and value: ";
        cin >> pos >> val;
        if (pos < 0 || pos > n) { cout << "Invalid position\n"; return; }
        for (int i = n; i > pos; i--) arr[i] = arr[i-1];
        arr[pos] = val;
        n++;
    }

    void remove() {
        int pos;
        cout << "Enter position(0-based): ";
        cin >> pos;
        if (pos < 0 || pos >= n) { cout << "Invalid position\n"; return; }
        for (int i = pos; i < n-1; i++) arr[i] = arr[i+1];
        n--;
    }

    void linearSearch() {
        int key;
        cout << "Enter element: ";
        cin >> key;
        for (int i = 0; i < n; i++) {
            if (arr[i] == key) {
                cout << "Found at position " << i << "\n";
                return;
            }
        }
        cout << "Not found\n";
    }
};

int main() {
    ArrayOps obj;
    int ch;
    do {
        cout << "\n--- MENU ---\n1.CREATE\n2.DISPLAY\n3.INSERT\n4.DELETE\n5.LINEAR SEARCH\n6.EXIT\n";
        cin >> ch;
        switch (ch) {
            case 1: obj.create(); break;
            case 2: obj.display(); break;
            case 3: obj.insert(); break;
            case 4: obj.remove(); break;
            case 5: obj.linearSearch(); break;
        }
    } while (ch != 6);
    return 0;
}
