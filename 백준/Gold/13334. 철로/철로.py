import sys, heapq

n = int(sys.stdin.readline())
people = []
for _ in range(n):
    a, b = map(int, sys.stdin.readline().split())
    if a > b: a, b = b, a
    people.append([a, b])
d = int(sys.stdin.readline())

people.sort(key=lambda x: (x[1], x[0])) # 끝점 기준 오름차순 정렬
heap = []
answer = 0
for p in people:
    heapq.heappush(heap, p[0])

    while len(heap) != 0:
        if p[1] - heap[0] <= d:
            break
        heapq.heappop(heap)
    answer = max(len(heap), answer)
    
print(answer)
