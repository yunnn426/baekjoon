import sys

n = int(sys.stdin.readline())
paper = []
white = 0
blue = 0

def cut(x, y, length):
    if length == 0:
        return
    
    cuttable = False
    color = paper[x][y]
    for i in range(length):
        for j in range(length):
            if paper[x + i][y + j] != color:
                cuttable = True
                
    # 더 이상 자를 수 없음
    # 한 색으로만 칠해져 있음
    if cuttable == False:
        if color == 0:
            global white
            white += 1
        else:
            global blue
            blue += 1
    
    # 잘라야함
    else:
        newlen = length // 2
        cut(x, y, newlen)
        cut(x + newlen, y, newlen)
        cut(x, y + newlen, newlen)
        cut(x + newlen, y + newlen, newlen)

for i in range(n):
    arr = list(map(int, sys.stdin.readline().split()))
    paper.append(arr)

cut(0, 0, n)
print(white, blue, sep="\n")