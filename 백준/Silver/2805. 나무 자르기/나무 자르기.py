import sys
n, m = map(int, sys.stdin.readline().split())
tree = list(map(int, sys.stdin.readline().split()))

start = 0
end = 1000000000

while start <= end:
    mid = (start + end) // 2

    sum = 0
    for t in tree:
        cut = t - mid
        if cut >= 0:
            sum += cut

    if sum >= m:
        start = mid + 1
        
    else:
        end = mid - 1
    
print(end)