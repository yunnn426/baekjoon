N, K = map(int, input().split())

score = [0 for i in range(N)] #나라별 점수 저장하는 배열
rank = [0 for i in range(N)] #나라별 등수 저장하는 배열

#gold: 3점, silver: 2점, bronze: 1점
for i in range(N):
    total = 0
    medal = list(map(int, input().split())) #N번째 나라, 금, 은, 동 순으로 저장
    total = 3 * medal[1] + 2 * medal[2] + 1 * medal[3] #나라 점수
    score[medal[0] - 1] = total

rank_tmp = 1 #등수
count = 0 #몇번째 score인지 추적용
while(max(score) != 0):
    max_arr = [] #최대 점수들의 인덱스 저장
    max_score = max(score)

    #현재 score 배열에서 가장 큰 점수를 가진 나라의 인덱스를 저장
    for i in range(len(score)):
        if max_score == score[i]:
            max_arr.append(i)
    
    #그 나라들에게 등수 부여
    for i in range(len(max_arr)):
        rank[max_arr[i]] = rank_tmp

    #등수 계산 완료한 나라는 score 배열에서 제거
    for i in range(len(max_arr)):
        score[max_arr[i]] = 0
        rank_tmp += 1
    
    count += 1

print(rank[K - 1])