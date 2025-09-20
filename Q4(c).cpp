#include <iostream>
using namespace std;

int main() {
    int A[10][10], T[10][10], r, c;
    cout << "Enter rows and cols: ";
    cin >> r >> c;
    cout << "Enter matrix:\n";
    for (int i=0;i<r;i++) for(int j=0;j<c;j++) cin>>A[i][j];

    for (int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            T[j][i] = A[i][j];

    cout << "Transpose:\n";
    for (int i=0;i<c;i++) {
        for(int j=0;j<r;j++) cout<<T[i][j]<<" ";
        cout<<"\n";
    }
    return 0;
}
