import sys
n, k = map(int, sys.stdin.readline().split())

q = [i for i in range(1, n + 1)]
answer = []

idx = 1
while (len(q) != 0):
    front = q.pop(0)
    if idx != k:
        q.append(front)
    else:
        answer.append(front)
        idx = 0
    idx += 1

print("<", end="")
for i in answer:
    print(i, end="")
    if i != answer[-1]:
        print(", ", end="")
print(">")