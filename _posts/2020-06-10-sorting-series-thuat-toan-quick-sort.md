---
layout: post
title: "[Sorting series] Thuật toán sắp xếp QuickSort"
redirect_from:
    - /sorting-series-thuat-toan-quick-sort/
date: 2020-06-10 23:00
category:
    - Programming
    - Data Structures and Algorithms
    - Sorting Problem
tags: 
    - C++
---
**QuickSort** là một thuật toán sắp xếp hiệu quả được đề xuất bởi **Tony Hoare** năm 1959-1961. Đây là một thuật toán được sử dụng phổ biến trong bài toán sắp xếp.
Chính vì sự hiệu quả của nó mà tác giả đã đặt tên cho thuật toán là QuickSort.

Ý tưởng của thuật toán như sau, sắp xếp dãy khoá k[1..n]. Đầu tiên ta cần tìm được
một điểm ngẫu nhiên trong dãy làm **chốt (pivot)**. Sau đó mọi khoá nhỏ hơn sẽ được
xếp vào vị trí trước pivot, và các khoá lớn hơn sẽ được xếp vào vị trí sau pivot.
Sau phép hoán đổi như vậy ta chia đoạn khoá ban đầu thành hai đoạn mà mọi khoá trong
đoạn đầu thì **$$\leq$$ chốt** và mọi khoá trong đoạn sau đều **$$\geq$$ pivot**.
Vấn đề trở thành sắp xếp hai đoạn con mới bằng phương pháp tương tự.

Độ phức tạp của thuật toán QuickSort trong trường hợp xấu nhất là **$$O(n^2)$$** khi
mà _tại mỗi bước chọn chốt để phân đoạn, ta chọn được khoá lớn nhất hoặc nhỏ nhất_. Khi
đó một đoạn sẽ gồm 1 phần tử và đoạn còn lại gồm n - 1 phần tử. Tuy nhiên việc ngẫu
nhiên chọn khoá làm pivot trong thực tế rất khó để xảy ra trường hợp này. Vì vậy thời
gian thực hiện của QuickSort trung bình là **O(nlogn)**. Việc chứng minh kết quả khá
phức tạp, bạn đọc có thể tìm hiểu thêm. Dưới đây là cách cài đặt thuật toán QuickSort bằng C++ mọi người có thể tham khảo.

{% highlight c++ %}
{% include codes/algo/sorting/quickSort.cpp %}
{% endhighlight c++ %}

Kết quả khi chạy chương trình trên sẽ như sau:

{% highlight pseudocode %}
1	2	3	4	5
{% endhighlight %}