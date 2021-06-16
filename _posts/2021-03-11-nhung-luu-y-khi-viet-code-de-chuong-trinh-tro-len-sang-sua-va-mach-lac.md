---
title: Những lưu ý khi viết code để chương trình trở lên sáng sủa và mạch lạc
date: 2021-03-11 22:40
category:
    - code style
---
Việc viết code không những để cho máy tính đọc mà cũng cho lập trình viên đọc code của bạn.
Chính vì vậy việc viết code một cách có cấu trúc, dễ đọc không những giúp bạn có thể quản lý
mã nguồn và lỗi tốt mà còn dễ dàng sửa đổi. Sau đây chúng ta cùng xem một vài lưu ý khi viết
chương của mình.

**1. Names**

**Use descriptive names for globals, short names for locals**\\
Tên có thể là của variables hay functions, bạn nên đặt tên có chứa thông tin, ngắn gọn, dễ nhớ
và có thể phát âm được nếu có thể. Thường sẽ đặt tên theo tiếng anh vì vậy nên chú ý điểm này.
Có thể mô tả cho globals với một tên dài để gợi nhớ cho bạn khi viết code. Nhưng hãy dùng tên
ngắn cho locals. Vì trong một function, bạn có thể dùng một tên ngắn là đủ, ví dụ như sử dụng
**n** là đủ, **npoints** là tốt, **numberOfPoints** là quá mức. Bạn thường được khuyến khích
đặt tên dài bất chấp trong các hoàn cảnh nào, đó là một sai lầm vì sự rõ ràng thường sử dụng
ngắn gọn.

```C++
for (theElementIndex = 0; theElementIndex < numberOfElements; theElementIndex++)
    elementArray[theElementIndex] = theElementIndex;

for (i = 0; i < nelems; i++)
    elem[i] = i;
```

Hằng số (**CONSTANT**) thường đặt tên với tất cả chữ HOA, còn **Globals** thì bắt đầu bằng chữ Hoa.

**Be consistent**\\
Bên cạnh tránh viết tên quá dài, việc chú ý đến context trong scope đó. Như ví dụ sau, khi không
cần phải đề cập tên với Queue vì tên của class đã đề cập về điều đó.

```Java
class UserQueue {
    int noOfItemsInQ, frontOfTheQueue, queueCapacity;
    public int numOfUsersInQueue();
}
queue.queueCapacity

class UserQueue {
    int nItems, front, capacity;
    public int nUsers();
}
queue.capacity;
```

**Use active names for functions**\\
Tên của function nên sử dụng active verbs, có thể theo sau là nouns, ví dụ như là **getTime()**
Nếu hàm trả về true or false thì nên đặt tên như là **isOctal()** không phải **checkOctal()**.

**Be accurate**\\
Tên của hàm hoặc biến phải phản ánh đúng những gì chức năng của hàm và biến đó thể hiện.

**2. Expressions and Statements**

**Indent to show structure**\\
Việc dùng indentation một cách nhất quán là mức thấp nhất để chương trình trở lên có cấu trúc

**Use the natural form for expressions**\\
Sử dụng những expressions mà bạn có thể đọc chúng lớn được.

**Parenthesize to resolve ambiguity**\\
Các toán tử có thể có độ ưu tiên khác nhau nên việc sử dụng dấu ngoặc đơn sẽ tránh được sự nhập
nhằng trong biểu thức mà bạn không chắc chắn thứ tự thực hiện của các toán tử.

**Break up complex expressions**\\
Nếu một expressions chứa quá nhiều toán tử và phức tạp thì bạn nên chuyển thành những đoạn code
đơn giản hơn mặc dù nó sẽ không được ngắn gọn, nhưng sẽ cho người đọc đoạn code đó dễ hiểu hơn.

**Be clear**\\
Mục tiêu nên là viết code thật sáng sủa, dễ hiểu, chứ không phải viết code thể hiện mình là thông minh.

**Be careful with side effects**\\
Những toán tử như là ++, -- có side effect, bên cạnh trả về giá trị của biến còn thay đổi giá trị
của biến đó. Thứ tự của việc thay đổi giá trị của biến và giá trị trả về sẽ ảnh hưởng tới kết
quả của biểu thức.

**3. Consistency and Idioms**

**Use a consistent indentation and brace style**\\
Mỗi người sẽ có một thói quen sử dụng indentation và brace khác nhau, nhưng quan trọng hơn hết là
khi đã sử dụng thì phải sử dụng nó một cách nhất quán.

**Use idioms for consistency**\\
Để tạo được sự thống nhất trong cách viết code, chúng ta có thể sử dụng những đoạn code được
sử dụng phổ biến trong các tài liệu cũng như thực tế.

```C++
for (i = 0; i < n; i ++)
    array[i] = 1;

for (p = list; p != NULL; p = p->next) {}

for (;;) {} // prefer than while(1)

while ((c = getchar()) != EOF)
    putchar(c);

p = malloc(strlen(buf) + 1);
strcpy(p, buf);
```

**Use else-ifs for multi-way decisions**\\
Cách bạn thay đổi thứ tự trong các điều kiện của if-else có thể tạo đoạn code sáng sủa hơn.

**4 Function Macros**

Macros được sử dụng để tránh overhead của việc gọi tới các function, đây có thể là một lý do
để bạn có thể cân nhắc việc sử dụng Macros. Tuy nhiên với máy tính có hiệu năng thấp thì việc
gọi function có thể expensive, nhưng với khả năng của những máy tính hiện tại thì nó là không
cần thiết.

**Avoid function macros**\\
Việc sử dụng macros có thể dẫn tới những bug rất khó thấy ví dụ sau

```C++
#define isupper(c) ((c) >= 'A' && (c) <= 'Z')
while (isupper(c = getchar()))
```

Có thể thấy rằng c xuất hiện hai lần trong biểu thức của macro và việc gọi ở câu lệnh thứ hai
có thể dẫn tới việc biểu thức được chạy hai lần và gây ra side effect.

**Parenthesize the macro body and arguments**\\
Để tránh thứ tự ưu tiên trong biểu thức bị thay đổi khi sử dụng macros.

**5 Magic Numbers**

**Give name to magic numbers**\\
Việc sử dụng những số khác 0 hoặc 1 trong code sẽ làm cho người đọc khó hiểu, vì vậy
hãy sử dụng tên để gán cho những số đang sử dụng.

```C++
enum {
    MINROW = 1,
    MINCOL = 1,
    MAXROW = 24,
    MAXCOL = 80
}
```

**Define numbers as constants, not macros**\\
Trong lập trình C bạn thường sử dụng **#define** cho các magic numbers. Tuy nhiên nó là điều không
nên khi macros sẽ thay đổi lexical structure của chương trình, vì vậy nên sử dụng theo một cách phù
hợp hơn bằng hằng số.

**Use character constants, not integers**

```C++
if (c >= 65 && c <= 90) {} // should not
if (c >= 'A' && c <= 'Z') {}

name[i] = 0; // should not
name[i] = '\0';
```
****

**Use the language to calculate the size of an object**\\
Ví dụ nên sử dụng sizeof(int) thay vì 2 hoặc 3.

**6 Comments**

**Don't belabor the obvious**\\
Cách sử dụng tên hàm, tên biến và các vòng lặp có thể cho thấy được ý định của đoạn code bạn muốn viết.
Vì vậy không nên lạm dụng comments những đoạn code có thể hiểu được dễ dàng.

**Comment functions and global data**\\
Việc comment cho functions có thể giúp người đọc nhanh chóng biết được nhiệm vụ của function đó, giá trị trả về.
Comment cho global data sẽ giúp ta gợi nhớ lại mục đích của nó trong toàn bộ chương trình.

**Don't comment bad code, rewrite it**\\
Nếu phải comments mọi thứ thì đoạn code đó chắc chắn cần phải thay đổi.

**Don't contradict the code**\\
Tránh việc code và comments không thể hiện giống nhau. Hay xảy ra khi việc bạn thay đổi function đó và quên không
cập nhật comments trước đó.

**Clarify, don't confuse**\\
Comments là giúp người đọc dễ hiểu hơn cho đoạn code khó. Vì vậy tránh tạo thêm rào cản cho người đọc bằng những
comments có thể làm cho người đọc hiểu nhầm.

Tóm lại, nếu code được viết một cách sáng sủa, mạch lạc và có cấu trúc sẽ giúp bạn quản lý code tốt hơn và tránh
sai sót, trong khi đó cũng giúp người khác có thể hiểu code của bạn dễ dàng hơn. Đây có thể coi như là một thói
quen khi bạn viết code, vì vậy hãy tập cho mình có một thói quen tốt ngay từ bây giờ.