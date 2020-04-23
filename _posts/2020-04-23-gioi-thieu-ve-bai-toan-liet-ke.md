---
title: Giới thiệu về bài toán liệt kê
date: 2020-04-23 14:39
category:
    - Programming
    - Data Structures and Algorithms
    - Listing Problem
tags: [C++]
---
Trong thực tế có một số bài toán cho trước một tập các đối tượng,
hỏi có bao nhiêu đối tượng thoả mãn một điều kiện nào đó. Bài toán
đó gọi là **bài toán đếm**.

Trong bài toán đếm, có thể yêu cầu thêm chỉ rõ những cấu hình tìm được
thoả mãn điều kiện đã cho. Bài toán yêu cầu đưa ra danh sách các cấu hình
được gọi là **bài toán liệt kê**

Để giải quyết bài toán liệt kê, cần phải xây dựng được một thuật toán có thể
lần lượt xây dựng được tất cả cấu hình theo một điều kiện đã cho. Có một vài
phương pháp liệt kê sẽ được trình bày trong series này. Các phương pháp cần
phải đáp ứng được yêu cầu:
- Không được lặp lại một cấu hình
- Không được bỏ sót một cấu hình
Phương pháp liệt kê chúng ta cần phải xét hết tất cả các cấu hình và tìm cấu hình
thoả mãn, vì vậy dễ dẫn tới sự bùng nổ tổ hợp các cấu hình. Vậy chỉ nên dùng phương
pháp liệt kê khi không còn phương pháp nào khác để tìm ra lời giải.

Các bài viết sau sẽ giới thiệu lần lượt về thuật toán:
1. Phương pháp sinh
2. Thuật toán quay lui
3. Kỹ thuật nhánh cận
