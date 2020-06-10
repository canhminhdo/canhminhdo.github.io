#include <iostream>
#include <stdlib.h>

using namespace std;

int arr[5] = {1, 5, 4, 2, 3};
int n = 5;
void print();
void quickSort(int start, int stop);

int main() {
    quickSort(0, 4);
    print();
}

void quickSort(int start, int stop) {
    int i, j, pivot, tmp;
    // nếu đoạn chỉ có <= 1 phần tử chúng ta không phải làm gì
    if (start >= stop)
        return;
    // tìm một khoá ngẫu nhiên làm khoá chốt
    pivot = arr[rand() % (stop - start + 1) + start];
    i = start;
    j = stop;
    do {
        while (arr[i] < pivot) i ++;
        while (arr[j] > pivot) j --;
        // đến đây ta tìm được hai khoá arr[i] và arr[j] mà
        // arr[i] >= pivot >= arr[j]
        if (i <= j) {
            if (i < j) { // nếu i đứng trước j thì đổi chỗ hai khoá
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
            i ++;
            j --;
        }
    } while (i < j);
    // sắp xếp hai đoạn con mới tạo ra
    quickSort(start, j);
    quickSort(i, stop);
}

void print() {
    for (int i = 0; i < n; i ++) {
        cout << arr[i] << '\t';
    }
    cout << endl;
}