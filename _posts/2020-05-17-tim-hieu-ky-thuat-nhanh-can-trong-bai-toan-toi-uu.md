---
title: Tìm hiểu kỹ thuật nhánh cận trong bài toán tối ưu
date: 2020-05-17 10:31
category:
    - Programming
    - Data Structures and Algorithms
    - Listing Problem
tags:
    - Python
---
Trong bài trước chúng ta đã tìm hiểu về [thuật toán quay lui]({% post_url 2020-04-24-thuat-toan-lui-trong-bai-toan-liet-ke %})
trong bài toán liệt kê. Nếu chúng ta thay đổi bài toán thành tìm ra **một** nghiệm thoả mãn một số điều
kiện nào đó, và nghiệm đó là **tốt nhất** theo một tiêu chí cụ thể. Thì bài toán sẽ trở thành bài toán tối ưu.

Chúng ta có thể sử dụng thuật toán quay lui trong bài toán liệt kê để tìm ra lời giải bằng cách liệt kê
ra tất cả các cấu hình có thể và đánh giá, tìm ra cấu hình tốt nhất. Nhưng nếu xét hết tất cả các cấu hình
thì sẽ mất rất nhiều thời gian và có thể lãng phí. Nếu chúng ta có thể đánh giá tại mỗi bước của thuật toán
quay lui, khi đi tiếp bước tiếp theo không mang lại kết quả tốt hơn so với cấu hình tốt nhất hiện tại. Chúng ta
có thể loại bỏ sớm phương án đó. Kỹ thuật này gọi là kỹ thật đánh giá nhánh cận trong tiến trình quay lui.
Mô hình của thuật toán nhánh cận có thể mô tả như sau:
{% highlight pseudocode %}
<khởi tạo một cấu hình bất kỳ cho BESTCONFIG>
void function Attemp(i) {
    for <mọi giá trị V có thể gán cho x[i]> {
        <thử x[i] := V>;
        if <việc thử trên vẫn còn hi vọng tìm ra cấu hình tốt hơn BESTCONFIG> {
            if <x[i] là phần tử cuối cùng trong cấu hình> {
                <cập nhật BESTCONFIG>
            } else {
                <ghi nhận việc thử x[i] = V (nếu cần)>;
                Attemp(i + 1);
                <bỏ ghi nhận việc thử x[i] := V (nếu cần)>;
            }
        }
    }
}
{% endhighlight %}
Chúng ta cùng xem bài toán người du lịch Cho n thành phố đánh số từ 1 đến n và m tuyến đường giao thông hai
chiều giữa chúng, mạng lưới giao thông này được cho bởi bảng C cấp nxn, ở đây C[i, j] = C[j, i] = Chi phí đi
đoạn đường trực tiếp từ thành phố i đến thành phố j. Giả thiết rằng C[i, i] = 0 với ∀i, C[i, j] = +∞ nếu không
có đường trực tiếp từ thành phố i đến thành phố j.

Một người du lịch xuất phát từ thành phố 1, muốn đi thăm tất cả các thành phố còn lại mỗi thành phố đúng 1 lần
và cuối cùng quay lại thành phố 1. Hãy chỉ ra cho người đó hành trình với chi phí ít nhất. Bài toán đó gọi là
bài toán người du lịch hay bài toán hành trình của một thương gia (Traveling Salesman).

Hãy cùng xem cách cài đặt thuật toán bằng C++ trong đoạn chương trình dưới đây.

{% highlight c++ %}
{% include codes/algo/lietke/branchandbound.cpp %}
{% endhighlight %}
Kết quả sau khi chạy chương trình.
{% highlight pseudocode %}
Path: 1 -> 3 -> 2 -> 4 -> 1
Cost: 6
{% endhighlight %}