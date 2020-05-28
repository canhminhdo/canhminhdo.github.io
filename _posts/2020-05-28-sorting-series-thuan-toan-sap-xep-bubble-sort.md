---
title: \[Sorting series\] Thuật toán sắp xếp Bubble Sort
date: 2020-05-28 21:24
category:
    - Programming
    - Data Structures and Algorithms
    - Sorting Problem
tags: [C++]
---

Thuật toán sắp xếp **Bubble Sort** (nổi bọt) được thực hiện như sau. Bắt đầu duyệt từ
cuối dãy tới đầu dãy, hai phần từ gần nhau nếu phần tử sau nhỏ hơn phần tử trước ta đổi
chỗ hai phần tử. Sau lần duyệt đầu tiên phần tử nhỏ nhất sẽ xuất hiện ở đầu dãy. Việc tiếp
theo của chúng ta là đi sắp xếp các phần tử còn lại từ k[2..n]. Vậy có thể thấy rằng, sau
bước duyệt thứ **$$i$$** như vậy thì ta sẽ có phần tử nhỏ nhất thứ **$$i$$** trong dãy số.

{% highlight pseudocode %}
void function BubbleSort() {
    int tmp;
    for (int i = 0; i < n - 1; i ++) {
        // Làm nổi phần tử nhỏ nhất trong đoạn k[i, n - 1] về vị trí k[i]
        for (int j = n - 1; j > i; j --) {
            if (arr[j] < arr[j - 1]) {
                <Đổi chỗ 2 phần tử arr[j] và arr[j - 1]>
            }
        }
    }
}
{% endhighlight %}

Độ phức tạp của thuật toán luôn là $$O(n^2)$$ bấp chấp dữ liệu ban đầu như thế nào.
Hãy cùng xem cách cài đặt trường trình bằng C++ như sau:

{% highlight c++ %}
{% include codes/algo/sorting/bubbleSort.cpp %}
{% endhighlight c++ %}

Kết quả khi chạy chương trình trên sẽ như sau:

{% highlight pseudocode %}
1	2	3	4	5
{% endhighlight %}
