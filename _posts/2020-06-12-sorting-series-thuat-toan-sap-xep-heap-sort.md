---
layout: post
title: "[Sorting series] Thuật toán sắp xếp HeapSort"
redirect_from:
    - /sorting-series-thuat-toan-sap-xep-heap-sort/
date: 2020-06-12 23:06
category:
    - Programming
    - Data Structures and Algorithms
    - Sorting Problem
tags: 
    - C++
---
HeapSort không những là một thuật toán sắp xếp hiệu quả mà còn xây dựng một
cấu trúc dữ liệu quan trọng để biểu diễn hàng đợi có độ ưu tiên.

**1. Đống (Heap)**

Đống là một dạng cây nhị phân hoàn chỉnh đặc biệt mà giá trị lưu lại mọi nút
có độ ưu tiên cao hơn hay bằng giá trị lưu trong hai nút con của nó.

**2. Vun đống**

Cho một dãy khoá k[1..n] là biểu diễn của một cây nhị phân hoàn chỉnh thì giá
trị lưu trong nút thứ i, có hai nút con là 2i và 2i + 1. Để vun một nhánh cây
gốc r thành đống, ta có thể coi hai nhánh con của nó là 2r và 2r+1 đã là đống rồi.
Việc tự hiện vun đống sẽ xuất phát từ dưới lên. Gọi h là chiều cao của cây thì ta sẽ
bắt đầu vun đống tại nút h / 2. Bởi vì những nút là ta coi như đã là đống với một phần
tử. Ta cần xét bắt đầu từ phần tử đầu tiên có chứa nút lá để vun đống. Từ đó ta vun
dần lên tới khi gặp nút gốc đầu tiên của đống.

Thuật toán HeapSort có hai thủ tục chính
- Thủ tục heapify(root, endNode) vun cây gốc root thành đống trong điều kiện 2 * root và
2 * root + 1 đã là đống rồi. Các nút từ endNode + 1 tới n đã nằm ở vị trí đúng và không
tính tới nữa
- Thủ tục HeapSort mô tả lại quá trình vun đống và chón khoá theo ý tưởng trên.

Về độ phức tạp của thuật toán, cây nhị phân hoàn chỉnh có **n** nút thì chiều cao của nó là
**log(n) + 1**. Trong trường hợp xấu nhất thủ tục heapify tìm đường đi từ nút gốc tới nút
lá xa nhất bằng chiều cao của cây thì thời gian thực hiện một lần heapify là **O(log(n))**.
Ta sẽ gọi **n** lần, vì vậy thời gian trong trường hợp xấu nhất của HeapSort cũng chỉ là
**O(nlog(n))**. Việc đánh giá thời gian thực hiện trung bình phức tạp, ta chỉ thừa nhận là
độ phức tạp của HeapSort là **O(nlog(n))**

Dưới đây là cách cài đặt thuật toán HeapSort bằng C++ bạn đọc có thể tham khảo

{% highlight c++ %}
{% include codes/algo/sorting/heapSort.cpp %}
{% endhighlight c++ %}

Kết quả khi chạy chương trình trên sẽ như sau:

{% highlight pseudocode %}
1	2	3	4	5
{% endhighlight %}

