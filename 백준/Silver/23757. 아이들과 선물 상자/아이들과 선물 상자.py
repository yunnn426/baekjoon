import sys, heapq
input = sys.stdin.readline

n, m = map(int, input().split())
c = list(map(int, input().split()))
c = [-x for x in c] # 최대 힙
w = list(map(int, input().split()))

heapq.heapify(c)

def sol():
    for i in range(m):
        want = w[i]
        biggest = heapq.heappop(c) * -1

        # 원하는게 선물 최대값보다 크면 실망
        if want > biggest:
            return 0
        
        # 가져갈 수 있다면 주고 그만큼 빼서 다시 힙에 추가
        biggest -= want
        heapq.heappush(c, biggest * -1)

    return 1

print(sol())