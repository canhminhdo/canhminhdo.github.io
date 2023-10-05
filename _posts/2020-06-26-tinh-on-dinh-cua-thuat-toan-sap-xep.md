---
layout: post
title: Tính ổn định của thuật toán sắp xếp (STABILITY)
date: 2020-06-26 23:20
category:
    - Programming
    - Data Structures and Algorithms
    - Sorting Problem
tags: 
    - C++
---
Một phương pháp sắp xếp được gọi là **ổn định** nếu nó đảm bảo thứ tự ban đầu của các bản ghi mang khoá
bằng nhau trong danh sách. Ví dụ danh sách sinh viên ban đầu theo thứ tự alphabet, khi sắp xếp theo thứ
tự giảm dần của điểm thì những sinh viên bằng điểm nhau sẽ được sắp xếp mà vẫn giữ được nguyên thứ tự
sắp xếp theo alphabet.

Về cơ bản thì bất kỳ thuật toán sắp xếp nào cũng có thể đưa về để đảm bảo được tính ổn định khi sắp xếp.
Bằng cách lưu các index của các khoá trong mảng cần sắp xếp, khi sắp xếp mà gặp các phần tử khoá có cùng
giá trị, ta có thể so sánh xem giá trị nào nên đứng trước giá trị khoá kia bằng cách so sánh index của
các khoá.

Trong các thuật toán sắp xếp đã tìm hiểu trong sorting series, thì thuật toán mà mặc định đã đảm bảo tính
ổn định gồm có những thuật toán sau.

Updating ...