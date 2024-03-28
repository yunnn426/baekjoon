# 쿼드트리
import sys

n = int(sys.stdin.readline())
video = [[0 for _ in range(n)] for _ in range(n)]
for i in range(n):
    row = sys.stdin.readline().strip()
    for j in range(n):  
        video[i][j] = int(row[j])

answer = ""
def quadtree(x, y, length):
    global answer
    
    if length == 1:
        answer += str(video[x][y])
        return
    
    newlen = length // 2
    cut = False
    first = video[x][y] # 해당 패치 첫 요소와 비교해서
    for i in range(x, x + length):
        if cut:
            break
        for j in range(y, y + length):
            if video[i][j] != first: # 다른 요소가 포함되면 
                # 재귀
                cut = True
                answer += "("
                quadtree(x, y, newlen)
                quadtree(x, y + newlen, newlen)
                quadtree(x + newlen, y, newlen)
                quadtree(x + newlen, y + newlen, newlen)
                answer += ")"
                break
    
    if not cut:
        answer += str(first)
        return
    
quadtree(0, 0, n)
print(answer)