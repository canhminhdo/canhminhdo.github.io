---
layout: post
title: "[Sorting series] Thuật toán sắp xếp distribution sort"
redirect_from:
    - /sorting-series-thuat-toan-sap-xep-distribution-sort/
date: 2020-06-26 23:20
category:
    - Programming
    - Data Structures and Algorithms
    - Sorting Problem
tags: 
    - C++
---
Trong bài viết này, chúng ta cùng tìm hiểu một thuật toán sắp xếp đặc biệt
khi biết các giá trị trong mảng sắp xếp nằm trong [0, m). Khi đó ta sẽ khởi
tạo một mảng có M phần tử, mỗi giá trị trong mảng sẽ là số lần xuất hiện của
giá trị khoá trong mảng cần tìm kiếm.

Mảng cần sắp xếp có n phần tử arr[1..n] thoả mãn $$arr[i] \in [0, m)$$. Ta có mảng
đếm số lần xuất hiện của phần tử khoá trong mảng cần sắp xếp là c[1..m]. Khởi
tạo ban đầu, tất cả giá trị trong mảng c[1..m] bằng 0.

{% highlight c++ %}
// khởi tạo gía trị ban đầu cho mảng c[1..M]
for (int i = 0; i < m; i++) {
    c[i] = 0;
}
{% endhighlight c++ %}

Bắt đầu tính toán số lần xuất hiện của giá trị khoá trong mảng arr[1..n] bằng vòng
lặp qua các phần tử khoá và cộng thêm một vào mảng đếm

{% highlight c++ %}
// khởi tạo gía trị ban đầu cho mảng c[1..m]
for (int i = 0; i < n; i ++) {
    c[arr[i]] ++;
}
{% endhighlight c++ %}

Khi biết được số lần xuất hiện của các phần tử khoá trong mảng c[1..m], ta có thể liệt
kê lại các phần tử đó để được một dãy khoá sắp xếp. Dưới đây là một cách có thể lấy ra
dãy khoá được sắp xếp. Đầu tiên ta sẽ tính toán vị trí xuất hiện cuối trong dãy sắp xếp
của một phần tử ở trong mảng c[1..m].

{% highlight c++ %}
// tính vị trí cuối mỗi đoạn của giá trị i
for (int i = 1; i < m; i ++) {
    c[i] = c[i - 1] + c[i];
}
{% endhighlight c++ %}

Ta sẽ dùng một mảng tạm để lưu các giá trị sắp xếp sau khi biết vị trí cuối mỗi đoạn của giá
trị i trong mảng c[1..m]

{% highlight c++ %}
// chèn vị khoá vào đúng vị trị trong mảng t
for (int i = n - 1; i >= 0; i --) {
    t[c[arr[i]] - 1] = arr[i];
    c[arr[i]] --;
}
{% endhighlight c++ %}
Cuối cùng ta có một dãy sắp xếp trong mảng t, và ta cần copy giá trị ở mảng t sang mảng khoá ban đầu. Nhưng tại sao chúng ta phải dùng dãy khoá tạm t và duyệt từ cuối dãy lên, chúng ta phân tích
thêm một đặc trưng của các thuật toán sắp xếp. Đó là tính ổn định của thuật toán sắp xếp (STABILITY).

Một phương pháp sắp xếp được gọi là **ổn định** nếu nó đảm bảo thứ tự ban đầu của các bản ghi mang khoá
bằng nhau trong danh sách. Ví dụ danh sách sinh viên ban đầu theo thứ tự alphabet, khi sắp xếp theo thứ
tự giảm dần của điểm thì những sinh viên bằng điểm nhau sẽ được sắp xếp mà vẫn giữ được nguyên thứ tự
sắp xếp theo alphabet. Bạn có thể tìm hiểu thêm [tại đây]({% post_url 2020-06-26-tinh-on-dinh-cua-thuat-toan-sap-xep %}).

Độ phức tạp của thuật toán distribution sort là **O(m + n)**, nhưng nhược điểm của cách sắp xếp này là giá trị khoá quá lớn mà n nhỏ cũng không thể làm được. Và sau đây là cách cài đặt của thuật toán bằng C++.

{% highlight c++ %}
{% include codes/algo/sorting/distributionSort.cpp %}
{% endhighlight c++ %}

Kết quả khi chạy chương trình trên sẽ như sau:

{% highlight pseudocode %}
0	1	2	3	4	5	5	6	7	8	9	9
{% endhighlight %}
