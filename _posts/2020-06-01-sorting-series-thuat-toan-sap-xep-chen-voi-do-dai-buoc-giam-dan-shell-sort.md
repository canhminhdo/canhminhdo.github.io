---
title: \[Sorting series\] Sắp xếp chèn với độ dài bước giảm dần (ShellSort)
date: 2020-06-01 23:08
category:
    - Programming
    - Data Structures and Algorithms
    - Sorting Problem
tags: [C++]
---
Nhược điểm của thuật toán [Insertion Sort]({% post_url 2020-05-31-sorting-series-thuat-toan-sap-xep-insertion-sort %})
khi ta phải chèn một phần tử khoá vào vị trí gần đầu dãy. Để khắc phục nhược điểm này,
ta có thể sử dụng thuật toán chèn với độ dài bước giảm dần, được đưa ra bởi D.L.Shell.
Có thể vì vậy mà thuật toán có tên gọi là ShellSort.

Ý tưởng của thuật toán là chia dãy khoá **k[1..n]** thành **h** dãy con với $$1 \leq h \leq n$$.
Khi đó ta có các dãy con như sau:<br/>
Dãy con 1: k[1], k[1 + h], k[1 + 2h], ...<br/>
Dãy con 2: k[2], k[2 + h], k[2 + 2h], ...<br/>
...<br/>
Dãy con h: k[h], k[h + h], k[h + 2h], ...<br/>

Chúng ta áp dụng thuật toán Insertion Sort trên từng dãy con độc lập để làm mịn dầy dãy khoá
chính. Rồi làm tương tự với bước **h** giảm dần bằng **h div 2**. Cho tới khi **h = 1** thì ta
được một dãy khoá sắp xếp. ShellSort hoạt động nhanh và dễ cài đặt, tuy nhiên việc đánh giá độ
phức tạp thuật toán là tương đối khó, chúng ta chỉ thừa nhận kết quả (bạn đọc có thể tìm hiểu thêm).

Dưới đây là cách cài đặt của thuật toán ShellSort, mọi người có thể theo dõi.

{% highlight c++ %}
{% include codes/algo/sorting/shellSort.cpp %}
{% endhighlight c++ %}

Kết quả khi chạy chương trình trên sẽ như sau:

{% highlight pseudocode %}
1	2	3	4	5
{% endhighlight %}

