---
layout: post
title: Phương pháp sinh trong bài toán liệt kê
redirect_from:
    - /phuong-phap-sinh-trong-bai-toan-liet-ke/
date: 2020-04-23 14:39
category:
    - Programming
    - Data Structures and Algorithms
    - Listing Problem
tags:
    - C++
---
Phương pháp sinh là một kỹ thuật để liệt kê các cấu hình nếu thoả mãn
hai điều kiện sau:
* Có thể **xác định được thứ tự** trên tập hợp các cấu hình tổ hợp cần liệt kê.
Từ đó biết được cấu hình đầu tiên và cấu hình cuối cùng.
* **Xây dựng được thuật toán** từ một cấu hình chưa phải cuối, sinh ra được cấu hình kế tiếp.

{% highlight pseudocode %}
<Xây dựng cấu hình đầu tiên>;
repeat
    <Đưa ra cấu hình đang có>;
    <Từ cấu hình đang có sinh ra cấu hình tiếp theo nếu còn>;
until <hết cấu hình>;
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
{% include codes/algo/lietke/generation.cpp %}
{% endhighlight %}