#!/usr/bin/env python
# coding: utf-8

# In[1]:


# problem 1: find an element in a sorted list
arr = list(range(10))
def binarySearch(arr, X):
    L, R = 0, len(arr) - 1
    while L <= R:
        mid = L + int((R - L) / 2)
        if arr[mid] == X:
            return mid
        if arr[mid] < X:
            L = mid + 1
        else:
            R = mid - 1
    return -1

print(arr)
print(binarySearch(arr, 5))


# In[2]:


# problem 2: find first element >= X in a sorted list
arr = [2, 3, 5, 6, 8, 12]
def findElement(arr, X):
    L, R = 0, len(arr) - 1
    ans = -1
    while L <= R:
        mid = L + int((R - L) / 2)
        if arr[mid] == X:
            return X
        if arr[mid] > X:
            ans = arr[mid]
            R = mid - 1
        else:
            L = mid + 1
    return ans

print(arr)
print(findElement(arr, 10))


# In[3]:


# problem 3: somebody roated a sorted list, find the smallest element
arr = [6, 7, 9, 15, 19, 2, 3]
def findSmallest(arr):
    L, R = 0, len(arr) - 1
    while L <= R:
        mid = L + int((R - L) / 2)
        if arr[L] < arr[R]:
            return arr[L]
        else:
            L = mid
print(findSmallest(arr))


# In[4]:


# problem 4: increase and decrease list, find the maximum element
arr = [2, 3, 4, 6, 9, 12, 11, 8, 6, 4, 1]
def findMaximum(arr):
    L, R = 0, len(arr) - 1
    ans = -1
    while L <= R:
        mid = L + int((R - L) / 2)
        if arr[mid] > arr[mid - 1]:
            ans = arr[mid]
            L = mid + 1
        else:
            R = mid - 1
    return ans
print(findMaximum(arr))


# In[8]:


# problem 3: calculate sqrx(x) with some precision
L , R , X, esp = 0, 2, 2, 1e-9
while (R - L > esp):
    mid = L + (R - L) / 2
    if mid * mid < X:
        L = mid
    else:
        R = mid
L, R


# In[9]:


import math
math.sqrt(2)

