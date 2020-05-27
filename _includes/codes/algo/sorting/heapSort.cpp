#include <iostream>

using namespace std;

void heapify(int root, int endNode);
int n = 10;
int arr[10] = {3, 2, 8, 4, 1, 9, 8, 2, 6, 7};

int main() {
    int tmp;
    for (int i = (n - 1) / 2; i >= 0; i --) {
        heapify(i, n);
    }
    for (int i = n - 1; i >= 0; i --) {
        tmp = arr[0];
        arr[0] = arr[i];
        arr[i] = tmp;
        heapify(0, i);
    }
    for (int i = 0; i < n; i ++) {
        cout << arr[i] << "\t";
    }
    cout << endl;
}

void heapify(int root, int endNode) {
    int child;
    int val = arr[root];
    while (root * 2 + 1 < endNode) {
        child = (root * 2) + 1;
        if (child + 1 < endNode && arr[child] < arr[child + 1]) {
            child ++;
        }
        if (arr[child] < val)
            break;
        arr[root] = arr[child];
        root = child;
    }
    arr[root] = val;
}