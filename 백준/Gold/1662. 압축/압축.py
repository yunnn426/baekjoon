from collections import deque
import sys
input = sys.stdin.readline

s = input().rstrip()
n = len(s)
st = deque()

length = 0
tmp = 0
for i in range(n): 
    if s[i] == '(':
        st.append((length - 1, tmp)) # tmp가 k
        length = 0

    elif s[i] == ')':
        l, k = st.pop()
        length = l + (length * k)

    else:
        length += 1
        tmp = int(s[i])

print(length)