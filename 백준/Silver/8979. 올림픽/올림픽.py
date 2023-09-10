N, K = map(int, input().split())

score = [0 for i in range(N)] #나라별 점수 저장하는 배열
rank = [0 for i in range(N)] #나라별 등수 저장하는 배열

#gold: 3점, silver: 2점, bronze: 1점
for i in range(N):
    total = 0
    medal = list(map(int, input().split())) #N번째 나라, 금, 은, 동 순으로 저장
    total = 3 * medal[1] + 2 * medal[2] + 1 * medal[3] #나라 점수
    score[medal[0] - 1] = total


k_score = score[K - 1] #알고자 하는 나라의 점수
count = 1 #등수
#K 나라보다 점수가 높은 나라만큼 등수에 더함
for i in range(N):
    if score[i] > k_score: 
        count += 1

print(count)