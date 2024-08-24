n, m = map(int, input().split())
INF = int(1e9)
dist = [[INF] * (n + 1) for _ in range(n + 1)]

for _ in range(m):
    a, b = map(int, input().split())
    dist[a][b] = dist[b][a] = 1

for i in range(1, n + 1):
    dist[i][i] = 0

for k in range(1, n + 1):
    for i in range(1, n + 1):
        for j in range(1, n + 1):
            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])

answer = INF
a, b = 0, 0

for i in range(1, n):
    for j in range(i + 1, n + 1):
        total = sum(min(dist[i][k], dist[j][k]) for k in range(1, n + 1))
        if total < answer:
            a, b, answer = i, j, total

print(a, b, 2 * answer)