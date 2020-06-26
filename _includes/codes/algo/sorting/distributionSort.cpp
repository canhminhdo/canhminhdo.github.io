#include <iostream>

using namespace std;

int arr[12] = {1, 5, 4, 2, 3, 6, 7, 9, 9, 8, 0, 5};
int c[10] = {}; // tạo một array với 10 phần tử, khởi tạo giá trị ban đầu bằng 0
int t[12] = {}; // mảng tạm chứa các phần tử đã được sắp xếp
int n = 12;
int m = 10; // nếu biết dãy cần sắp xếp chứa các giá trị từ [0 10)
void print();
void distributionSort();

int main() {
    distributionSort();
    print();
}

void distributionSort() {
    // khởi tạo dãy
    for (int i = 0; i < m; i ++) {
        c[i] = 0;
    }
    // đếm số lần xuất hiện của các giá trị
    for (int i = 0; i < n; i ++) {
        c[arr[i]] ++;
    }
    // tính vị trí cuối mỗi đoạn
    for (int i = 1; i < m; i ++) {
        c[i] = c[i - 1] + c[i];
    }
    // chèn vị khoá vào đúng vị trị trong mảng t
    for (int i = n - 1; i >= 0; i --) {
        t[c[arr[i]] - 1] = arr[i];
        c[arr[i]] --;
    }
    // copy giá trị mảng tạm sang mảng chính
    for (int i = 0; i < n; i ++) {
        arr[i] = t[i];
    }
}

void print() {
    for (int i = 0; i < n; i ++) {
        cout << arr[i] << '\t';
    }
    cout << endl;
}