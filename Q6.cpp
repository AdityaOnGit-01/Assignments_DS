#include <iostream>
using namespace std;

struct Element {
    int r, c, val;
};

class SparseMatrix {
    Element data[100];
    int rows, cols, num;
public:
    void read() {
        cout << "Enter rows, cols, non-zero count: ";
        cin >> rows >> cols >> num;
        for (int i = 0; i < num; i++)
            cin >> data[i].r >> data[i].c >> data[i].val;
    }

    void display() {
        cout << "Triplet form:\n";
        for (int i = 0; i < num; i++)
            cout << data[i].r << " " << data[i].c << " " << data[i].val << "\n";
    }

    void transpose() {
        for (int i = 0; i < num; i++) {
            int t = data[i].r;
            data[i].r = data[i].c;
            data[i].c = t;
        }
        cout << "Transposed matrix:\n"; display();
    }

    // For simplicity, addition/multiplication can be coded with assumptions
    // (skipping here due to length).
};
