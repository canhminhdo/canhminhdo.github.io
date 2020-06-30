---
title: Tìm hiểu về định lý Bayes và ứng dụng
date: 2020-06-30 11:21
category:
    - Machine learning
tags: [Classifier, Bayes]
---
Định lý Bayes là một định lý toán học để tính xác suất xảy ra của một sự kiện ngẫu nhiên **A**
khi biết sự kiện liên quan **B** đã xảy ra.

**1. Xác suất có điều kiện**

Ta có 2 sự kiện ngẫu nhiên A và B, nếu A và B là hai sự kiện liên quan tới nhau:
<center>$$P(A,B) = P(A|B) P(B)$$ or $$P(A,B) = P(B|A) P(A)$$</center>
Nếu hai sự kiện A và B là độc lập với nhau thì công thức trên sẽ trở thành:
<center>$$P(A,B) = P(A) P(B)$$</center>

**2. Định lý Bayes**

Định lý Bayes dựa trên định nghĩa về xác suất có điều kiện ở trên, được phát biểu dưới
dạng công thức sau:
<center>$$P(A|B) = \frac{P(A) P(B|A)}{P(B)}$$</center>
**P(A)** - được gọi là xác suất tiền nghiệm (prior probability) khi chưa nhìn thấy B<br/>
**P(B|A)** - được gọi là likelihood, xác suất có điều kiện (conditional probability) khi nhìn thấy A<br/>
**P(A|B)** - được gọi là xác suất hậu nghiệp (posterior probability) khi nhìn thấy B<br/>
**P(B)** - được gọi là predictor Prior Probability hoặc evidence (tiếng việt nên gọi là gì)<br/>

**3. Naive Bayes**

Áp dụng công thức Bayes ở trên ta có như sau
<center>$$P(y|X) = \frac{P(y) P(X|y)}{P(X)}$$</center>
Cho $$X = (x_1, x_2, ..., x_n)$$ thay thế vào công thức trên ta có
<center>$$P(y|x_1,...,x_n) = \frac{P(y) P(x_1,..,x_n|y)}{P(x_1,...,x_n)}$$</center>
Dựa vào xác suất có điều kiện chúng ta có thể khai triển như sau
<center>$$P(x_1,...,x_n|y) = P(x_1|y,x_2,...,x_n)P(x_2,...,x_n|y)$$</center>
<center>$$P(x_1,...,x_n) = P(x_1|x_2,...,x_n)P(x_2,...,x_n)$$</center>
Naive Bayes cho chúng ta một giả thuyết rằng tất cả các biến ngẫu nhiên $$x_i$$ là độc lập với nhau.
Vì vậy ta có thể suy ra như sau:
<center>$$P(x_1|y, x_2,...,x_n) = P(x_1|y)$$</center>
<center>$$P(x_1|x_2,...,x_n) = P(x_1)$$</center>
Công thức ban đầu sẽ trở thành
<center>$$P(y|x_1,...,x_n) = \frac{P(y) \prod^n_{i=1}P(x_i|y)}{P(x_1)...P(x_n)}$$</center>
Để ước lượng xác suất của tất cả giá trị y với đầu vào X, ta có thể thấy rằng
$$P(X) = P(x_1)...P(x_n)$$ là một hằng số. Vì vậy, để tìm được sắc suất lớn nhất của giá trị y
với đầu vào X ta có công thức sau.
<center>$$P(y|x_1,...,x_n) \propto P(y) \prod^n_{i=1}P(x_i|y)$$</center>
<center>$$\hat{y} = \underset{y}{argmax}(P(y) \prod^n_{i=1}P(x_i|y))$$</center>

**4. Áp dụng vào bài toán sau**

Ta có một tập training set như sau:

||Doc|Words|Class|
| --- | --- | --- |---|
|Training|1|fish smoked fish|f|
||2|fish line|f|
||3|fish haul smoked|f|
||4|guitar jazz line|g|
|Test|5|line guitar jazz jazz|?|
|||V = {fish, smoked, line, haul, guitar, jazz}|

Đưa vào một dữ liệu **line guitar jazz jazz** hỏi rằng nó thuộc lớp **f** hay lớp **g**.
Chúng ta có thể áp dụng Naive Bayes để tính xác suất dữ liệu đưa vào thuộc lớp **f** hay lớp **g** như sau.

$$P(f|line, guitar, jazz, jazz) = p(line|f) P(guitar|f) P(jazz|f) P(jazz|f) P(f)$$

$$P(g|line, guitar, jazz, jazz) = p(line|g) P(guitar|g) P(jazz|g) P(jazz|f) P(g)$$

Xác suất tiền nghiệm được tính như sau (Priors):

$$P(c) = \frac{N_c}{N}$$

Có thể hiểu là tổng số class $$c$$ trên tổng toàn bộ các classs. Ta sẽ có kết quả là $$P(f) = 3/4$$ và $$P(g) = 1/4$$.

Xác suất có điều kiện được tính như sau (Conditional Probabilities):

$$P(w|c) = \frac{count(w,c) + \alpha}{count(c) + \alpha * |V|}$$

Cho vào một từ $$w$$, chúng ta đếm số lượng từ $$w$$ xuất hiện trong lớp $$c$$. Chia cho tổng số lượng từ
thuộc vào lớp $$c$$. Ngoài ra chúng ta sử dụng kỹ thuật **Laplace Smoothing** với $$\alpha = 1$$ để tránh trường hợp $$P(w|c) = 0$$
bằng cách cộng 1 vào tử và cộng số lượng từ trong từ điển vào mẫu. Nó sẽ không ảnh hưởng tới kết quả cuối
cùng. Ngoài ra bạn có thể sử dụng hàm $$log$$ để tránh gặp phải giá trị xác suất bằng 0.

$$P(line|f) = (1+1)/(8+6) = 2/14$$

$$P(guitar|f) = (0+1)/(8+6) = 1/14$$

$$P(jazz|f) = (0+1)/(8+6) = 1/14$$

$$P(line|g) = (1+1)/(3+6) = 2/9$$

$$P(guitar|g) = (1+1)/(3+6) = 2/9$$

$$P(guitar|g) = (1+1)/(3+6) = 2/9$$

Thay thế giá trị đã tính toán vào công thức ban đầu ta sẽ có kết quả sau

$$ P(f|line, guitar, jazz, jazz) = 2/14 * 1/14 * 1/14 * 1/4 * 3/4 \approx 0.00003$$

$$ P(g|line, guitar, jazz, jazz) = 2/9 * 2/9 * 2/9 * 2/9 * 1/4 \approx 0.0006$$

Dựa vào kết quả tính toán với Naive Bayes, chúng ta có thể dự toán dữ liệu đưa vào
**line guitar jazz jazz** thuộc vào lớp **g** với xác xuất cao hơn.
