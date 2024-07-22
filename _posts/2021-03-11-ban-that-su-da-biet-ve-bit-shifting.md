---
layout: post
title: Bạn thật sự đã biết về Bit shifting
redirect_from:
    - /ban-that-su-da-biet-ve-bit-shifting
date: 2021-03-11 22:24
category:
    - Bit Manipulation
---
Bit shifting là một thao tác dịch bit trong ngôn ngữ lập trình thường hỗ trợ khi làm việc với bit.
Trong bài trước chúng ta có tìm hiểu cách biểu diễn số âm trong máy tính. Vậy khi dịch bit với
số âm và số dương liệu khác nhau như thế nào? Chúng ta sẽ cùng tìm hiểu trong bài viết này.
Như đã biết việc dịch bit sẽ có dịch bit sang trái hoặc phải một số lượng bit nhất định.
Cách dịch bit đối với số âm là khác đối với số tự nhiên, vì vậy chúng ta có hai cách dịch bit
như sau: (Cũng không biết dịch sang tiếng việt như thế nào)

**1. Arithmetic shift**

Được sử dụng để dịch bit cho số âm. Khi dịch bit sang bên trái thì bit 0 sẽ được chèn vào.
Khi dịch bit sang bên phải thì bit của dấu sẽ được chèn vào.

```pseudocode
// dich bit sang trái 2
10010111 -> 01011100
// dịch bit sang phải 2
10010111 -> 11100101
```

**2. Logic shift**

Khi không phải là số âm. Việc dịch bit sang trái và phải sẽ giống nhau là chèn bit 0 vào.
Đơn giản hơn so với việc dịch bit của số âm.

```pseudocode
// dich bit sang trái 2
010010111 -> 001011100
// dịch bit sang phải 2
01010111 -> 00
010101
```