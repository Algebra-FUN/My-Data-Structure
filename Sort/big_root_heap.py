def bh_sift(a, i, sup):
    j = 2*i
    if j > sup:
        return
    if j < sup and a[j+1] > a[j]:
        j += 1
    if a[j] > a[i]:
        a[i], a[j] = a[j], a[i]
        bh_sift(a, j, sup)

def big_heap_sort(a):
    n = len(a)
    a.insert(0, None)
    for i in range(n//2, 0, -1):
        bh_sift(a, i, n)
    for i in range(n, 1, -1):
        a[1], a[i] = a[i], a[1]
        bh_sift(a, 1, i-1)
    a.pop(0)


if __name__ == "__main__":
    a = [6, 8, 7, 9, 0, 1, 3, 2, 4, 5]
    big_heap_sort(a)
    print(a)
