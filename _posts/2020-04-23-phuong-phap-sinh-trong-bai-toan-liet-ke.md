---
title: Phương pháp sinh trong bài toán liệt kê
date: 2020-04-23 14:39
category:
    - Programming
    - Data Structures and Algorithms
    - Listing Problem
tags: [C++]
---
Phương pháp sinh là một kỹ thuật để liệt kê các cấu hình nếu thoả mãn
hai điều kiện sau:
* Có thể **xác định được thứ tự** trên tập hợp các cấu hình tổ hợp cần liệt kê.
Từ đó biết được cấu hình đầu tiên và cấu hình cuối cùng.
* **Xây dựng được thuật toán** từ một cấu hình chưa phải cuối, sinh ra được cấu hình kế tiếp.

{% highlight c++ %}
// <Xây dựng cấu hình đầu tiên>;
// repeat
//      <Đưa ra cấu hình đang có>;
//      <Từ cấu hình đang có sinh ra cấu hình tiếp theo nếu còn>;
// until <hết cấu hình>;
{% endhighlight %}

Chúng ta cùng xem một bài toán liệt kê tất cả các dãy nhị phân có độ dài N.
Một dãy nhị phân có độ dài N là một dãy X[1..N] trong đó $$X[i] \in \{0,1\} (\forall i \in [1..N])$$. Dễ thấy dãy nhị phân độ dài N biểu diễn một giá trị nguyên p(x) nào đó trong đoạn [0, $$2^n$$ -1]. Thứ tự của dãy nhị phân độ dài N sẽ là thứ tự của dãy số nguyên từ 0, 1, ..., $$2^n$$ - 1

Ví dụ: Khi n = 2, các dãy nhị phân độ dài 2 được liệt kê như sau:

| p(x) | 0 | 1 | 2 | 3 |
|--- | --- | ---|
| x | 00 | 01 | 10 | 11 |

Đối chiếu với hai điều kiện bên trên ta có
* Tổ hợp cấu hình cần liệt kê có thứ tự, cấu hình đầu tiên là 00, cấu hình kết thúc là 11.
* Thuật toán đề sinh ra một cấu hình tiếp theo từ một cấu hình chưa kết thúc
    - Duyệt từ cuối dãy lên đầu dãy, nếu thấy số 0 thì thay bằng 1, và đặt lại tất cả số
    sau đó bằng 0.
    - Nếu không thấy số 0 thì, toàn dãy là số 1, đây cũng là cấu hình cuối cùng.

Dưới dây là chương trình C++ mô tả cách hoạt động của thuật toán sinh.

{% highlight c++ %}
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
{% endhighlight %}