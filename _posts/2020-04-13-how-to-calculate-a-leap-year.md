---
title: How to calculate a leap year
date: 2020-04-13 23:15
category:
    - Programming
tags:
    - C++
excerpt:
---
In this post, I show you how to calculate a leap year given a year.
Before, we dive into code to solve the problem.

What is a leap year?

A year has 29 days in February called a leap year. The 29th day is called the leap day.
Below is tricky to to differentiate a leap year.

> on every year that is evenly divisible by 4 <br/>
except every year that is evenly divisible by 100 unless <br/>
the year is also evenly divisible by 400

For example, 1997 is not a leap year, but 1996 is. 1900 is not a leap year, but 2000 is.

The following is the snippet code in C++ implemented the program to check a leap year.

{% highlight c++ %}
bool is_leap_year(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0 && year % 400 != 0) {
            return false;
        }
        return true;
    }
    return false;
}
{% endhighlight %}