from collections import deque
import sys
input = sys.stdin.readline

n = int(input())
height = [int(input()) for _ in range(n)]
sum = 0
st = deque()
st.append((height[n - 1], 0))
for i in range(n - 2, -1, -1):
    now = height[i]
    # print(st, now)
    count = 0
    while True:
        if len(st) == 0: break
        h, cnt = st.pop()
        if h >= now:
            st.append((h, cnt))
            break
        count += 1 + cnt
    
    sum += count
    st.append((now, count))

print(sum)
