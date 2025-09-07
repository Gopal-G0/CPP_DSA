#include<iostream>
using namespace std;

void Print(int n) {
    
    if(n == 1) {
        cout << 1 << " ";
        return;
    }

    Print(n-1);
    cout << n << " ";
}

int main() {
    
    int n;
    cout << "Enter n: ";
    cin >> n;

    Print(n);
    cout << endl;

    return 0;
}