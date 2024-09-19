import sys, heapq
input = sys.stdin.readline

n, m = map(int, input().split())
a = list(map(int, input().split()))

# 우선순위 큐
heapq.heapify(a)
for i in range(m):
    num1 = heapq.heappop(a)
    num2 = heapq.heappop(a)

    heapq.heappush(a, num1 + num2)
    heapq.heappush(a, num1 + num2)

print(sum(a))