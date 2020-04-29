#include <iostream>

using namespace std;

void generation(int n);
void show(int* arr, int n);
void fill(int* arr, int start, int end, int val);

int main() {
    generation(4);
}

void generation(int n) {
    // cấu hình đầu tiên
    int arr[n];
    int i;
    fill(arr, 0, n, 0);
    do {
        // hiển thị cấu hình
        show(arr, n);
        // sinh cấu hình tiếp theo
        i = n - 1;
        while (i >= 0 and arr[i] == 1) i --;
        if (i >= 0) {
            arr[i] = 1;
            fill(arr, i + 1, n, 0);
        }
    } while (i >= 0);
}

void show(int* arr, int n) {
    for (int i = 0; i < n; i ++) {
        cout << arr[i];
    }
    cout << endl;
}

void fill(int* arr, int start, int end, int val) {
    for (int i = start; i < end; i ++) {
        *(arr + i) = val;
    }
}