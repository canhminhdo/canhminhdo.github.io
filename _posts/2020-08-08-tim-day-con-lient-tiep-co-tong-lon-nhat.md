---
title: Tìm dãy con liên tiếp có tổng lớn nhất
date: 2020-08-08 23:40
category:
    - Programming
    - Data Structures and Algorithms
tags: [C++]
---
Dãy con liên tiếp có tổng lớn nhất (maximum subarray problem) là việc tìm ra
một dãy con chứa các phần tử liên tiếp trong một dãy cho trước thoả mãn tổng
của dãy con được chọn là lớn nhất. Xem thêm [tại đây](https://en.wikipedia.org/wiki/Maximum_subarray_problem).

Ví dụ: cho một dãy số [−2, 1, −3, 4, −1, 2, 1, −5, 4], dãy con liên tiếp có tổng
lớn nhất là [4, -1, 2, 1] với tổng là 6.

Tuỳ vào từng cách cài đặt, chúng ta có thể có độ phức tạp thuật toán là $$O(n^3)$$, $$O(n^2)$$ hay $$O(n)$$.
Dưới đây là cách cài đặt thuật toán với độ phức tạp là $$O(n^3)$$. Với **i** là phần tử đầu tiên của dãy con,
**j** là phần tử cuối cùng của dãy con, **k** được lặp để tính tổng của dãy con **[i, j]** và so sánh với **best**
để lấy giá trị lớn nhất.

{% highlight c++ %}
int best = INT_MIN;
for (int i = 0; i < n; i ++) {
    for (int j = i; j < n; j ++) {
        int sum = 0;
        for (int k = i; k <= j; k ++) {
            sum += arr[k];
        }
        best = max(best, sum);
    }
}
{% endhighlight c++ %}

Chúng ta có thể cải thiện thuật toán để có được độ phức tạp là $$O(n^2)$$. Bằng cách loại bỏ vòng lặp **k**,
và tính toán tổng ngay trong vòng lặp **j** như sau.

{% highlight c++ %}
int best = INT_MIN;
for (int i = 0; i < n; i ++) {
    int sum = 0;
    for (int j = i; j < n; j ++) {
        sum += arr[i];
        best = max(best, sum);
    }
}
{% endhighlight c++ %}

Để có thể giảm độ phức tạp tính toán xuống $$O(n)$$, chúng ta cùng tìm hiểu thuật toán **Kadane's algorithm**.
Tư tưởng của thật toán là chia bài toán thành bài toán nhỏ hơn, bằng cách tìm dãy con có tổng lớn nhất kết thúc
tại vị trí k trong dãy. Khi đó sẽ có hai trường hợp xảy ra:
1. Dãy con chỉ chứa phần thử thứ **k**. So sánh **best** với phần tử thứ **k** để cập nhật giá trị lớn nhất.
2. Dãy con chứa phần tử thứ **k** và dãy con kết thúc ở phần thử thứ **k - 1**. Cập nhật tổng mới dựa trên tổng
của dãy con **k - 1** và cộng thêm phần tử thứ **k**. So sánh tổng mới với **best** để cập nhật giá trị lớn nhất.

Thuật toán được cài đặt như sau:

{% highlight c++ %}
int best = INT_MIN;
int sum = 0;
for (int i = 0; i < n; i ++) {
    sum = max(arr[i], sum + arr[i]);
    best = max(sum, best);
}
cout << best << "\n";
{% endhighlight c++ %}

Cách cài đặt chi tiết, cũng như lưu thông tin chỉ số của dãy con có tổng lớn nhất được mô tả sau đây. Bạn đọc có
thể tham khảo

{% highlight c++ %}
{% include codes/problems/subArrayMax.cpp %}
{% endhighlight c++ %}

Kết quả khi chạy chương trình trên sẽ như sau:

{% highlight pseudocode %}
6
start from 3 to 6
{% endhighlight %}



