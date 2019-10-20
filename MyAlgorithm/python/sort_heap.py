def sort_heap(a):
    def heapify(i):
        largest = i
        if 2*i+1<l:
            if a[i]<a[2*i+1]:
                largest = 2*i+1
        if 2*i+2<l:
            if a[largest] < a[2*i+2]:
                largest = 2*i+2
        if largest != i:
            a[i],a[largest] = a[largest],a[i]
            heapify(largest)
    l = len(a)
    for i in range(l//2,-1,-1):
        heapify(i)
    for l in range(len(a)-1,-1,-1):
        a[0],a[l] = a[l],a[0]
        heapify(0)
b = [randint(1,15) for _ in range(100)]
sort_heap(b)
print(b)