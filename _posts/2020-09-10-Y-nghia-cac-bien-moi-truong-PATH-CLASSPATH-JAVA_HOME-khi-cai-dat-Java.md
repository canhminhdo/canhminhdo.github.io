---
layout: post
title: Ý nghĩa các biến môi trường PATH, CLASSPATH và JAVA_HOME khi cài đặt và sử dụng Java
redirect_from:
    - /Y-nghia-cac-bien-moi-truong-PATH-CLASSPATH-JAVA_HOME-khi-cai-dat-Java/
date: 2020-09-10 11:53
category:
    - Java Configuration
tags: 
    - Java
---
Khi bạn cài đặt và sử dụng Java trong các dự án của mình, có 3 biến môi trường quan trọng cần phải lưu ý là **PATH**, **CLASSPATH** và **JAVA_HOME**. Ý nghĩa của mỗi biến môi trường phục vụ những mục đích khác nhau.

**JAVA_HOME** là biến môi trường chỉ tới thư mục bạn cài đặt JDK, nhiều ứng dụng viết bằng Java yêu cầu sử dụng biến **JAVA_HOME** này để biết được nơi cài đặt của Java, ví dụ như Apache Tomcat.

{% highlight pseudocode %}
--- for csh shell
setenv JAVA_HOME /work/$USER/ogatalab/Applications/Java/jdk1.8.0_261
{% endhighlight %}

**PATH** là biến môi trường cho bạn có thể sử dụng những câu lệnh của Java ở bất kỳ đâu, như là **java**, **javac**. Thường sẽ được trỏ tới thư mục bin nằm dưới thư mục cài đặt của jdk.

{% highlight pseudocode %}
--- for csh shell
setenv PATH $JAVA_HOME/bin:$PATH
{% endhighlight %}

**CLASSPATH** là biến môi trường cho phép Java Runtime Environment (JRE) tìm kiếm các classes files và những tài nguyên khác như **jar**, **zip** files để chạy chương trình. Ngoài ra bạn có thể sử dụng **wild cards (*)** để chỉ định tất cả các **jar** files trong một thư mục sẽ được tìm kiếm.
Ví dụ như `mydir/*`, chương trình java sẽ tìm kiếm được tất cả các **jar** files có trong thư mục **mydir**.

{% highlight pseudocode %}
--- for csh shell
setenv CLASSPATH "/work/$USER/ogatalab/Applications/jpf-core/build/*":/work/$USER/ogatalab/Applications/jpf-core/build/annotations:/work/$USER/ogatalab/Applications/jpf-core/build/classes:/work/$USER/ogatalab/Applications/jpf-core/build/main:/work/$USER/ogatalab/Applications/jpf-core/build/peers
{% endhighlight %}

**Chú ý:** Khi sử dụng **java** command line, nếu bạn sử dụng **-classpath** hoặc **-cp** thì classpath mới sẽ được sử dụng thay vì **CLASSPATH**.

Ngoài ra bạn có thể tham khảo thêm về biến môi trường **JRE_HOME**, có thể được yêu cầu từ những ứng dụng Java khác.