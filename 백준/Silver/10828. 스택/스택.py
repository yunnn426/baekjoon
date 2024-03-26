import sys


n = int(sys.stdin.readline())

lst = []
for _ in range(n):
    cmd = sys.stdin.readline().strip()
    num = 0
    for i in range(len(cmd)):
        if cmd[i] == ' ':
            num = cmd[i + 1:]
            num = int(num)
            cmd = cmd[:i]
            break

    ans = 0
    if cmd == "push":
        lst.append(num)

    elif cmd == "pop":
        if len(lst) != 0: 
            ans = lst[-1]
            lst.pop()
        else: # 스택이 비어있는 경우
            ans = -1
        print(ans)

    elif cmd == "size":
        ans = len(lst)
        print(ans)

    elif cmd == "empty":
        if len(lst) == 0:
            ans = 1
        else:
            ans = 0
        print(ans)

    elif cmd == "top":
        if len(lst) != 0:
            ans = lst[-1]
        else:
            ans = -1
        print(ans)
    