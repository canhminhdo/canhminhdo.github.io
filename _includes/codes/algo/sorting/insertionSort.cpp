#include <iostream>

using namespace std;

int arr[5] = {1, 5, 4, 2, 3};
int n = 5;

void insertionSort();
void insertionSortWithBinarySearch();
void shift(int idxStart, int i);
void print();

int main() {
    insertionSort();
    insertionSortWithBinarySearch();
    print();
}

void insertionSort() {
    int tmp;
    int j;
    if (n == 1)
        return;
    for (int i = 1; i < n; i ++) {
        // chèn giá trị arr[i] vào dãy arr[0..i-1] để toàn dãy arr[0..i] trở thành sắp xếp
        tmp = arr[i]; // lưu lại giá trị arr[i]
        j = i - 1;
        while (j >= 0 && tmp < arr[j]) {
            arr[j + 1] = arr[j]; // dịch giá trị arr[j] về sau một vị trí, tạo một khoảng trống j
            j = j - 1;
        }
        arr[j + 1] = tmp; // đưa giá trị chèn vào khoảng chống mới tạo ra
    }
}

void insertionSortWithBinarySearch() {
    int idxStart, idxStop, median, tmp;
    if (n == 1)
        return;
    for (int i = 1; i < n; i ++) {
        tmp = arr[i];
        // binary search
        idxStart = 0;
        idxStop = i - 1;
        // idxStart chính là vị trí cần chèn sau khi thoát khỏi vòng lặp
        // mỗi lượt lặp sẽ co ngắn đoạn cần kiểm tra
        do {
            median = (idxStart + idxStop) / 2;
            if (arr[median] > arr[i]) {
                idxStop = median - 1;
            } else {
                idxStart = median + 1;
            }
        } while(idxStart <= idxStop);
        // dịch khoá từ arr[idxStart] tới arr[i - 1] lùi sau một vị trí
        shift(idxStart, i - 1);
        arr[idxStart] = tmp; // đưa giá trị tmp vào khoảng trống
    }
}

void shift(int idxStart, int j) {
    while (j >= idxStart) {
        arr[j + 1] = arr[j];
        j = j - 1;
    }
}

void print() {
    for (int i = 0; i < n; i ++) {
        cout << arr[i] << '\t';
    }
    cout << endl;
}