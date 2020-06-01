#include <iostream>

using namespace std;

int arr[5] = {1, 5, 4, 2, 3};
int n = 5;
void print();
void shellSort();

int main() {
    shellSort();
    print();
}

void shellSort() {
    int i, j, tmp, h;
    h = n / 2;
    while (h != 0) {
        for (i = h; i < n; i ++) {
            // sắp xếp chèn trên dãy con a[i - h], a[i], a[i + h], a[i + 2h], ...
            tmp = arr[i];
            j = i - h;
            while (j >= 0 and arr[j] > tmp) {
                arr[j + h] = arr[j];
                j = j - h;
            }
            arr[j + h] = tmp;
        }
        h = h / 2;
    }
}

void print() {
    for (int i = 0; i < n; i ++) {
        cout << arr[i] << '\t';
    }
    cout << endl;
}