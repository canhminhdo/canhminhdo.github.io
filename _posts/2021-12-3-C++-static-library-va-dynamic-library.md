---
title: C++ static library và dynamic library
date: 2021-12-03 15:20
category:
    - C++
---
Tôi có hội làm việc với C++ thông qua một dự án nhỏ cần phải thêm mới một vài
chức năng. Dự án đó sử dụng autotools để quản lý các configuration, make và
dependencies. Trong quá trình phát triển và build dự án để có thể chạy được trên
các máy khác nhau, tôi cần phải chọn cách build dự án thông qua static library
hay dynamic library.

**1. Quá trình build một chương trình C++**
Trong C/C++ để build một chương trình sẽ trải qua những bước như sau:

- Processor: source code sẽ được tiền xử lý như là xóa đi các comments,
expand những include từ headers files, repace các macros bạn định nghĩa
vào những chỗ bạn sử dụng trong source code.

- Complie: preprocessed code sẽ được complie về dạng assembly code, bạn
có thể đọc được những mã lệnh assembly code này nếu bạn đã từng lập trình
với assembly.

- Assembler: assembly code sẽ được chuyển về dạng mã máy để có thể chạy được
trên máy tính của bạn. Bạn có thể ogij đây là các object code.

- Linker: Các object code này sẽ được link với các dependencies hoặc có thể hiểu
là các library bạn sử dụng trong chương trình, bạn cần link vào thì chương trình
mới có thể chạy được, ngoài ra thì chương trình của bạn sẽ không hiểu nó là cái
gì, ngoài một interface được chứa trong file **.h**.

Khi build chương trình bạn có thể tùy chọn là sử dụng static library hay dynamic
library. Một một cái sẽ có pros và cons khác nhau.

**2. Static library (.a, .lib)**
Static library là tập hợp các object files được link cùng với trương trình khi
bạn build một file có thể chạy được. Vì vậy library code sẽ được link vào chương
trình trong quá trình complie time, vì vậy chương trình được build sẽ chứa nhiều
files và nặng hơn. Tuy nhiên tốc độ sẽ nhanh hơn vì bạn không phải mất thời gian
để load library trong khi run-time. Một điểm đặc biệt chú ý là khi bạn muốn thay
đổi static libraries bạn phải build lại toàn bộ chương trình.


**3. Dynamic library (.so, .dll, .dylib)**
Trái ngược với static library, dynamic library sẽ được link vào trong chương trình
trong khi run-time, vì vậy kích thước của chương trình được build ra sẽ nhỏ hơn và
đặc biệt là bạn không cần phải complie lại chương trình khi thay đổi version của các
library đó. Nhược điểm là sẽ làm chậm quá trình run time vì phải đợi để load những
dynamic library vào chương trình khi chạy.

Khi sử dụng dynamic library bạn cần chú ý biến environment **LD_LIBRARY_PATH** sẽ
được linker sử dụng để tìm kiếm các dynamic library.

**4. Một vài flags cần phải nắm khi build chương trình C++**
Chúng ta có thể overwrite những mặc định khi build chương trình với những flag như sau:

**CC** là C complider command.

**CFLAGS** là C complier flags.

**LDFLAGS*** là linker flags, e.g. -L<lib dir> nếu bạn có library không phải standard library
và nằm ở thư mục đâu đó.

**LIBS** libarary bạn muốn nói cho linkers biết, e.g. -l<library>. Trong trường hợp sử dụng
static library, bạn nên chỉ đến đúng đường dẫn của libary đó, e.g. /path/to/libary.a

**CPPFLAGS** là C/C++ preprocessor flags, e.g -I<include dir> nếu bạn sử dụng headers file
của nhưng nonstandard libary nằm ở thư mục đâu đó.

**CXX** là C++ complier command.

**CXXFLAGS** là C++ complier flags.

Dưới đây là câu lệnh mình sử dụng để configure cho dự án của mình trước khi complie bằng
câu lệnh make.

```
../configure \
--with-yices2=yes \
--with-cvc4=no \
FLEX=/opt/local/bin/flex \
BISON=/usr/local/bin/bison \
CFLAGS="-g -Wall -O3 -fno-stack-protector -fstrict-aliasing" \
CXXFLAGS="-g -Wall -O3 -fno-stack-protector -fstrict-aliasing -std=c++11" \
CPPFLAGS="-I/Users/Darwin64/include" \
LDFLAGS="-L/Users/Darwin64/lib" \
LIBSIGSEGV_LIB="/Users/Darwin64/lib/libsigsegv.a" \
BUDDY_LIB="/Users/Darwin64/lib/libbdd.a" \
YICES2_LIB="/Users/Darwin64/lib/libyices.a" \
TECLA_LIBS="/Users/Darwin64/lib/libtecla.a /Users/Darwin64/lib/libtecla_r.a -lcurses" \
GMP_LIBS="/Users/Darwin64/lib/libgmpxx.a /Users/Darwin64/lib/libgmp.a" \
--prefix="${CWD}/dist"
```
