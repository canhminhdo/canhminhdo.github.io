---
layout: post
title: Tìm hai số bất kỳ trong dãy số có tổng bằng k
redirect_from:
    - /tim-hai-so-bat-ky-trong-day-co-tong-bang-k
date: 2020-05-02 11:56
category:
    - Programming
    - Data Structures and Algorithms
tags:
    - Python
---
Trong bài viết này, chúng ta cùng tìm hiểu bài toán tìm hai số bất kỳ trong dãy số
có tổng bằng k. Có nhiều cách giải có thể được áp dụng trong bài toán, tác giả sẽ
trình bày một cách giải có độ phức tạp tính toán thấp nhất.

Giả sử ta có một dãy số **arr = [10, 15, 3, 7]** và **k = 17**, hai số trong dãy có
thể có thể là **10** và **7**. Chúng ta có thể sử dụng 2 vòng lặp để có thể hoàn thành
bài toán này một cách đơn giản như sau:
{% highlight python %}
arr = [10, 15, 3, 7]
k = 17
for i in range(len(arr) - 1):
    for j in range(1, len(arr)):
        if arr[i] + arr[j] == k:
            print(arr[i], arr[j]);
{% endhighlight %}

Với cách tiếp cận trên chúng ta cần dùng 2 vòng lặp và không phải dùng thêm bộ nhớ tạm.
Nhưng độ phức tạp của thuật toán sẽ là $$O(N^2)$$. Trong thực tế độ phức tạp tính toán
là quan trọng hơn bộ nhớ tạm, chúng ta có thể lắp thêm và chi phí rẻ hơn nhiều so với độ
phức tạp tính toán. Nếu độ dài dãy là **1,000,000** số thì số vòng lặp sẽ là $$1,000,000^2$$.
Một con số rất là lớn, sau đây chúng ta sẽ xem một cách tiếp cận khác sử dụng hashtable để
có thể tìm được kết quả bài toán với độ phức tạp $$O(N)$$ - Time Complexity nhưng cần phải sử dụng thêm bộ
nhớ tạm với độ phức tạp không gian $$O(N)$$ - Space Complexity.

{% highlight python %}
{% include codes/problems/sum.py %}
{% endhighlight %}

Việc sử dụng thêm hashtable sẽ cần thêm bộ nhớ, nhưng với việc sử dụng hashtable thì việc tìm
kiếm một phần tử trong hashtable chỉ mất **O(1)**. Ý tưởng của thuật toán là duyệt qua dãy một
vòng lặp, tại mỗi vòng lặp kiểm tra liệu tổng k trừ đi phần tử hiện tại arr[i] là (k - arr[i])
có tồn tại ở trong hashtable không. Nếu tồn tại thì ghi kết quả ra màn hình, ngược lại sẽ lưu
giá trị hiện tại như key và index trong mảng như value vào trong hashtable để thực hiện vòng lặp tiếp
theo.

Như vậy, chúng ta đã tìm hiểu cách sử dụng hashtable trong bài toán này. Hashtable là cấu trúc dữ liệu
được dùng phổ biến trong thực tế, khi việc truy xuất một phần tử trong hash chỉ mất thời gian O(1).