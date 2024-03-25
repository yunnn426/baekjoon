n = int(input())
lst = [0 for _ in range(n)]
for i in range(n):
    lst[i] = int(input())
srt = sorted(lst)
for i in srt:
    print(i)