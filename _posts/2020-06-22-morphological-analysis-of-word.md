---
title: Phân tích hình thái (Morphological Analysis) trong xử lý ngôn ngữ tự nhiên
date: 2020-06-22 09:27
category:
    - NLP
    - Morphological Analysis
tags: [Python]
---
**Phân tích hình thái (Morphological Analysis)** là một quá trình xử lý để cung cấp thông tin về từ
trong một câu. Đây được coi là bước xử lý đầu tiên trong xử lý ngôn ngữ tự nhiên. Đối với tiếng anh chúng ta có những khâu như sau:

- chia một từ thành morphemes. Ví dụ: unkindly = un + kind * ly
- quyết định parts-of-speech của từ (POS tagging)

Một từ có thể có nhiều POSs, việc chọn đúng POSs cho từng từ là quan trọng để làm đầu vào cho
bước tiếp theo **phân tích cú pháp (Syntatic Analysis)** trong NLP.

Trong bài viết này, chúng ta sẽ đề cập tới phương pháp sử dụng **word dictionary** để POSs các
từ trong một câu. Đầu vào của chúng ta sẽ gồm có 2 thành phần quan trọng:
- Từ điển chứa các word cùng với POSs của các word.
- Bảng kết nối (Connection Table) chứa thông tin các POSs kết nối với nhau như thế nào

Cho một câu, với từ điển và bảng kết nối, chúng ta cần tạo một **word lattice** cho câu đầu vào.
Word lattice là một đồ thị của việc phân tích hình thái học. Mỗi node sẽ chứa một từ và POS của nó.
Trong khi đó cạnh kết nối giữa các node được quyết định từ bảng kết nối. Khi xây dựng word lattice, chúng ta sẽ
có một đồ thị có hướng và có thể tồn tại nhiều path từ điểm bắt đầu tới điểm kết thúc.
Có nghĩa rằng một từ có thể POS tagging theo nhiều cách, việc này khiến chúng ta phải suy nghĩ rằng.
Path nào trong word lattice là chính xác nhất so với những path còn lại trong đồ thị. Để trả lời câu hỏi này,
chúng ta sẽ tìm hiểu thuật toán Viterbi trong bày tiếp theo. Dưới đây là chương trình cài đặt cách xây dựng
word lattice, từ đó biết được những POS tagging cho một câu đưa vào. Quá trình thực hiện thuật toán chỉ phụ
thuộc vào từ điển và bảng kết nối ban đầu.

Đầu ra mong muốn của phân tích hình thái (Morphological Analysis) là một POSs tagging của các từ trong một câu.

{% highlight python %}
{% include codes/problems/morphological-analysis.py %}
{% endhighlight c++ %}