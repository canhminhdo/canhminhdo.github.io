---
layout: post
title: Thuật toán quay lui (backtracking) trong bài toán liệt kê
redirect_from:
    - /thuat-toan-lui-trong-bai-toan-liet-ke/
date: 2020-04-24 10:57
category:
    - Programming
    - Data Structures and Algorithms
    - Listing Problem
tags: 
    - C++
---
Thuật toán quay lui dùng để liệt kê các cấu hình mà mỗi cấu hình được xây dụng bằng
cách xây dựng từng phần tử, mỗi phần tử được chọn bằng tất cả các khả năng. Khi chọn
một giá trị có thể cho một phần tử, chúng ta tiếp tục liệt kê tất cả các cấu hình cho
những phần tử còn lại. Giả sử cấu hình cần xây dựng có dạng x[1..n], khi đó thuật toán
thực hiện các bước sau:
- Xét tất cả các giá trị x[1] có thể nhận được. Với mỗi giá trị gán cho x[1] chúng ta sẽ:
- Xét tất cả các giá trị x[2] có thể nhận được. Với mỗi giá trị gán cho x[2] chúng ta sẽ
xét tiếp tất cả các giá trị cho x[3], ...
- Xét tất cả các giá trị x[n] có thể nhận, với mỗi giá trị gán cho x[n], chúng ta có thêm
một cấu hình tìm được (x[1], x[2], ..., x[n])

Một cách giải thích khác có thể hiểu bằng cách thử cho x[1] nhận lần lượt các giá trị có thể.
Với mỗi giá trị thử gán cho x[1] bài toán trở thành liệt kê liên tiếp cấu hình n - 1 phần tử
x[2..n].
Mô hình của thuật toán quay lui có thể mô tả như sau:
{% highlight pseudocode %}
void function Attemp(i) {
    for <mọi giá trị V có thể gán cho x[i]> {
        <thử x[i] := V>;
        if <x[i] là phần tử cuối cùng trong cấu hình> {
            <thông báo cấu hình tìm được>
        } else {
            <ghi nhận việc thử x[i] = V (nếu cần)>;
            Attemp(i + 1);
            <bỏ ghi nhận việc thử x[i] := V (nếu cần)>;
        }
    }
}
{% endhighlight %}
Thuật toán quay lui sẽ bắt đầu bằng lời gọi **Attempt(1)**.

Chúng ta cùng xem một bài toán liệt kê tất cả các dãy nhị phân có độ dài N.
Một dãy nhị phân có độ dài N là một dãy X[1..N] trong đó X[i] $$\in$$ {0,1}
($$\forall$$ i $$\in$$ [1..N]). Khi n = 2, cùng xem cách liệt kê như sau:
- x[1] = 0
    - x[2] = 0
        print("00")
    - x[2] = 1
        print("01")
- x[1] = 1
    - x[2] = 0
        print("10")
    - x[2] = 1
        print("11")

Cùng cài đặt bài toán với thuật toán quay lui bằng C++ như sau:
{% highlight c++ %}
{% include codes/algo/lietke/backtracking.cpp %}
{% endhighlight %}