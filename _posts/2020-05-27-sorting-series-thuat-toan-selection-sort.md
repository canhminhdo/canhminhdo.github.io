---
layout: post
title: "[Sorting series] - Thuật toán sắp xếp Selection Sort"
redirect_from:
    - /sorting-series-thuat-toan-selection-sort
date: 2020-05-27 21:39
category:
    - Programming
    - Data Structures and Algorithms
    - Sorting Problem
tags: 
    - C++
---
Trong loạn bài về sắp xếp, hôm nay chúng ta cùng tìm hiểu cách thực hiện và cài đặt thuật toán **Selection Sort**.
Ý tưởng của thuật toán Selection Sort rất đơn giản. Tại mỗi lượt khi sắp xếp ta sẽ chọn phần tử
nhỏ nhất (hoặc lớn nhất) để trở thành phần thử khoá trong dãy các phần tử còn lại. Cách sắp xếp được tiến hành như sau:<br/>
Ở lượt thứ nhất, ta phải chọn được phần tử nhỏ nhất trong dãy k[1..n] và đổi chỗ với k[1]<br/>
Ở lượt thứ hai, ta phải chọn ra được phần tử nhỏ nhất trong dãy k[2..n] và đổi chỗ với k[2]<br/>
...<br/>
Ở lượt thứ n-1, ta chọn được ra phẩn tử nhỏ nhất trong dãy k[n-1..n] và đổi chỗ với k[n-1]<br/>

{% highlight pseudocode %}
void function SelectionSort() {
    int jmin;
    for (int i = 0; i < n - 1; i ++) {
        jmin = i;
        for (int j = i + 1; i < n; i ++>) {
            if (arr[i] > arr[j]) {
                jmin = j; // tìm phần tử nhỏ nhất trong dãy arr[i..n]
            }
        }
        if (jmin != i) {
            <Đổi chỗ 2 phần tử arr[i] và arr[jmin]>
        }
    }
}
{% endhighlight %}

Độ phức tạp của thuật toán luôn là $$O(n^2)$$ bấp chấp dữ liệu ban đầu như thế nào.
Ưu điểm là thuật toán rất đơn giản, dễ cài đặt cho người mới bắt đầu. Hãy cùng xem cách
cài đặt trường trình bằng C++ như sau:

{% highlight c++ %}
{% include codes/algo/sorting/selectionSort.cpp %}
{% endhighlight c++ %}

Kết quả khi chạy chương trình trên sẽ như sau:

{% highlight pseudocode %}
1	2	3	4	5
{% endhighlight %}
