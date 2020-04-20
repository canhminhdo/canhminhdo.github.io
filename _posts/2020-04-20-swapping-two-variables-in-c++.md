---
title: Swapping two variables in C++
date: 2020-04-20 14:58
category:
    - Programming
tags:
    - C++
    - Swapping
excerpt:
---
In this post, we consider about how to swap two variables in C++.
Assumption that we would like to swap two integer variables.

Let's look at the first **swap1** function below.
{% highlight c++ %}
void swap1(int a, int b) {
    int tmp = a;
    a = b;
    b = tmp;
}

int main() {
    int x = 3, y = 4;
    swap1(x, y);
    cout << "x = " << x << ", y = " << y << endl;   // x = 3, y = 34
}
{% endhighlight %}
Seem ok, but it does not work. Because **a** and **b** are local variables in the **swap1** function.
When you call **swap1(x, y)**, actually **x** will be copied to the **a** parameter, **y** also. Inside
the **swap1** function, **a** and **b** are exchanged but not given **x** and **y** variables.
**a** and **b** are discharged when finished **swap1** function.

Moving to the second **swap2** funtion below where reference variables are used as parameters.
{% highlight c++ %}
void swap2(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

int main() {
    int x = 3, y = 4;
    swap2(x, y);
    cout << "x = " << x << ", y = " << y << endl;   // x = 4, y = 3
}
{% endhighlight %}
It works well because of reference variables. When you call **swap2(x, y)** function.
Actually, we will have int &a = x, int &b = y. Now **a** and **b** are reference variables.
So **a** and **b** are attached to the **x** and **y** location in memory. You can access variables through
either **a**, **b** or **x**, **y**. When you change **a** and **b** value, in essence you are changing **x** and **y**.
References is good but it has some disavantagges:
* you cannot have NULL references. You must indicate that a reference is connected to a piece of memory.
* Once a reference is initialized to an object, it cannot change to refer to another object.
* A reference must be initialized when it is created.

From that points, using pointers in C++ may be flexiable and powerful.
Parameters of **swap3** function are two pointer variables of integer. When you call **swap3(&x, &y)**, we have int *a = &x, int *b = &y. Pointer variables **a**, **b** will point to **x**, **y**, respectively.
Actually, **a** and **b** store the address of **x** and **y** in memory. We can access the value pointed by **a** by operator ***a**.

{% highlight c++ %}
void swap3(int *a, int *b)
{
	int tmp = *a; // store value pointed by a
	*a = *b;    // change the value pointed by a by the value pointed by b
	*b = tmp;   // change the value pointed by b by tmp
}

int main() {
    int x = 3, y = 4;
    swap3(&x, &y);
    cout << "x = " << x << ", y = " << y << endl;   // x = 4, y = 3
}
{% endhighlight %}
