---
layout: post
title: Cách biểu diễn số âm trong máy tính
redirect_from:
    - /cach-bieu-dien-so-am-trong-trong-may-tinh
date: 2021-01-10 17:27
category:
    - Bit Manipulation
---
Trong máy tính, mọi kí hiệu, con số đều được biểu diễn dưới dạng số nhị phân 0 và 1.
Vậy làm thế nào để biểu diễn và phân biệt được số dương và số âm trong máy tính.
Có nhiều cách để biểu diễn số âm trong máy tính, bạn có thể tham khảo [tại đây](https://vi.wikipedia.org/wiki/Bi%E1%BB%83u_di%E1%BB%85n_s%E1%BB%91_%C3%A2m).

Tuy nhiên, các máy tính hiện nay đều sử dụng **phương pháp bù 2 (Two's complement)**. Vì vậy
chúng ta sẽ cùng tìm hiểu cách biểu diễn số âm bằng phương pháp bù 2 trong bài viết này nhé.

Giải sử một số được biểu diễn trong máy tính với 8 bit. Thì một bit đầu tiên từ bên phải
sẽ được sử dụng làm bit dấu, các bit còn lại sẽ được sử dụng để thể hiện giá trị của nó.
Ví dụ số 5 biểu diễn theo hệ nhị phân, thì chúng ta sẽ có **0000 0101**. Giờ thì làm thế
nào có thể biểu diễn số -5 theo hệ nhị phân. Chúng ta có thể đoán được là bit đầu tiên sẽ
là 1, vậy các bit còn lại sẽ là những bit như thế nào.

Biểu diễn số **-5** bằng phương pháp bù 2, chúng ta thực hiện theo các bước sau:
- Bước 1: Lấy biểu số nhị phân của 5 là **0000 0101**, ở trên đã có.
- Bước 2: Đảo tất cả các bit của 5, ta sẽ có **1111 1010**
- Bước 3: Cộng giá trị vừa nhận được với **1**, ta có **1111 1011**

Vậy với phương pháp bù 2, số **-5** được biểu diễn ở hệ nhị phân trong máy tính là **1111 1011**,
có thể thấy rằng bit đầu tiên của số âm luôn là **1**.

Từ một số nhị phân biểu diễn số âm, làm thế nào có thể biết được giá trị thập phân của nó.
Chúng ta sẽ làm theo chiều ngược lại một cách dễ dàng như sau.

Ví dụ chúng ta muốn biết **1111 1011** là số thập phân gì?

- Bước 1: Đảo tất cả các bit của số nhị phân đó, ta có **0000 0100**
- Bước 2: Cộng kết quả vừa có với **1**, chúng ta sẽ có **0000 0101**
- Bước 3: Tính toán ra số dương bình thường ở hệ cơ số 2 ta có giá trị **\\(2^2 + 2^1 = 5\\)**
- Bước 4: Thêm dấu - vào trước giá trị vừa tìm, ta có được kết quả là **-5**

Đến đây ta có thể dễ dàng chuyển đổi từ một số âm sang số nhị phân và ngược lại.
Có một chú ý khi bạn thao tác trên số nhị phân biểu diễn cho số âm là hiện tượng
**tràn số**. Ví dụ, khi chúng ta chỉ sử dụng 4 bit để biểu diễn một số. Và ta có số -6 và -4
được biểu diễn sang hệ nhị phân lần lượt là **1010**, số **1100**. Nếu ta cộng hai số sẽ có kết quả
là **\\(1010 + 1100 = 0110\\)**. Rõ ràng **0110** khi ta chuyển sang số thập phân là **6**,
chứ không phải là **-10** như chúng ta mong muốn. Đây là một kết quả không chính xác,
khi chúng ta sử dụng số lượng bit để biểu diễn quá ít.

Dựa vào cách tính toán trên, chúng ta có thể thấy rằng **~(-X) + 1 = X**. Vì vậy,
ứng dụng trong lập trình nếu ta nghịch đảo các bit của một số âm **-X** thì sẽ nhận
được một giá trị dương là **X - 1**.

