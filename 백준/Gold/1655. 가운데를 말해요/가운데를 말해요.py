import sys, heapq

n = int(sys.stdin.readline())

# maxheap, minheap 
# max->min 차례대로 수를 저장
# maxheap의 root는 항상 minheap의 root보다 작음
# maxheap의 root가 중앙값이 됨

maxheap = []
minheap = []
order = 0

def switch_root():
    if len(maxheap) != 0 and len(minheap) != 0:
        maxhtop = maxheap[0] * -1
        minhtop = minheap[0]
        if maxhtop > minhtop: # maxheap의 root가 minheap의 root보다 크면 교체
            heapq.heappop(maxheap)
            heapq.heappop(minheap)
            heapq.heappush(maxheap, -minhtop)
            heapq.heappush(minheap, maxhtop)

# main
for i in range(n):
    num = int(sys.stdin.readline())
    
    if order % 2 == 0: # maxheap 차례
        heapq.heappush(maxheap, -num)
        switch_root()
    
    else: # minheap 차례
        heapq.heappush(minheap, num)
        switch_root()

    order += 1
    
    print(-maxheap[0])