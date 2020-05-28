#include <iostream>

using namespace std;

int arr[5] = {1, 5, 4, 2, 3};
int n = 5;
void print();
void bubbleSort();

int main() {
    bubbleSort();
    print();
}

void bubbleSort() {
    int tmp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = n - 1; j > i; j --) {
            if (arr[j] < arr[j - 1]) {
                tmp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = tmp;
            }
        }
    }
}

void print() {
    for (int i = 0; i < n; i ++) {
        cout << arr[i] << '\t';
    }
    cout << endl;
}