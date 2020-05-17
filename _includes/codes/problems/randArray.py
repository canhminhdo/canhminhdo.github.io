import random

arr = [1, 2, 3, 4]
def shuffle(arr):
    for i in range(len(arr), 0, -1):
        j = random.randint(0, i - 1)
        tmp = arr[i - 1]
        arr[i - 1] = arr[j]
        arr[j] = tmp
    return arr

print(shuffle(arr))