def Min(array):
    if len(array) is 1:
        return array[0]
    v = array.pop()
    mins = Min(array)
    return v if v < mins else mins


print(Min([1, 2, 4, -1, 3, 5, -2, 6, 7]))


def Max(array):
    length = len(array)
    if length is 1:
        return array[0]
    i = length//2
    max1 = Max(array[:i])
    max2 = Max(array[i:])
    return max1 if max1 > max2 else max2


print(Max([1, 2, 4, -1, 3, 5, -2, 6, 7]))