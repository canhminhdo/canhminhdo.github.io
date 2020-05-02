arr = [10, 15, 3, 7]
k = 17
dict = {}
for i in range(len(arr)):
    remaining = k - arr[i]
    if remaining in dict:
        print("1st index {}, value {}".format(i, arr[i]))
        print("2nd index {}, value {}".format(dict[remaining], remaining))
        break;  # if you only want to find the 1st solution but not all.
    else:
        dict[arr[i]] = i