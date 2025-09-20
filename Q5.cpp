#include <iostream>
using namespace std;

int main() {
    int n = 4; // Example size
    int diag[4] = {1,2,3,4}; // diagonal matrix storage
    cout << "Diagonal Matrix stored as 1D: ";
    for(int i=0;i<n;i++) cout<<diag[i]<<" ";
    cout<<"\n";
    
    int triDiag[3*4-2] = {1,2,3,4,5,6,7,8,9,10}; // tri-diagonal storage
    cout << "Tri-diagonal stored size: " << (3*n-2) << "\n";

    int lower[(n*(n+1))/2]; 
    cout << "Lower triangular needs " << (n*(n+1))/2 << " elements\n";

    int upper[(n*(n+1))/2]; 
    cout << "Upper triangular needs " << (n*(n+1))/2 << " elements\n";

    int sym[(n*(n+1))/2];
    cout << "Symmetric needs " << (n*(n+1))/2 << " elements\n";
    return 0;
}
