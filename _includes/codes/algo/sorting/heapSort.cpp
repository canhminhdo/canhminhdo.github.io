#include <iostream>

using namespace std;

void heapify(int root, int endNode);
void print();

int arr[5] = {1, 5, 4, 2, 3};
int n = 5;

int main() {
    int tmp;
    // vun cây từ dưới lên tạo thành đống
    for (int i = (n - 1) / 2; i >= 0; i --) {
        heapify(i, n);
    }
    for (int i = n - 1; i >= 0; i --) {
        // cho khoá lớn nhất về cuối dãy
        tmp = arr[0];
        arr[0] = arr[i];
        arr[i] = tmp;
        // vun đống lại từ vị trí root đầu tiên và không xét phần tử thứ >= i
        heapify(0, i);
    }
    print();
}

void heapify(int root, int endNode) {
    int child;
    int val = arr[root];
    // chừng nào chưa phải nút lá
    while (root * 2 + 1 < endNode) {
        child = (root * 2) + 1; // nút con trái
        // so sánh nút con trái và nút con phải nếu có
        if (child + 1 < endNode && arr[child] < arr[child + 1]) {
            child ++;
        }
        // nếu cả hai nút con nhỏ hơn root thì dừng
        if (arr[child] < val)
            break;
        // đặt giá trị của nút con lớn hơn vào nút gốc
        arr[root] = arr[child];
        root = child;
    }
    arr[root] = val;
}

void print() {
    for (int i = 0; i < n; i ++) {
        cout << arr[i] << '\t';
    }
    cout << endl;
}