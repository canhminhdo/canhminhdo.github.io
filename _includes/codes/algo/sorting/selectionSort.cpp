#include <iostream>

using namespace std;

int arr[5] = {1, 5, 4, 2, 3};
int n = 5;
void print();
void selectionSort();

int main() {
    selectionSort();
    print();
}

void selectionSort() {
    int tmp;
    int jmin;
    for (int i = 0; i < n - 1; i ++) {
        jmin = i;
        for (int j = i + 1; j < n; j ++) {
            if (arr[jmin] > arr[j]) {
                jmin = j; // tìm index phần tử nhỏ nhất trong dãy arr[i..n]
            }
        }
        if (jmin != i) {
            tmp = arr[i];
            arr[i] = arr[jmin];
            arr[jmin] = tmp;
        }
    }
}

void print() {
    for (int i = 0; i < n; i ++) {
        cout << arr[i] << '\t';
    }
    cout << endl;
}