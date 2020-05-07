def bubble_sort(a):
    n = len(a)
    for i in range(n):
        exchange = False
        for j in range(n-1,i,-1):
            if a[j-1] > a[j]:
                a[j-1],a[j] = a[j],a[j-1]
                exchange = True
        if not exchange:
            return
        

if __name__ == "__main__":
    a = [8,9,5,6,1,2,4,0]
    bubble_sort(a)
    print(a)