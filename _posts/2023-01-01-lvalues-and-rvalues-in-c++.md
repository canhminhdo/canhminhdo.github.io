---
layout: post
title: Lvalues and Rvalues in C++
date: 2021-12-03 15:20
category:
    - C++
---

Lvalues và Rvalues là khái niệm quan trọng trong C++ để có thể hiểu được những chức năng mới được giới thiệu từ C++11. Trong C++, một lvalue được trỏ tới một vị trí cụ thể trong bộ nhớ. Còn một rvalue không được trỏ tới đâu cả. Rvalues là tạm thời và tồn tại trong thời gian ngắn, trong khi đó lvalues có thể tồn tại lâu dài miễn là biến đó vẫn tồn tại. Nếu bạn nghĩ lvalues và một nơi chứa thì rvalues là thứ được chứa trong đó. Không có nơi chứa thì những thứ đó sẽ không tồn tại.

Hãy cùng đi vào một ví dụ cụ thể sau:

```C++
int x = 8888; // ok
```

Trong ví dụ này `8888` là một rvalue, một hằng số đơn thuần và không có một địa chỉ bộ nhớ cụ thể nào ngoài việc được lưu trữ ở trong thanh ghi tạm thời khi chương trình đang chạy. Biến `x` có một giá trị bộ nhớ cụ thể và được gán giá trị `8888`, vì vậy `x` là một rvalue. Trong C++ thì toán tử gán yêu cầu toán hạng bên trái là một lvalue, trong khi đó toàn hạng bên phải có thể là lvalue hoặc rvalue.

```C++
int* y = &x; // ok
666 = x; // error!
```
Một vài ví dụ trên cho bạn hình dung rằng chúng ta không thể sử dụng một rvalue cho toán hạng ở bên trái.

### Functions trả về lvalues và rvalues

Nếu functions trả về rvalues và được sử dụng trong phép gán bên tay trái là không hợp lệ như sau:

```C+
int setValue() {
    return 6;
}
setValue() = 3; // error!
```

Tuy nhiên nếu functions trả về lvalues, chúng ta có thể sử dụng trong phép gán như sau:

```C++
int global = 100;
int& setGlobal() {
    return global;
}
setGlobal() = 400; // OK
```

Một tham chiếu (`reference`) trỏ tới một địa chỉ bộ nhớ cụ thể đã tồn lại. Vì vậy nó cũng được coi là lvalue. Chú ý rằng `&` sử dụng trong kiểu giá trị trả về của hàm ở trên không phải là toán tử lấy về địa chỉ, nó được sử dụng để định nghĩa giá trị trả về là một `lvalue reference` (chúng ta sẽ tìm hiểm trong phần dưới).

### Chuyển lvalues sang rvalues

Một lvalue có thể được chuyển thành rvalue. Ví dụ toán tử `+` trong C++ yêu cầu hai toán hạng là rvalues. Tuy nhiên hãy xem ví dụ sau:

```C++
int x = 1;
int y = 2;
int z = x + y; // ok
```

Rõ ràng `x` và `y` là lvalues, nhưng toán tử `+` mong muốn rvalues. C++ sẽ ngầm chuyển đổi lvalues sang rvalues cho chúng ta.

### Lvalue reference

Liệu rvalues có thể được chuyển thành lvalues? Câu trả lời là không.

```C++
int x = 10;
int& xref = x;
xref++; // x is now 11
```

Chúng ta đang khai báo `xref` là một biến tham chiếu tới `x` và được gọi là `lvalue reference`. Giờ chúng ta có thể thay đổi giá trị `x` thông qua `xref`.
Nếu chúng ta gán `10` tới `xref` như ví dụ dưới liệu có hợp lệ không?

```C++
int& xref = 10; // will it work?
```

Toán hạng bên phải là một giá trị tạm thời và cần phải được lưu trữ ở đâu đó trong một lvalue để có thể tham chiếu tới. Nhưng `10` là một giá trị cụ thể và không có một địa chỉ cụ thể trong bộ nhớ. Vì vậy ta không thể làm như vậy. Tương tự như trong ví dụ sau:

```C++
void func(int& x) {}
int main() {
    func(10); // error
}
```

### Const lvalue reference có thể giải quyết được

Tuy nhiên, chúng ta có thể sử dụng một `const lvalue` để gắn một rvalue như sau:

```C++
const int& ref = 10; // ok
```

Và ví dụ sau cũng hoàn toàn hợp lệ:

```C++
void func(const int& x) {}
int main() {
    func(10); // OK
}
```

Giá trị `10` sẽ hết hạn ngay lập tức, vì vậy một `reference` tới nó là không có ý nghĩa gì. Tuy nhiên chúng ta có thể tạo biến `const lvalue reference` với giá trị trỏ đến không thể bị thay đổi. Để có thể làm vậy C++ compiler sẽ tạo một `hidden variable` để lưu trữ giá trị `10` và gắn `hidden variable` tới biến tham chiếu như sau.

```C++
const int& ref = 10;

// would translate to
int __internal_unique_name = 10;
const int& ref = __internal_unique_name;
```

Bây giờ mọi thử trở dễ hiểu hơn khi biến tham chiếu trỏ tới một vị trí bộ nhớ cụ thể và chúng ta có thể dụng như bình thường nhưng không được sửa đổi nó.

### Kết luận
Hiểu được ý nghĩa của lvalues và rvalues giúp chúng ta hiểu được những khái niệm mới như rvalue references, move semantics và perfect forwarding trong các bài viết tới.