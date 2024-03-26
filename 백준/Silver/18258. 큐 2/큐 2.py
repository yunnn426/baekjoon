import sys
from collections import deque

n = int(sys.stdin.readline().strip())
lst = deque()

for _ in range(n):
    cmd = sys.stdin.readline().strip()
    x = 0
    for i in range(len(cmd)):
        if cmd[i] == ' ': # push
            x = cmd[i + 1:]
            x = int(x)
            cmd = cmd[:i]
            break
    
    if cmd == "push":
        lst.append(x)
    
    elif cmd == "pop":
        if len(lst) == 0:
            print(-1)
        else:
            print(lst.popleft())

    elif cmd == "size":
        print(len(lst))
    
    elif cmd == "empty":
        if len(lst) == 0:
            print(1)
        else:
            print(0)
    
    elif cmd == "front":
        if len(lst) == 0:
            print(-1)
        else:
            print(lst[0])
    
    elif cmd == "back":
        if len(lst) == 0:
            print(-1)
        else:
            print(lst[-1])