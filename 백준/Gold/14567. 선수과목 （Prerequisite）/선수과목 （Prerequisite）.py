import sys
input = sys.stdin.readline

n, m = map(int, input().split())
prereq = [[] for _ in range(n + 1)]
for _ in range(m):
    a, b = map(int, input().split())
    prereq[b].append(a) # a -> b
topology = [1 for _ in range(n + 1)]

for i in range(2, n + 1):
    for j in prereq[i]:
        topology[i] = max(topology[i], topology[j] + 1)

print(*topology[1:])