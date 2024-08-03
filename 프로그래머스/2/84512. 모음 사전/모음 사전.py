import sys
sys.setrecursionlimit(10000)

letters = ['A', 'E', 'I', 'O', 'U']

answer = 0
count = 0
def dfs(start, word):
    global answer, count
    
    # 종료 조건
    if start == word:
        answer = count
        return 
    
    if len(start) < 5:
        for l in letters:
            count += 1
            dfs(start + l, word)

def solution(word):
    dfs('', word)       
    global answer
    
    return answer