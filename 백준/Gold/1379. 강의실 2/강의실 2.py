# 강의실 2
import sys, heapq
input = sys.stdin.readline

n = int(input())
lecture = []
for _ in range(n):
    num, s, e = map(int, input().split())
    lecture.append((s, e, num)) # 시작-끝-강의번호 순

lecture.sort() # 시작하는 시간 기준 정렬

place = []
idx = 1
hq = []
firsts, firste, firstn = lecture[0]
# 강의실 우선순위큐는 끝나는 시간 기준 정렬
heapq.heappush(hq, (firste, 1))
place.append((firstn, 1))
lecture.pop(0)

for l in lecture:
    s, e, num = l

    if hq[0][0] > s: # 강의의 시작시간이 큐에서 꺼내온 강의실의 종료시간보다 늦으면 새로운 강의실 필요
        idx += 1
        heapq.heappush(hq, (e, idx)) # 새로운 강의실 만들기
        place.append((num, idx)) # 강의번호-강의실

    else: # 해당 강의실을 이용 가능하면 강의실 시작,종료 시간을 해당 강의로 바꿔줌
        pe, pnum = heapq.heappop(hq)
        heapq.heappush(hq, (e, pnum))
        place.append((num, pnum)) # 강의번호-강의실

print(idx)
place.sort()
for p in place:
    num, pla = p
    print(pla)