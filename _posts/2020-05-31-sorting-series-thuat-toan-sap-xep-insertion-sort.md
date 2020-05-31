---
title: \[Sorting series\] Thuật toán sắp xếp Insertion Sort
date: 2020-05-31 02:18
category:
    - Programming
    - Data Structures and Algorithms
    - Sorting Problem
tags: [C++]
---
Trong bài viết này, chúng ta cùng tìm hiểu về thuật toán Insertion Sort.
Ý tưởng của thuật toán Insertion Sort là tại mỗi bước lặp tìm vị trí để
chèn một phần tử vào một dãy đã sắp xếp trước để được một dãy sắp xếp.<br/>
Xét dãy khoá k[1..n], ta thấy dãy con chỉ gồm một khoá k[1] có thể coi
là đã sắp xếp.<br/>
Xét thêm k[2], ta so sánh k[2] với k[1], nếu k[2] < k[1] thì ta chèn k[2]
vào trước k[1].<br/>
Đối với k[3], ta xét dãy chỉ gồm 2 khoá k[1], k[2] đã sắp xếp và tìm cách chèn
k[3] vào dãy để được dãy sắp xếp.<br/>
...<br/>
Tổng quát, ta sẽ có dãy **k[1..i]** trong đó **k[1..i - 1]** đã sắp xếp, ta cần tìm
cách chèn **k[i]** vào đúng vị trí để được dãy **k[1..i]** sắp xếp.<br/>
{% highlight pseudocode %}
void function InsertionSort() {
    int j, tmp;
    for (int i = 1; i < n; i ++) {
        // chèn giá trị k[i] vào dãy k[0..i-1] để được dãy k[0..i] đã sắp xếp
        tmp = k[i]; // lưu lại giá trị k[i]
        j = i - 1;
        while (i >= 0 & k[j] < tmp) {
            k[j + 1] = k[j]; // dịch giá trị k[j] lùi về sau một vị trí
            j = j - 1;
        }
        k[j + 1] = tmp; // đưa giá trị k[i] chèn vào khoảng trống mới
    }
}
{% endhighlight %}

Thuật toán Insertion Sort có phụ thuộc vào dãy khoá ban đầu, nếu dãy khoá đã
sắp xếp thì ta chỉ mất thời gian O(n) để chạy thực hiện. Trong trường hợp xấu
nhất ta vẫn mất $$O(n^2)$$. Chúng ta có thể cải thiện thuật toán tại bước chèn
phần tử **k[i]** vào mảng **k[0..i - 1]** bưởi vì mảng đã được sắp xếp trước đó.
Vì vậy chúng ta có thể dùng tìm kiếm nhị phân để nhanh chóng tìm ra vị trí cần chèn vào
mảng. Nhưng trong trường hợp xấu nhất ta vẫn phải dịch **i - 1** về phía sau một
bước để tạo ra khoangr trống cho **k[i]**. Vì vậy điều đó cũng không làm giảm đi
độ phức tạp của thuật toán.

Dưới đây là cách cài đặt thuật toán Insertion Sort và cải tiến khi dùng kỹ thuật
tìm kiếm nhị phân.

{% highlight c++ %}
{% include codes/algo/sorting/insertionSort.cpp %}
{% endhighlight c++ %}

Kết quả khi chạy chương trình trên sẽ như sau:

{% highlight pseudocode %}
1	2	3	4	5
{% endhighlight %}

