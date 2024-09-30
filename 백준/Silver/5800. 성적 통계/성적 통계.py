import sys
input = sys.stdin.readline

k = int(input())
scores = [sorted(list(map(int, input().split()))[1:], reverse=True) for _ in range(k)]

def gap(arr):
    diff = 0
    for i in range(len(arr) - 1):
        diff = max(diff, arr[i] - arr[i + 1])

    return diff

for i in range(k):
    print('Class', i + 1)
    print('Max ', max(scores[i]), ', Min ', min(scores[i]), ', Largest gap ', gap(scores[i]), sep="")