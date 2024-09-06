import sys
input = sys.stdin.readline

n = int(input())
arr = []

# n -> 한 자리씩 배열에
while True:
    i = n % 10
    if i == 0 and n == 0:
        break
    arr.append(i)
    n //= 10

# 1. 버블정렬
def bubble(n):
    for i in range(n):
        for j in range(i + 1, n):
            if arr[i] < arr[j]:
                arr[i], arr[j] = arr[j], arr[i]

# 2. 삽입 정렬
def insertion(n):
    for i in range(1, n):
        key = arr[i]
        idx = i - 1
        while idx >= 0 and arr[idx] < key:
            arr[idx + 1] = arr[idx]
            idx -= 1
        arr[idx + 1] = key

# 3. 선택 정렬
def selection(n):
    for i in range(n):
        idx = i
        for j in range(i + 1, n):
            if arr[j] > arr[idx]:
                idx = j
        arr[i], arr[idx] = arr[idx], arr[i]

# 4. 병합 정렬
## 합병
def merge(left, right):
    i, j = 0, 0
    sorted_arr = []

    while i < len(left) and j < len(right):
        if left[i] > right[j]:
            sorted_arr.append(left[i])
            i += 1
        elif left[i] < right[j]:
            sorted_arr.append(right[j])
            j += 1
        
    if i < len(left):
        sorted_arr.extend(left[i:])
    if j < len(right):
        sorted_arr.extend(right[j:])
    
    return sorted_arr

## 분할
def merge_sort(arr):
    n = len(arr)
    if n <= 1:
        return arr
    
    mid = n // 2
    left = arr[:mid]
    right = arr[mid:]

    return merge(merge_sort(left), merge_sort(right))

# 5. 퀵 정렬
def quick(arr):
    if len(arr) <= 1:
        return arr
    
    pivot = arr[len(arr) // 2]
    left = [x for x in arr if x < pivot]
    mid = [x for x in arr if x == pivot]
    right = [x for x in arr if x > pivot]

    return quick(right) + mid + quick(left)

# 6. 힙 정렬
## 최소 힙 생성
def heapify(arr, i, n):
    smallest = i
    left = i * 2 + 1
    right = i * 2 + 2

    if left < n and arr[left] < arr[smallest]:
        smallest = left
    if right < n and arr[right] < arr[smallest]:
        smallest = right
    
    if smallest != i:
        arr[i], arr[smallest] = arr[smallest], arr[i]
        heapify(arr, smallest, n) # 밀려 내려온 트리부터 다시 힙 정렬
    
def heap(n):
    for i in range(n // 2, -1, -1):
        heapify(arr, i, n)
    
    for i in range(n - 1, 0, -1):
        arr[0], arr[i] = arr[i], arr[0] 
        heapify(arr, 0, i) 

cnt = len(arr)

# bubble(cnt)
# insertion(cnt)
# selection(cnt)
# sorted_arr = merge_sort(arr)
# sorted_arr = quick(arr)

heap(cnt) 
print(*arr, sep="")
# print(*sorted_arr, sep="")