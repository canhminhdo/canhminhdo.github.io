---
title: Những lưu ý khi viết code để chương trình trở lên sáng sủa và mạch lạc
date: 2021-03-11 22:40
category:
    - code style
---
Việc viết code không những để cho máy tính đọc mà cũng cho lập trình viên đọc code của bạn.
Chính vì vậy việc viết code một cách có cấu trúc, dễ đọc không những giúp bạn có thể quản lý
mã nguồn và lỗi tốt mà còn dễ dàng sửa đổi. Sau đây chúng ta cùng xem một vài lưu ý khi viết
chương của mình

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

Updating ...