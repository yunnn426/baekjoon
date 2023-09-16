N = int(input())
size = []
rank = []

for i in range(N):  #입력순서, 몸무게, 키, 등수 순 저장
    size.append(list(map(int, input().split())))


for i in range(N):
    count = 1
    for j in range(N):
        if size[i][0] < size[j][0] and size[i][1] < size[j][1]:  #몸무게, 키 둘다 크면
            count += 1
    rank.append(count)

for i in range(N):
    print(rank[i], end=" ")
print()