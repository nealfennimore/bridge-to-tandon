#include <iostream>
using namespace std;

void printTriangle(int n);
void printOpositeTriangles(int n);
void printRuler(int n);

int main() {
    int n;
    cout << "Type in an int" << endl;
    cin >> n;

    cout << "printTriangle:" << endl;
    printTriangle(n);
    cout << endl << endl << endl;

    cout << "printOpositeTriangles:" << endl;
    printOpositeTriangles(n);
    cout << endl << endl << endl;

    cout << "printRuler:" << endl;
    printRuler(n);
    cout << endl;
}

void printTriangle(int n) {
    if (n - 1 > 0) {
        printTriangle(n - 1);
    }
    for (int i = 0; i < n; i++) {
        cout << "*";
    }
    cout << endl;
}

void printOpositeTriangles(int n) {
    for (int i = 0; i < n; i++) {
        cout << "*";
    }
    cout << endl;
    if (n - 1 > 0) {
        printOpositeTriangles(n - 1);
    }
    for (int i = 0; i < n; i++){
        cout << "*";
    }
    cout << endl;
}

void printRuler(int n) {
    if (n - 1 > 0) {
        printRuler(n - 1);
    }
    for (int i = 0; i < n; i++) {
        cout << "-";
    }
    cout << "\n";
    if (n - 1 > 0) {
        printRuler(n - 1);
    }
}