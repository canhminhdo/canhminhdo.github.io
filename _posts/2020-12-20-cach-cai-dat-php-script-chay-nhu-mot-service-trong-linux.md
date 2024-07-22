---
layout: post
title: Cách cài đặt PHP script chạy như một service trong Linux
redirect_from:
    - /cach-cai-dat-php-script-chay-nhu-mot-service-trong-linux
date: 2020-12-20 11:22
category:
    - Deployment
tags: 
    - Linux
    - PHP
---
Trước khi hướng dẫn deploy một PHP script chạy như một service trong Linux.
Chúng ta cùng tìm hiểu tại sao chúng ta cần phải làm như vậy thay vì sử dụng `crontab`, `screen`.

Việc chạy PHP script như một service trong Linux, thực chất là viết một đoạn bash script để chạy chương trình của bạn với `nohup`, sẽ có một vài ưu điểm bạn có thể cân nhắc:
- `nohup` được sử dụng cho tiến trình ngầm khi tiến trình đó không sử dụng đầu vào từ user chẳng hạn như những batch job.
- `nohub` sẽ chạy trên một tiến trình độc lập, bạn có thể dễ dàng `start`, `stop`, `status` và `restart`
- Tránh những trường hợp không may ấn tổ hợp phím để dừng một tiến trình trong `screen` như `Ctrl' + `C`
- Thông tin log sẽ được viết xuống một file được chỉ định, dễ dàng cho việc kiểm tra lỗi.
- Hoạt động hiệu quả và tốn ít bộ nhớ.

Dưới đây là cách deploy một PHP script chạy như một service trong Linux.
Bạn cần có quyền của root để có thể làm điều này.
1. Đầu tiên bạn tạo một file dưới thư mục **/etc/init.d** bằng trình soạn thảo bạn quen thuộc như vi hoặc emacs. Ví dụ mình tạo một file là **import_test_case** thì sẽ tạo như sau **vi /etc/init.d/import_test_case**.

2. Thay đổi một vài thông tin trong file bash script ở bên dưới. Như là SERVICE_NAME, PATH_TO_PROJECT, PATH_TO_LOG, COMMAND để script biết được tên của service, vị trí của dự án, vị trí để viết file log, command sẽ thực hiện.

3. Cho phép file bạn vừa tạo có thể chạy bằng lệnh **sudo chmod +x /etc/init.d/import_test_case**

4. Một vài lệnh bạn có thể kiểm tra với service mới bạn định sử dụng

- chạy service bằng lệnh **service import_test_case start**
- dừng service bằng lệnh **service import_test_case stop**
- khởi động lại service bằng lệnh **service import_test_case restart**
- kiểm tra trạng thái của service bằng lệnh **service import_test_case status**

{% highlight bash %}
#!/bin/sh
SERVICE_NAME=import_test_case_dev
WORKER_ID=$2
PROJECT_NAME=dev.manage-test.com
PATH_TO_PROJECT="/var/www/html/${PROJECT_NAME}"
PATH_TO_CONSOLE="${PATH_TO_PROJECT}/lib/Cake/Console"
PATH_TO_LOG="/home/mtest/rabbitmq/${SERVICE_NAME}_worker${WORKER_ID}.log"
PID_PATH_NAME="/home/mtest/rabbitmq/${SERVICE_NAME}_worker${WORKER_ID}_pid"
COMMAND="php -q ${PATH_TO_CONSOLE}/cake.php -working ${PATH_TO_PROJECT} ImportTestCase"

case $1 in
    start)
        echo "Starting $SERVICE_NAME ..."
        if [ ! -f $PID_PATH_NAME ]; then
            cd $PATH_TO_PROJECT && nohup $COMMAND >> $PATH_TO_LOG 2>&1 &
            echo $! > $PID_PATH_NAME
            echo "$SERVICE_NAME started ..."
        else
            echo "$SERVICE_NAME is already running ..."
        fi
    ;;
    status)
        if [ -f $PID_PATH_NAME ]; then
            PID=$(cat $PID_PATH_NAME);
            echo "$SERVICE_NAME is running at $PID ..."
        else
            echo "$SERVICE_NAME is not running ..."
        fi
    ;;
    stop)
        if [ -f $PID_PATH_NAME ]; then
            PID=$(cat $PID_PATH_NAME);
            echo "$SERVICE_NAME stoping ..."
            pkill -P $PID && kill $PID;
            echo "$SERVICE_NAME stopped ..."
            rm $PID_PATH_NAME
        else
            echo "$SERVICE_NAME is not running ..."
        fi
    ;;
    restart)
        if [ -f $PID_PATH_NAME ]; then
            PID=$(cat $PID_PATH_NAME);
            echo "$SERVICE_NAME stopping ...";
            pkill -P $PID && kill $PID;
            echo "$SERVICE_NAME stopped ...";
            rm $PID_PATH_NAME
            echo "$SERVICE_NAME starting ..."
            cd $PATH_TO_PROJECT && nohup $COMMAND >> $PATH_TO_LOG 2>&1 &
            echo $! > $PID_PATH_NAME
            echo "$SERVICE_NAME started ..."
        else
            echo "$SERVICE_NAME is not running ..."
        fi
    ;;
esac
{% endhighlight %}
